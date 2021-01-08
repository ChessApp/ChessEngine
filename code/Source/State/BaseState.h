#ifndef CHESS_STATE_BASESTATE_H_
#define CHESS_STATE_BASESTATE_H_

#include "Chess.h"
#include "GameState.h"
#include "Pieces/Pieces.h"


namespace Chess
{
  namespace State
  {

    class BaseState
    {
    public:
      //-- types
      typedef shared_ptr<Pieces>    PiecePtr;
      typedef shared_ptr<BaseState> StatePtr;
      
      //-- construction
      inline BaseState( GameState& gameState )
        : gameState_(gameState)
      { }

      //-- interface methods
      virtual StatePtr execute( ) = 0;

      //-- accessors
      void setTransitionStates( StatePtr nextState, StatePtr returnState );
      void setWhiteKing( PiecePtr whiteKing ) { whiteKing_ = whiteKing; }
      void setBlackKing( PiecePtr blackKing ) { blackKing_ = blackKing; }

    protected:
      //-- protected types
      GameState& gameState_;
      StatePtr nextState_ ;
      StatePtr returnState_ ;
      PiecePtr whiteKing_ ;
      PiecePtr blackKing_ ;
      bool     active_ ;
      int      runs_ ;
      int      returns_ ;
      int      nexts_ ;
    };

  }
}

#endif /* CHESS_STATE_BASESTATE_H_ */
