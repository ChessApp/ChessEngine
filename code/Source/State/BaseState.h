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
      
      inline BaseState ( )
      { }

      virtual void setTransitionStates ( BaseState * nextState, BaseState * returnState ) ;
      virtual BaseState * execute( ) = 0 ;
      void setWhiteKing( Pieces * whiteKing ) { whiteKing_ = whiteKing ; }
      void setBlackKing( Pieces * blackKing ) { blackKing_ = blackKing ; }
      // virtual void updateDiagnostics( ) ;

    protected:

      BaseState * nextState_ ;
      BaseState * returnState_ ;
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