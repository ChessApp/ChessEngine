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



}