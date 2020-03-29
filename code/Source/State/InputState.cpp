#include "State/InputState.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr InputState::execute( )
    {
      DEBUG_CONSOLE_1ARG("State: INPUT");
      
      interface_->printGameConds();
      interface_->getInput();
      
      nextState_->setWhiteKing(whiteKing_);
      nextState_->setBlackKing(blackKing_);
      return nextState_;
    }

  }
}
