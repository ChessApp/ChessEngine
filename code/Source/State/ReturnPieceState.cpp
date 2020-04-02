#include "State/ReturnPieceState.h"

#include "Pieces/NullPiece.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr ReturnPieceState::execute( )
    {
      DEBUG_CONSOLE_1ARG("State: RETURN PIECE");
      
      PiecePtr pieceToReturn = board_->getPiece(interface_->destRow, interface_->destCol);
      returnPiece(pieceToReturn, interface_->sourceRow, interface_->sourceCol);

      return nextState_;
    }

    void ReturnPieceState::returnPiece( PiecePtr pieceToReturn, int rowToReturn, int colToReturn )
    {
      pieceToReturn->setLocation(rowToReturn, colToReturn);
      board_->setPiece(pieceToReturn, rowToReturn, colToReturn);
      // Restore the original piece back to its square on the board (stored
      // in the currentTurn_ since the MoveState).
      PiecePtr originalPiece = currentTurn_->getPendingRemovedPiece();
      board_->setPiece(originalPiece, originalPiece->getRow(), originalPiece->getCol());
    }

  }
}
