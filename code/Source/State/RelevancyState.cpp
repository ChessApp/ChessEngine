#include "State/RelevancyState.h"

#include "Tools/pugixml/pugixml.hpp"

#include "Agents/ValidationAgent.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr RelevancyState::executeImpl()
    {
      DEBUG_CONSOLE_1ARG("State: RELEVANCY");

      ValidationAgent::differentSquare(gameState_.moveRequest);
      ValidationAgent::destinationSquareAvailable(gameState_.moveRequest, gameState_.board);

      return nextState_;
    }

  }
}