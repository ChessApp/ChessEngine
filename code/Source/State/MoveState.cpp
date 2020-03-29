#include "State/MoveState.h"

#include "Pieces/NullPiece.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr MoveState::execute( )
    {
      std::cout << "Move state" << std::endl;
      
      nextState_->setWhiteKing(whiteKing_);
      nextState_->setBlackKing(blackKing_);
      
      PiecePtr pieceToMove = board_->getPiece(interface_->sourceRow, interface_->sourceCol);
      setPiece(pieceToMove, interface_->destRow, interface_->destCol);

      return nextState_;
    }

    void MoveState::setPiece( PiecePtr pieceToSet, int rowToSet, int colToSet )
    {
      pieceToSet->setLocation(rowToSet, colToSet);
      board_->setPiece(pieceToSet, rowToSet, colToSet);
      PiecePtr np( new NullPiece(".. ") );
      np->setLocation(interface_->sourceRow, interface_->sourceCol);
      board_->setPiece(np, interface_->sourceRow, interface_->sourceCol);
    }

  }
}
