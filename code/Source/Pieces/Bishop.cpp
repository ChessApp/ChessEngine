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
    scan = new DualAxisScan ( board ) ;
  }

  Bishop::Bishop( const string name, Board * board )
    : Pieces( name, "B" )
  {
    scan = new DualAxisScan ( board ) ;
  }

  bool Bishop::validDirection ( int destRow, int destCol )
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

}