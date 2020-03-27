#ifndef BASESTATE_H_
#define BASESTATE_H_

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
      typedef Pieces * PiecePtr;
      typedef shared_ptr<BaseState> StatePtr;
      
      inline BaseState ( )
      { }

      virtual void setTransitionStates ( StatePtr nextState, StatePtr returnState ) ;
      virtual StatePtr execute( ) = 0 ;
      void setWhiteKing( Pieces * whiteKing ) { whiteKing_ = whiteKing ; }
      void setBlackKing( Pieces * blackKing ) { blackKing_ = blackKing ; }
      // virtual void updateDiagnostics( ) ;

    protected:

      StatePtr nextState_ ;
      StatePtr returnState_ ;
      Pieces * whiteKing_ ;
      Pieces * blackKing_ ;
      bool active_ ;
      int runs_ ;
      int returns_ ;
      int nexts_ ;
    };

  }
}

#endif /* BASESTATE_H_ */