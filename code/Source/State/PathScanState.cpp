#include "PathScanState.h"

namespace Chess
{
  namespace State
  {

    BaseState * PathScanState::execute ( )
    {
      std::cout << "Path scan state" << std::endl ;

      Pieces * currentPiece = board_->getPiece( interface_->sourceRow, interface_->sourceCol ) ;

      return nextState_ ;
      
    }

  }
}