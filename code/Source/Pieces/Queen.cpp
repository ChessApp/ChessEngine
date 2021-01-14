#include "Pieces/Queen.h"


namespace Chess
{

  Queen::Queen( const string& name )
    : Pieces(name, "Q")
  { }

  bool Queen::validDirection( PiecePtr& pieceAtDestination )
  {
    const pair<int,int>& destination = pieceAtDestination->getLocation();
    if( !pieceMoved(destination) )
      return false;
    if( (location_.first == destination.first) || (location_.second == destination.second) )
      return true;
    if( abs(location_.first - destination.first) == abs(location_.second - destination.second) )
      return true;

    return false;
  }

}
