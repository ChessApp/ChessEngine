// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.


#include "WhitePawn.h"

namespace Chess
{

    
  WhitePawn::WhitePawn( const string name, Board * board, int initRow, int initCol )
    : Pieces( name, "P", initRow, initCol )
  {
    
  }

  WhitePawn::WhitePawn( const string name, Board * board )
    : Pieces( name, "P" )
  {
    
  }

  bool WhitePawn::validDirection( int destRow, int destCol )
  {
    if ( destCol == col && destRow == row - 2 && row == 6 )
    {
      return true;
    }
    //move forward one square if that square is empty.
    else if ( destCol == col && destRow == row - 1 )
    {
      return true;
    }
    //move diagonally as long as there is an opposing piece to capture
    else if ( ( destCol == col + 1 || destCol == col - 1 ) && destRow == row - 1 )
    {
      return true;
    }
    else
    {
      return false;
    }
  }


}