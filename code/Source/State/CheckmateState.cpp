#include "State/CheckmateState.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr CheckmateState::execute( )
    {
      std::cout << "Checkmate!" << std::endl;

      interface_->printBoard();
      return nextState_;
    }

  }
}