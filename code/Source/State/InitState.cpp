#include "State/InitState.h"

#include <cstdio>

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

    BaseState::StatePtr InitState::execute( )
    {
      DEBUG_CONSOLE_1ARG("State: INIT");

      

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

      // Iterate through all of the children of the board node (each square/piece)
      for( pugi::xml_node_iterator i = boardNode.begin(); i != boardNode.end(); ++i )
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
        }

        // Don't bother setting Null Pieces - every square is initialized
        // with a Null Piece set for it.
        if( type != "" )
        {
          setPiece(p,row,col);
        }
      }

      // Set which team is initially starting the game based on the
      // config file.
      pugi::xml_node turnNode = root.child("Turn");
      string turn = turnNode.attribute("color").value();
    }

    void InitState::setPiece( PiecePtr pieceToSet, int rowToSet, int colToSet )
    {
      if(pieceToSet)
      {
        pieceToSet->setLocation(rowToSet, colToSet);
        gameState_.board.setPiece(pieceToSet, rowToSet, colToSet);
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
