#include "State/RelevancyState.h"

#include "Tools/pugixml/pugixml.hpp"

#include "Agents/Validator.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr RelevancyState::execute( )
    {
      DEBUG_CONSOLE_1ARG("State: RELEVANCY");

      try
      {
        Validator::differentSquare(gameState_.moveRequest);
        Validator::destinationSquareAvailable(gameState_.moveRequest, gameState_.board);
      }
      catch( string error )
      {
        cout << "[ERROR] " << error << endl;
        gameState_.errorMessage = error;
        return returnState_;
      }
      return nextState_;
    }

  }
}