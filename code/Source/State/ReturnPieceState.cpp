#include "State/ReturnPieceState.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr ReturnPieceState::executeImpl()
    {
      PiecePtr pieceToReturn = gameState_.board.getPiece(gameState_.moveRequest.back());
      returnPiece(pieceToReturn, gameState_.moveRequest.front());
      // Reset the captured piece id
      gameState_.capturedPieceId = -1;

      return nextState_;
    }

    void ReturnPieceState::returnPiece( PiecePtr pieceToReturn, const pair<int,int>& returnLocation )
    {
      gameState_.board.movePiece(pieceToReturn, returnLocation);

      auto capturedPiece = gameState_.activePieces.find(gameState_.capturedPieceId);
      if( capturedPiece != gameState_.activePieces.end() )
        gameState_.board.setPiece(capturedPiece->second, gameState_.moveRequest.back());
    }

  }
}
