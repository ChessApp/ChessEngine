#ifndef CHESS_STATE_INITSTATE_H_
#define CHESS_STATE_INITSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "Pieces/Pieces.h"


namespace Chess
{
  namespace State
  {

    class InitState
      : public BaseState
    {
    public:
      //-- types

      //-- construction
      inline InitState( GameState& gameState )
        : BaseState(gameState, "InitState")
      { }

      //-- BaseState interface
      virtual StatePtr executeImpl() override;

    protected:
      //-- protected types
      typedef shared_ptr<Pieces> PiecePtr;

      //-- protected methods
      void deserializeGameStateFile();
      void setPiece( PiecePtr pieceToSet, const pair<int, int>& location );

      //-- protected members
    };

  }
}

#endif /* CHESS_STATE_INITSTATE_H_ */
