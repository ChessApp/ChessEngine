#ifndef CHESS_STATE_RETURNPIECESTATE_H_
#define CHESS_STATE_RETURNPIECESTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "GameState.h"


namespace Chess
{
  namespace State
  {

    class ReturnPieceState
      : public BaseState
    {
    public:
      //-- types

      //-- construction
      inline ReturnPieceState( GameState& gameState ) 
        : BaseState(gameState, "ReturnPieceState")
      { }

      //-- BaseState interface
      virtual StatePtr executeImpl();

    protected:
      //-- protected methods
      void returnPiece( PiecePtr pieceToReturn, const pair<int,int>& returnLocation );

      //-- protected members
    };

  }
}

#endif /* CHESS_STATE_RETURNPIECESTATE_H_ */
