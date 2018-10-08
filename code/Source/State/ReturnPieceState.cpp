#include "ReturnPieceState.h"

namespace Chess
{
  namespace State
  {

    BaseState * ReturnPieceState::execute ( )
    {
      std::cout << "Return piece state" << std::endl ;
      
      Pieces * pieceToReturn = board_->getPiece( interface_->destRow, interface_->destCol ) ;
      returnPiece( pieceToReturn, interface_->sourceRow, interface_->sourceCol ) ;

      return nextState_ ;
    }

    void ReturnPieceState::returnPiece( Pieces * pieceToReturn, int rowToReturn, int colToReturn )
    {
      pieceToReturn->setLocation( rowToReturn, colToReturn ) ;
      board_->setPiece( pieceToReturn, rowToReturn, colToReturn ) ;
      Pieces * np = new NullPiece( ".. ", board_ ) ;
      np->setLocation( interface_->destRow, interface_->destCol ) ;
      board_->setPiece( np, interface_->destRow, interface_->destCol ) ;
    }

  }
}