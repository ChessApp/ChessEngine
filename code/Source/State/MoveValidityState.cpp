#include "MoveValidityState.h"

namespace Chess
{
  namespace State
  {

    BaseState * MoveValidityState::execute ( )
    {
      std::cout << "Move validity state" << std::endl ;

      int sourceRow = interface_->sourceRow ;
      int sourceCol = interface_->sourceCol ;
      int destRow = interface_->destRow ;
      int destCol = interface_->destCol ;
      Pieces * currentPiece = board_->getPiece( sourceRow, sourceCol ) ;
      if ( currentPiece->validDirection( destRow, destCol ) )
      {
      	return nextState_ ;
      }
      else
      {
      	return returnState_ ;
      }
      
    }

  }
}