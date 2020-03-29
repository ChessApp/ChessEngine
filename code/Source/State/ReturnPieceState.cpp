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
      PiecePtr np( new NullPiece(".. ") );
      np->setLocation(interface_->destRow, interface_->destCol);
      board_->setPiece(np, interface_->destRow, interface_->destCol);
    }

  }
}
