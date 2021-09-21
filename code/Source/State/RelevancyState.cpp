#include "State/RelevancyState.h"

#include "Agents/ValidationAgent.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr RelevancyState::executeImpl()
    {
      ValidationAgent::isClientTurn(gameState_);
      ValidationAgent::pieceOwner(gameState_);
      ValidationAgent::differentSquare(gameState_.moveRequest);
      ValidationAgent::destinationSquareAvailable(gameState_.moveRequest, gameState_.board);

      return nextState_;
    }

  }
}