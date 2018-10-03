#include "MoveState.h"

namespace Chess
{
  namespace State
  {

    BaseState * MoveState::execute ( )
    {
      std::cout << "Move state" << std::endl ;
      
      Pieces * pieceToMove = board_->getPiece( interface_->sourceRow, interface_->sourceCol ) ;
      board_->setPiece( pieceToMove, interface_->destRow, interface_->destCol ) ;

      return nextState_ ;
    }

    void MoveState::setPiece( Pieces * pieceToSet, int rowToSet, int colToSet )
    {
      pieceToSet->setLocation( rowToSet, colToSet ) ;
      board_->setPiece( pieceToSet, rowToSet, colToSet ) ;
    }

  }
}