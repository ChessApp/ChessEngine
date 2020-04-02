#include "State/MoveState.h"

#include "Pieces/NullPiece.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr MoveState::execute( )
    {
      DEBUG_CONSOLE_1ARG("State: MOVE");
      
      nextState_->setWhiteKing(whiteKing_);
      nextState_->setBlackKing(blackKing_);
      
      PiecePtr pieceToMove = board_->getPiece(interface_->sourceRow, interface_->sourceCol);
      setPiece(pieceToMove, interface_->destRow, interface_->destCol);

      return nextState_;
    }

    void MoveState::setPiece( PiecePtr pieceToSet, int rowToSet, int colToSet )
    {
      // Stash the original piece with the currentTurn_. This piece must be restored
      // to this square if the DefensiveCheckScan fails.
      currentTurn_->setPendingRemovedPiece( board_->getPiece(rowToSet, colToSet) );

      pieceToSet->setLocation(rowToSet, colToSet);
      board_->setPiece(pieceToSet, rowToSet, colToSet);
      PiecePtr np( new NullPiece(".. ") );
      np->setLocation(interface_->sourceRow, interface_->sourceCol);
      board_->setPiece(np, interface_->sourceRow, interface_->sourceCol);
    }

  }
}
