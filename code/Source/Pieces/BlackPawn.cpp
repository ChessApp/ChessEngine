// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.


#include "BlackPawn.h"

namespace Chess
{

    
  BlackPawn::BlackPawn( const string name, Board * board, int initRow, int initCol )
    : Pieces( name, "P", initRow, initCol )
  {
    
  }

  BlackPawn::BlackPawn( const string name, Board * board )
    : Pieces( name, "P" )
  {
    
  }

  bool BlackPawn::validDirection( int destRow, int destCol )
  {
    if ( pieceMoved( destRow, destCol ) )
    {
      if ( destCol == col && destRow == row + 2 && row == 1 )
      {
        return true;
      }
      //move forward one square if that square is empty.
      else if ( destCol == col && destRow == row + 1 )
      {
        return true;
      }
      //move diagonally as long as there is an opposing piece to capture
      else if ( ( destCol == col + 1 || destCol == col - 1 ) && destRow == row + 1 )
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false ;
    }  
  }

  bool BlackPawn::pathScan ( int destRow, int destCol )
  {
    return true ;

  }


}