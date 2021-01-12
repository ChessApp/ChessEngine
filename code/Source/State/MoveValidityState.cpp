#include "State/MoveValidityState.h"

#include "Tools/pugixml/pugixml.hpp"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr MoveValidityState::executeImpl()
    {
      auto source      = gameState_.moveRequest.front();
      auto destination = gameState_.moveRequest.back();

      PiecePtr currentPiece = gameState_.board.getPiece(source);
      PiecePtr pieceAtDestination = gameState_.board.getPiece(destination);
      currentPiece->validDirection(pieceAtDestination);

      return nextState_;
    }

  }
}
