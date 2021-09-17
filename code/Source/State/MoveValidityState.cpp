#include "State/MoveValidityState.h"

#include "Tools/pugixml/pugixml.hpp"


namespace Chess
{
  namespace State
  {

    const string invalidDirectionMessage = "The selected piece is not capable of moving to the requested destination!";

    BaseState::StatePtr MoveValidityState::executeImpl()
    {
      auto source      = gameState_.moveRequest.front();
      auto destination = gameState_.moveRequest.back();

      PiecePtr currentPiece = gameState_.board.getPiece(source);
      PiecePtr pieceAtDestination = gameState_.board.getPiece(destination);
      if( !currentPiece->validDirection(pieceAtDestination) )
        throw Exception(invalidDirectionMessage, "MoveValidityState::executeImpl");

      return nextState_;
    }

  }
}
