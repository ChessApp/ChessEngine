#include "State/MoveValidityState.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr MoveValidityState::execute( )
    {
      DEBUG_CONSOLE_1ARG("State: MOVE VALIDITY");

      nextState_->setWhiteKing(whiteKing_);
      nextState_->setBlackKing(blackKing_);

      int sourceRow = interface_->sourceRow;
      int sourceCol = interface_->sourceCol;
      int destRow   = interface_->destRow;
      int destCol   = interface_->destCol;

      PiecePtr currentPiece = board_->getPiece(sourceRow, sourceCol);
      if( currentPiece->validDirection(destRow, destCol) )
      	return nextState_;
      else
      	return returnState_;
    }

  }
}
