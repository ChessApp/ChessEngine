#include "State/MoveValidityState.h"

#include "Tools/pugixml/pugixml.hpp"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr MoveValidityState::execute( )
    {
      DEBUG_CONSOLE_1ARG("State: MOVE VALIDITY");

      auto source      = gameState_.moveRequest.front();
      auto destination = gameState_.moveRequest.back();

      PiecePtr currentPiece = gameState_.board.getPiece(source.first, source.second);
      try
      {
        currentPiece->validDirection(destination.first, destination.second);
      }
      catch( string error )
      {
        return returnState_;
      }

      return nextState_;
    }

  }
}
