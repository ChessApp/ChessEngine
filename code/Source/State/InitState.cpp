#include "State/InitState.h"

#include "Tools/pugixml/pugixml.hpp"

namespace Chess
{
  namespace State
  {

    BaseState::StatePtr InitState::execute ( )
    {
      std::cout << "Init state" << std::endl ;

      vector<PiecePtr> nullPieceList ;
      for ( int j = 0; j < 8; j++ )
      {
        for ( int i = 0; i < 8; i++ )
        {
          PiecePtr np = new NullPiece( ".. " ) ;
          setPiece( np, j, i ) ;
          nullPieceList.push_back( np ) ;
        }  
      }

      // Configure the state of the board from the xml
      // file passed in during construction of this class.
      parseXMLFile();

      board_->init( nullPieceList ) ;

      currentTurn_ = whiteTurn_ ;
      
      interface_->printBoard( ) ;

      return nextState_ ;
    }

    void InitState::parseXMLFile()
    {
      // Setup the xml document structure and load the state initialization file
      pugi::xml_document doc;
      pugi::xml_parse_result result = doc.load_file(configFileName_);

      // Grab the root node
      pugi::xml_node root = doc.child("root");

      // Iterate through all of the children of the root node
      for( pugi::xml_node_iterator i = root.begin(); i != root.end(); ++i )
      {
        string type   = i->attribute("type").value();
        string color  = i->attribute("color").value();
        int    row    = i->attribute("row").as_int();
        int    col    = i->attribute("column").as_int();
        string symbol = i->attribute("symbol").value();

        // Create pieces on the heap based on the configuration
        // read from the xml file
        PiecePtr p;
        if( type == "Pawn" )
        {
          if( color == "W" )
            p = new Chess::WhitePawn(symbol);
          else
            p = new Chess::BlackPawn(symbol);
        }
        else if( type == "Bishop" )
        {
          p = new Chess::Bishop(symbol, board_);
        }
        else if( type == "Rook" )
        {
          p = new Chess::Rook(symbol, board_);
        }
        else if( type == "Knight" )
        {
          p = new Chess::Knight(symbol);
        }
        else if( type == "Queen" )
        {
          p = new Chess::Queen(symbol, board_);
        }
        else if( type == "King" )
        {
          p = new Chess::Queen(symbol, board_);
          if( color == "W" )
          {
            whiteTurn_->setDefensiveKing(p) ;
            blackTurn_->setOffensiveKing(p) ;
          }
          else
          {
            whiteTurn_->setOffensiveKing(p) ;
            blackTurn_->setDefensiveKing(p) ;
          }
        }

        setPiece(p,row,col);

        if( color == "W" )
          whiteTurn_->setActivePiece(p);
        else
          blackTurn_->setActivePiece(p);
      }
    }

    void InitState::setPiece( PiecePtr pieceToSet, int rowToSet, int colToSet )
    {
      pieceToSet->setLocation( rowToSet, colToSet ) ;
      board_->setPiece( pieceToSet, rowToSet, colToSet ) ;
    }

  }
}