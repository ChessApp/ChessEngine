// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.
#include "Pieces/Rook.h"


namespace Chess
{

  Rook::Rook( const string& name )
    : Pieces(name, "R")
  { }

  bool Rook::validDirection( PiecePtr& pieceAtDestination )
  {
    const pair<int,int>& destination = pieceAtDestination->getLocation();
    pieceMoved(destination);
    if( location_.first == destination.first || location_.second == destination.second ) return true;

    throw Exception(invalidDirectionMessage_, "Rook::validDirection");
  }

}
