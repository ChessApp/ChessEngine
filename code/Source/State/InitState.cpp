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

    void writeToFile( const char * filePath, string content )
    {
      ofstream outFile(filePath);
      outFile << content;
      outFile.close();
    }

    void parseGameInfo( GameState& gameState )
    {
      Chess::Agents::DynamoDBAgent db("GameStates", "localhost", "http://localhost:8000");
      auto info = db.getItem("gameId", gameState.gameId);

      auto whiteId = info.find("whiteId");
      auto blackId = info.find("blackId");
      auto state   = info.find("state");
      if( whiteId == info.end() || blackId == info.end() || state == info.end() ) throw "DynamoDB game info missing field(s)";

      gameState.whiteClientId = whiteId->second.GetS();
      gameState.blackClientId = blackId->second.GetS();
      writeToFile(FilePaths::gameStateFile, state->second.GetS());
    }

    void parseClientRequest( GameState& gameState )
    {
      // Setup the xml document structure and load the state initialization file
      pugi::xml_document doc;
      pugi::xml_parse_result result = doc.load_file(FilePaths::userInputFile);
      pugi::xml_node request = doc.child("request");

      gameState.gameId          = request.attribute("gameId").value();
      gameState.currentClientId = request.attribute("clientId").value();
      string moveString         = request.attribute("move").value();
      gameState.moveString      = moveString;
      gameState.setMoveRequest(moveString);
    }

    BaseState::StatePtr InitState::execute( )
    {
      DEBUG_CONSOLE_1ARG("State: INIT");

      parseClientRequest(gameState_);
      parseGameInfo(gameState_);
      parseInitialStateFile();

      gameState_.print();

      return nextState_;
    }

    void InitState::parseInitialStateFile()
    {
      // Setup the xml document structure and load the state initialization file
      pugi::xml_document doc;
      pugi::xml_parse_result result = doc.load_file(FilePaths::gameStateFile);

      // Grab the root node
      pugi::xml_node root      = doc.child("root");
      pugi::xml_node boardNode = root.child("Board");

      for( int j = 0; j < 8; j++ )
      {
        for( int i = 0; i < 8; i++ )
        {
          PiecePtr np( new NullPiece(".. ") );
          gameState_.board.setPiece(np, j, i);
        }  
      }

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
        PiecePtr p;
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

      cout << "5" << endl;
      // Set which team is initially starting the game based on the
      // config file.
      pugi::xml_node turnNode = root.child("Turn");
      gameState_.setAttacker(turnNode.attribute("color").value());
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

    void InitState::initializeGameStateFile()
    {
      // Setup the xml document structure and load the state initialization file
      pugi::xml_document doc;
      pugi::xml_parse_result result = doc.load_file(FilePaths::gameStateFile);

      // Grab the root node
      pugi::xml_node root = doc.child("root");

      pugi::xml_node flagsNode    = root.child("Flags");
      pugi::xml_node messagesNode = root.child("Messages");
      pugi::xml_node turnNode     = root.child("Turn");
      pugi::xml_node winnerNode   = root.child("Winner");


      flagsNode.attribute("invalidMove").set_value(0);
      messagesNode.attribute("invalidMove").set_value("");
      turnNode.attribute("checkStatus").set_value(0);
      winnerNode.attribute("status").set_value(0);
      winnerNode.attribute("color").set_value("");

      doc.save_file(FilePaths::gameStateFile);
    }

  }
}
