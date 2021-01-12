// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.
#include "Pieces/King.h"


namespace Chess
{

  King::King( const string& name )
    : Pieces(name, "K")
  { }

  bool King::validDirection( PiecePtr& pieceAtDestination )
  {
    const pair<int,int>& destination = pieceAtDestination->getLocation();
    if( abs(destination.second - location_.second) <= 1 &&
        abs(destination.first - location_.first) <= 1 &&
        pieceMoved(destination) )
      return true;
    else
      return false;
  }

}
