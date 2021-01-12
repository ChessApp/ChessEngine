// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.
#include "Pieces/NullPiece.h"


namespace Chess
{
   
  NullPiece::NullPiece( const string& name, const pair<int,int>& location )
    : Pieces(name, "", location)
  { }

  bool NullPiece::validDirection( PiecePtr& )
  {
    return false;
  }

}
