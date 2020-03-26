// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.


#include "Pieces/Knight.h"

namespace Chess
{
  
    
  Knight::Knight( const string name, int initRow, int initCol )
    : Pieces( name, "KN", initRow, initCol )
  {
    
  }

  Knight::Knight( const string name )
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