// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.


#include "Pawn.h"

namespace Chess
{

    
  Pawn::Pawn( const string name, Board * board, int initRow, int initCol )
    : Pieces( name, "P", initRow, initCol )
  {
    
  }


}