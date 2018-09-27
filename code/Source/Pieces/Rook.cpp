// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.


#include "Rook.h"

namespace Chess
{

    
  Rook::Rook( const string name, Board * board )
  	: Pieces( name, "R" )
  {
  	scan ( new SingleAxisScan ( board ) ) ;
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

  
}