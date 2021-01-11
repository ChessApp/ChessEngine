#include "Pieces/Bishop.h"


namespace Chess
{

  Bishop::Bishop( const string& name )
    : Pieces(name, "B")
  { }

  bool Bishop::validDirection( const pair<int,int>& destination )
  {
    pieceMoved(destination);
    if( abs(location_.first - destination.first) != abs(location_.second - destination.second) )
      throw Exception(invalidDirectionMessage_, "Bishop::validDirection");
    
    return true;
  }

}
