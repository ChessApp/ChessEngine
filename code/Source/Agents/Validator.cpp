#include "Agents/Validator.h"

namespace Chess
{
  namespace Validator
  {

    void differentSquare( const GameState::MoveRequest& moveRequest )
    {
      if( moveRequest.front() == moveRequest.back() )
      {
        throw string("Validator::differentSquare -> Piece cannot be moved to the square it is already on!");
      }
    }

    void destinationSquareAvailable( const GameState::MoveRequest& moveRequest, Board& board )
    {
      GameState::PiecePtr currentPiece = board.getPiece(moveRequest.front().first, moveRequest.front().second);
      GameState::PiecePtr destPiece = board.getPiece(moveRequest.back().first, moveRequest.back().second);

      if( currentPiece->getColor() == destPiece->getColor() )
      {
        throw string("Validator::destinationSquareAvailable -> Destination square already occupied by the same team!");
      }
    }

  }
}