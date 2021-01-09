#include "State/InitState.h"

#include <cstdio>

#include "Agents/DynamoDBAgent.h"

#include "Tools/pugixml/pugixml.hpp"

#include "Pieces/Pieces.h"
#include "Pieces/NullPiece.h"
#include "Pieces/Rook.h"
#include "Pieces/Knight.h"
#include "Pieces/Bishop.h"
#include "Pieces/Queen.h"
#include "Pieces/King.h"
#include "Pieces/WhitePawn.h"
#include "Pieces/BlackPawn.h"


namespace Chess
{
  namespace State
  {

    void deserializeGameInfo( GameState& gameState )
    {
      Chess::Agents::DynamoDBAgent db("GameStates", "localhost", "http://localhost:8000");
      auto info = db.getItem("gameId", gameState.gameId);

      auto whiteId = info.find("whiteId");
      auto blackId = info.find("blackId");
      auto state   = info.find("state");
      if( whiteId == info.end() || blackId == info.end() || state == info.end() ) throw string("DynamoDB game info missing field(s)");

      gameState.whiteClientId = whiteId->second.GetS();
      gameState.blackClientId = blackId->second.GetS();
      gameState.gameStateString = state->second.GetS();
      writeToFile(FilePaths::gameStateFile, gameState.gameStateString);
    }

    void deserializeClientRequest( GameState& gameState )
    {
      // Setup the xml document structure and load the state initialization file
      pugi::xml_document doc;
      pugi::xml_parse_result result = doc.load_file(FilePaths::userInputFile.c_str());
      pugi::xml_node request = doc.child("request");

      gameState.gameId          = request.attribute("gameId").value();
      gameState.currentClientId = request.attribute("clientId").value();
      string moveString         = request.attribute("move").value();
      gameState.moveString      = moveString;
      gameState.setMoveRequest(moveString);
    }

    BaseState::StatePtr InitState::execute()
    {
      DEBUG_CONSOLE_1ARG("State: INIT");

      deserializeClientRequest(gameState_);
      deserializeGameInfo(gameState_);
      deserializeGameStateFile();

      return nextState_;
    }

    void InitState::deserializeGameStateFile()
    {
      // Setup the xml document structure and load the state initialization file
      pugi::xml_document doc;
      pugi::xml_parse_result result = doc.load_file(FilePaths::gameStateFile.c_str());

      // Grab the root node
      pugi::xml_node root      = doc.child("root");
      pugi::xml_node boardNode = root.child("Board");

      // Iterate through all of the children of the board node (each square/piece)
      int pieceId = 0;
      for( pugi::xml_node_iterator i = boardNode.begin(); i != boardNode.end(); ++i, ++pieceId )
      {
        string type   = i->attribute("type").value();
        string color  = i->attribute("color").value();
        int    row    = i->attribute("row").as_int();
        int    col    = i->attribute("col").as_int();
        string symbol = i->attribute("symbol").value();

        // Create pieces on the heap based on the configuration
        // read from the xml file
        InitState::PiecePtr p;
        if( type == "P" )
        {
          if( color == "W" )
            p.reset( new Chess::WhitePawn(symbol) );
          else
            p.reset( new Chess::BlackPawn(symbol) );
        }
        else if( type == "B" )
        {
          p.reset( new Chess::Bishop(symbol, gameState_.board) );
        }
        else if( type == "R" )
        {
          p.reset( new Chess::Rook(symbol, gameState_.board) );
        }
        else if( type == "KN" )
        {
          p.reset( new Chess::Knight(symbol) );
        }
        else if( type == "Q" )
        {
          p.reset( new Chess::Queen(symbol, gameState_.board) );
        }
        else if( type == "K" )
        {
          p.reset( new Chess::King(symbol, gameState_.board) );
          if( color == "W" ) gameState_.whiteKingId = pieceId;
          else gameState_.blackKingId = pieceId;
        }

        // Don't bother setting Null Pieces - every square is initialized
        // with a Null Piece set for it.
        if( type != "" )
        {
          p->setId(pieceId);
          setPiece(p,row,col);
        }
      }

      // Set which team is initially starting the game based on the
      // config file.
      pugi::xml_node turnNode = root.child("Turn");
      gameState_.setAttacker(turnNode.attribute("color").value());
      pugi::xml_node messagesNode = root.child("Messages");

      // Reset the messages for now. This move attempt has a clean slate and will
      // be evaluated for any possible crimes...
      messagesNode.attribute("invalidMove").set_value("");
      root.remove_child(boardNode);
      doc.save_file(FilePaths::gameStateFile.c_str());
    }

    void InitState::setPiece( PiecePtr pieceToSet, int rowToSet, int colToSet )
    {
      if(pieceToSet)
      {
        pieceToSet->setLocation(rowToSet, colToSet);
        gameState_.board.setPiece(pieceToSet, rowToSet, colToSet);
        gameState_.activePieces.insert({pieceToSet->getId(), pieceToSet});
      }
    }

  }
}
