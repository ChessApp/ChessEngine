#ifndef CHESS_STATE_MOVESTATE_H_
#define CHESS_STATE_MOVESTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "GameState.h"


namespace Chess
{
  namespace State
  {

    class MoveState
      : public BaseState
    {
    public:
      //-- types

      //-- construction
      inline MoveState( GameState& gameState ) 
        : BaseState(gameState, "MoveState")
      { }

      //-- BaseState interface
      virtual StatePtr executeImpl();

    protected:
      //-- protected methods
      void movePiece( PiecePtr pieceToSet, const pair<int,int>& destination );

      //-- protected members
    };

  }
}

#endif /* CHESS_STATE_MOVESTATE_H_ */
