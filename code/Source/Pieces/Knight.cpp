// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.


#include "Knight.h"

namespace Chess
{
  
    
  Knight::Knight( const string name, Board * board, int initRow, int initCol )
    : Pieces( name, "KN", initRow, initCol )
  {
    
  }

  Knight::Knight( const string name, Board * board )
    : Pieces( name, "KN" )
  {
    
  }

  bool Knight::validDirection( int destRow, int destCol )
  {
    int rowDiff = abs( destRow - row ) ;
    int colDiff = abs( destCol - col ) ;
    if ( rowDiff == 2 && colDiff == 1 )
    {
      return true ;
    }
    else if ( rowDiff == 1 && colDiff == 2 )
    {
      return true ;
    }
    else
    {
      return false ;
    }
  }

  bool Knight::pathScan ( int destRow, int destCol )
  {
    return true ;
  }

}