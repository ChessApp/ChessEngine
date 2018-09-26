// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.


#include "NullPiece.h"

namespace Chess
{
  
    
  NullPiece::NullPiece( const string name, Board * board )
    : Pieces( name, "" )
  {
    
  }

  bool NullPiece::validDirection (int destRow, int destCol )
  {
    return false ;
  }


}