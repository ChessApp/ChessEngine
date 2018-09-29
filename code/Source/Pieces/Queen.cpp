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
    scan = new CompoundAxisScan( board ) ;
  }

}