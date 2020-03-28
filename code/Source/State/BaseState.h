#ifndef CHESS_STATE_BASESTATE_H_
#define CHESS_STATE_BASESTATE_H_

#include "Chess.h"
#include "Pieces/Pieces.h"


namespace Chess
{
  namespace State
  {

    class BaseState
    {
    public:
      //-- types
      typedef Pieces *              PiecePtr;
      typedef shared_ptr<BaseState> StatePtr;
      
      //-- construction
      inline BaseState ( )
      { }

      //-- interface methods
      virtual StatePtr execute( ) = 0;

      //-- accessors
      void setTransitionStates( StatePtr nextState, StatePtr returnState );
      void setWhiteKing( Pieces * whiteKing ) { whiteKing_ = whiteKing; }
      void setBlackKing( Pieces * blackKing ) { blackKing_ = blackKing; }

    protected:
      //-- protected types
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
