#include "Agents/ValidationAgent.h"

namespace Chess
{
  namespace ValidationAgent
  {

    void differentSquare( const GameState::MoveRequest& moveRequest )
    {
      if( moveRequest.front() == moveRequest.back() )
        throw Exception("Piece cannot be moved to the square it is already on!", "ValidationAgent::differentSquare");
    }

    void destinationSquareAvailable( const GameState::MoveRequest& moveRequest, Board& board )
    {
      GameState::PiecePtr currentPiece = board.getPiece(moveRequest.front().first, moveRequest.front().second);
      GameState::PiecePtr destPiece = board.getPiece(moveRequest.back().first, moveRequest.back().second);

      if( currentPiece->getColor() == destPiece->getColor() )
        throw Exception("Destination square already occupied by the same team!", "ValidationAgent::destinationSquareAvailable");
    }

  }
}