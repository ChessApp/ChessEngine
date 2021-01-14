#include "Pieces/Bishop.h"


namespace Chess
{

  Bishop::Bishop( const string& name )
    : Pieces(name, "B")
  { }

  bool Bishop::validDirection( PiecePtr& pieceAtDestination )
  {
    const pair<int,int>& destination = pieceAtDestination->getLocation();
    if( !pieceMoved(destination) )
      return false;
    if( abs(location_.first - destination.first) != abs(location_.second - destination.second) )
      return false;

    return true;
  }

}
