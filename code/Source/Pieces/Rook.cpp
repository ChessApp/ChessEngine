// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.


#include "Rook.h"

namespace Chess
{

    
  Rook::Rook( const string name, Board * board, int initRow, int initCol )
  	: Pieces( name, "R", initRow, initCol )
  {
  	scanner_ = new SingleAxisScan ( board ) ;
  }

  Rook::Rook( const string name, Board * board )
    : Pieces( name, "R" )
  {
    scanner_ = new SingleAxisScan ( board ) ;
  }

  bool Rook::validDirection ( int destRow, int destCol )
  {
    if ( row == destRow || col == destCol )
    {
      return true ;
    }
    else
    {
      // throw "That move is invalid." ;
      return false ;
    }
  }

  bool Rook::pathScan ( int destRow, int destCol )
  {
    scanner_->identifyScan( row, col, destRow, destCol ) ;
    Pieces * detectedPiece = scanner_->execute( ) ;
    if ( detectedPiece->getColor( ) == getColor( ) )
    {
      return false ;
    }
    else if ( detectedPiece->getRow( ) != getRow( ) || 
              detectedPiece->getCol( ) != getCol( ) )
    {
      return false ;
    }
    else
    {
      return true ;
    }
  }

  
}