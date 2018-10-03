// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.


#include "Queen.h"

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
      // throw "That move is invalid." ;
      return false ;
    }
  }

}