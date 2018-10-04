#include "InputState.h"

namespace Chess
{
  namespace State
  {

    BaseState * InputState::execute ( )
    {
      std::cout << "Input state" << std::endl ;
      
      interface_->printGameConds( ) ;
      interface_->getInput( ) ;
      
      nextState_->setWhiteKing( whiteKing_ ) ;
      nextState_->setBlackKing( blackKing_ ) ;
      return nextState_ ;
    }

  }
}