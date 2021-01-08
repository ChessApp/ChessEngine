#ifndef CHESS_STATE_INITSTATE_H_
#define CHESS_STATE_INITSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"


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
        : BaseState(gameState)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );

    protected:
      //-- protected methods
      void setPiece( PiecePtr pieceToSet, int rowToSet, int colToSet );
      void parseInitialStateFile( );

      //-- protected members
    };

  }
}

#endif /* CHESS_STATE_INITSTATE_H_ */
