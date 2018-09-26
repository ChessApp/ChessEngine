// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.


#include "King.h"

namespace Chess
{

    
  King::King( const string name, Board * board )
    : Pieces( name, "K" )
  {
    
  }


}