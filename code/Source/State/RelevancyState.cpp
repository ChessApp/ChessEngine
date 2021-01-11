#include "State/RelevancyState.h"

#include "Tools/pugixml/pugixml.hpp"

#include "Agents/ValidationAgent.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr RelevancyState::executeImpl()
    {
      ValidationAgent::differentSquare(gameState_.moveRequest);
      ValidationAgent::destinationSquareAvailable(gameState_.moveRequest, gameState_.board);
      ValidationAgent::pieceOwner(gameState_);

      return nextState_;
    }

  }
}