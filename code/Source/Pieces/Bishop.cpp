// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.


#include "Bishop.h"

namespace Chess
{
  
    
  Bishop::Bishop( const string name, Board * board, int initRow, int initCol )
    : Pieces( name, "B", initRow, initCol )
  {
    scanner_ = new DualAxisScan ( board ) ;
  }

  Bishop::Bishop( const string name, Board * board )
    : Pieces( name, "B" )
  {
    scanner_ = new DualAxisScan ( board ) ;
  }

  bool Bishop::validDirection ( int destRow, int destCol )
  {
    if ( pieceMoved( destRow, destCol ) )
    {
      if ( abs(row - destRow) == abs(col - destCol) )
      {
        return true ;
      }
      else
      {
        return false ;
      }
    }
    else
    {
      return false ;
    }
    
  }

  bool Bishop::pathScan ( int destRow, int destCol )
  {
    scanner_->identifyScan( row, col, destRow, destCol ) ;
    Pieces * detectedPiece = scanner_->execute( ) ;
    
    if ( detectedPiece->getColor( ) == getColor( ) )
    {
      return false ;
    }
    else if ( detectedPiece->getRow( ) != destRow || 
              detectedPiece->getCol( ) != destCol )
    {
      return false ;
    }
    else
    {
      return true ;
    }

  }

}