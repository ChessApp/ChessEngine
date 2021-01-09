#include "State/BaseState.h"
#include "Agents/ExceptionAgent.h"

namespace Chess
{
  namespace State
  {

    void BaseState::setTransitionStates( StatePtr nextState, StatePtr returnState )
    {
      nextState_   = nextState;
      returnState_ = returnState;
    }

    BaseState::StatePtr BaseState::execute()
    {
      try
      {
        return executeImpl();
      }
      catch( Exception& e )
      {
        e.setState(name_);
        ExceptionAgent::handle(e, gameState_);
        return returnState_;
      }
    }

  }
}
