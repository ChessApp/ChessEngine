#include "State/MoveValidityState.h"

#include "Tools/pugixml/pugixml.hpp"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr MoveValidityState::executeImpl()
    {
      DEBUG_CONSOLE_1ARG("State: MOVE VALIDITY");

      auto source      = gameState_.moveRequest.front();
      auto destination = gameState_.moveRequest.back();

      PiecePtr currentPiece = gameState_.board.getPiece(source);
      currentPiece->validDirection(destination);

      return nextState_;
    }

  }
}
