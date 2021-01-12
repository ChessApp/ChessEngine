#include "Pieces/BlackPawn.h"


namespace Chess
{

  BlackPawn::BlackPawn( const string& name )
    : Pieces(name, "P")
  { }

  bool BlackPawn::validDirection( PiecePtr& pieceAtDestination )
  {
    const pair<int,int>& destination = pieceAtDestination->getLocation();
    if( pieceMoved(destination) )
    {
      if( (destination.second == location_.second) && (destination.first == location_.first + 2) && (location_.first == 1) &&
                pieceAtDestination->getColor() == "" )
        return true;
      //move forward one square if that square is empty.
      else if( (destination.second == location_.second) && (destination.first == location_.first + 1) &&
                pieceAtDestination->getColor() == "" )
        return true;
      //move diagonally as long as there is an opposing piece to capture
      else if( ((destination.second == location_.second + 1) || (destination.second == location_.second - 1)) &&
                (destination.first == location_.first + 1) &&
                 pieceAtDestination->getColor() == "W" )
        return true;
      else
        throw Exception(invalidDirectionMessage_, "BlackPawn::validDirection");
    }
    else
    {
      throw Exception(invalidDirectionMessage_, "BlackPawn::validDirection");
    }  
  }

}
