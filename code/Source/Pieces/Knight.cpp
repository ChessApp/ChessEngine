#include "Pieces/Knight.h"


namespace Chess
{

  Knight::Knight( const string& name )
    : Pieces( name, "KN" )
  { }

  bool Knight::validDirection( PiecePtr& pieceAtDestination )
  {
    const pair<int,int>& destination = pieceAtDestination->getLocation();
    int rowDiff = abs(destination.first - location_.first);
    int colDiff = abs(destination.second - location_.second);

    if( (rowDiff == 2) && (colDiff == 1) )
      return true;
    else if( (rowDiff == 1) && (colDiff == 2) )
      return true;

    throw Exception(invalidDirectionMessage_, "Knight::validDirection");
  }

}
