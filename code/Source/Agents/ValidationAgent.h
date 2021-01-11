#ifndef CHESS_VALIDATIONAGENT_H_
#define CHESS_VALIDATIONAGENT_H_

#include "Chess.h"
#include "GameState.h"
#include "Board.h"


namespace Chess
{
  namespace ValidationAgent
  {

    void differentSquare( const GameState::MoveRequest& moveRequest );
    void destinationSquareAvailable( const GameState::MoveRequest& moveRequest, Board& board );
    void pieceOwner( GameState& gameState );

  }
}

#endif /* CHESS_VALIDATIONAGENT_H_ */
