#include "Pieces/BlackPawn.h"


namespace Chess
{

  BlackPawn::BlackPawn( const string& name )
    : Pieces(name, "P")
  { }

  bool BlackPawn::validDirection( const pair<int,int>& destination )
  {
    if( pieceMoved(destination) )
    {
      if( (destination.second == location_.second) && (destination.first == location_.first + 2) && (location_.first == 1) )
        return true;
      //move forward one square if that square is empty.
      else if( (destination.second == location_.second) && (destination.first == location_.first + 1) )
        return true;
      //move diagonally as long as there is an opposing piece to capture
      else if( ((destination.second == location_.second + 1) || (destination.second == location_.second - 1)) && (destination.first == location_.first + 1) )
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
