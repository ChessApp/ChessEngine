#include "State/MoveState.h"

#include "Pieces/NullPiece.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr MoveState::executeImpl()
    {
      PiecePtr pieceToMove = gameState_.board.getPiece(gameState_.moveRequest.front());
      movePiece(pieceToMove, gameState_.moveRequest.back());

      return nextState_;
    }

    void MoveState::movePiece( PiecePtr pieceToSet, const pair<int,int>& destination )
    {
      PiecePtr pieceAtDestination = gameState_.board.getPiece(destination);
      gameState_.setCapturedPieceId( pieceAtDestination->getId() );

      gameState_.board.movePiece(pieceToSet, destination);
    }

  }
}
