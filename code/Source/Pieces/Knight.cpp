// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.
#include "Pieces/Knight.h"


namespace Chess
{

  Knight::Knight( const string name )
    : Pieces( name, "KN" )
  { }

  bool Knight::validDirection( const pair<int,int>& destination )
  {
    int rowDiff = abs(destination.first - location_.first);
    int colDiff = abs(destination.second - location_.second);

    if( (rowDiff == 2) && (colDiff == 1) )
      return true;
    else if( (rowDiff == 1) && (colDiff == 2) )
      return true;
    else
      return false;
  }

  bool Knight::pathScan( const pair<int,int>& destination )
  {
    return true;
  }

}
