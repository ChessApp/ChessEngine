#include "Pieces/Queen.h"


namespace Chess
{

  Queen::Queen( const string& name )
    : Pieces(name, "Q")
  { }

  bool Queen::validDirection( const pair<int,int>& destination )
  {
    pieceMoved(destination);
    if( (location_.first == destination.first) || (location_.second == destination.second) )
      return true;
    if( abs(location_.first - destination.first) == abs(location_.second - destination.second) )
      return true;

    throw Exception(invalidDirectionMessage_, "Queen::validDirection");    
  }

}
