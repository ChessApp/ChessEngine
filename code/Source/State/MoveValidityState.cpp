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
      Pieces * currentPiece = board_->getPiece( sourceRow, sourceCol ) ;
      if ( currentPiece->validDirection( sourceRow, sourceCol ) )
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