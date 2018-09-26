#include "Status.h"

namespace Chess
{

  Status::Status ( )
    : turn('W')
  {}
  
  void Status::updateCurrentPiece ( Pieces * piece )
  {
    currentPiece = piece;
  }

  void Status::updateTurn ( )
  {
    if ( 'W' == turn )
    {
		turn = 'B';
    }
    else
    {
		turn = 'W';
    }
  }

  void Status::updateCurrentLocation ( int row, int col )
  {
    currentRow = row;
    currentCol = col;
  }

  void Status::updateDestLocation ( int row, int col )
  {
    destRow = row;
    destCol = col;
  }

  Pieces * Status::getCurrentPiece ( )
  {
    return currentPiece;
  }

  char Status::getTurn ( )
  {
    return turn;
  }

}
