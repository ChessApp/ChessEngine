#include "BaseState.h"

namespace Chess
{
  namespace State
  {

    void BaseState::setTransitionStates ( BaseState * nextState, BaseState * returnState )
    {
      nextState_ = nextState ;
      returnState_ = returnState ;
    }

  }
}