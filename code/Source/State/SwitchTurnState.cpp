#include "State/SwitchTurnState.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr SwitchTurnState::executeImpl()
    {
      if( gameState_.attacker == GameState::Attacker::white )
        gameState_.attacker = GameState::Attacker::black;
      else
        gameState_.attacker = GameState::Attacker::white;

      return nextState_;
    }

  }
}
