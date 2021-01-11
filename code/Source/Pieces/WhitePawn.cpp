// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.
#include "Pieces/WhitePawn.h"


namespace Chess
{

  WhitePawn::WhitePawn( const string& name )
    : Pieces(name, "P")
  { }

  bool WhitePawn::validDirection( const pair<int,int>& destination )
  {
    if( pieceMoved(destination) )
    {
      if( (destination.second == location_.second) && (destination.first == location_.first - 2) && (location_.first == 6) )
        return true;
      //move forward one square if that square is empty.
      else if( (destination.second == location_.second) && (destination.first == location_.first - 1) )
        return true;
      //move diagonally as long as there is an opposing piece to capture
      else if( ((destination.second == location_.second + 1) || (destination.second == location_.second - 1)) && (destination.first == location_.first - 1) )
        return true;
      else
        return false;
    }
    else
    {
      return false ;
    }

  }

}
