// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.


#include "Pieces/Queen.h"

namespace Chess
{
  
    
  Queen::Queen( const string name, Board * board, int initRow, int initCol )
    : Pieces( name, "Q", initRow, initCol )
  {
    scanner_ = new CompoundAxisScan( board ) ;
  }

  Queen::Queen( const string name, Board * board )
    : Pieces( name, "Q" )
  {
    scanner_ = new CompoundAxisScan( board ) ;
  }

  bool Queen::validDirection( int destRow, int destCol )
  {
    if ( pieceMoved( destRow, destCol ) )
    {
      if ( row == destRow || col == destCol )
      {
        return true ;
      }
      else if ( abs(row - destRow) == abs(col - destCol) )
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

  bool Queen::pathScan ( int destRow, int destCol )
  {
    scanner_->identifyScan( row, col, destRow, destCol ) ;
    ScanResult * scanResult = scanner_->execute( ) ;
    Pieces * detectedPiece = scanResult->detectedPiece ;
    
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