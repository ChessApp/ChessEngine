#include "State/CheckmateState.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr CheckmateState::executeImpl()
    {
      gameState_.checkmate = true;

      return nextState_;
    }

  }
}