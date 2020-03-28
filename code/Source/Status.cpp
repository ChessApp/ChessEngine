#include "Status.h"


namespace Chess
{

  Status::Status( )
    : turn_('W')
  { }
  
  void Status::updateCurrentPiece( PiecePtr piece )
  {
    currentPiece_ = piece;
  }

  void Status::updateTurn( )
  {
    if( 'W' == turn_ )
		  turn_ = 'B';
    else
		  turn_ = 'W';
  }

  void Status::updateCurrentLocation( int row, int col )
  {
    currentRow_ = row;
    currentCol_ = col;
  }

  void Status::updateDestLocation( int row, int col )
  {
    destRow_ = row;
    destCol_ = col;
  }

  Status::PiecePtr Status::getCurrentPiece( )
  {
    return currentPiece_;
  }

  char Status::getTurn( )
  {
    return turn_;
  }

}
