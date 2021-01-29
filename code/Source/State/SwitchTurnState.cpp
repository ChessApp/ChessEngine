#include "State/SwitchTurnState.h"

#include "Pieces/NullPiece.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr SwitchTurnState::executeImpl()
    {
      if( gameState_.attacker == GameState::whiteAttacker )
        gameState_.attacker = GameState::blackAttacker;
      else
        gameState_.attacker = GameState::whiteAttacker;

      return nextState_;
    }

  }
}
