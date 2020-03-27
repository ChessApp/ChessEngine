#include "State/BaseState.h"

namespace Chess
{
  namespace State
  {

    void BaseState::setTransitionStates ( StatePtr nextState, StatePtr returnState )
    {
      nextState_ = nextState ;
      returnState_ = returnState ;
    }

  }
}