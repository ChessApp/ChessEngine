#ifndef CHESS_VALIDATOR_H_
#define CHESS_VALIDATOR_H_

#include "Chess.h"
#include "GameState.h"
#include "Board.h"


namespace Chess
{
  namespace Validator
  {

    void differentSquare( const GameState::MoveRequest& moveRequest );
    void destinationSquareAvailable( const GameState::MoveRequest& moveRequest, Board& board );

  }
}

#endif /* CHESS_VALIDATOR_H_ */
