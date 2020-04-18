#ifndef CHESS_STATE_CHECKMATESTATE_H_
#define CHESS_STATE_CHECKMATESTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "Interface.h"
#include "BaseTurn.h"


namespace Chess
{
  namespace State
  {

    class CheckmateState
      : public BaseState
    {
    public:
      //-- types
      typedef shared_ptr<Interface> InterfacePtr;
      typedef shared_ptr<BaseTurn>  BaseTurnPtr;

      //-- construction
      inline CheckmateState( InterfacePtr interface, BaseTurnPtr & currentTurn ) 
        : interface_(interface),
          currentTurn_(currentTurn)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );
 
    protected:
      //-- protected methods
      void updateGameState( );

      //-- protected members
      InterfacePtr  interface_;
      BaseTurnPtr & currentTurn_;
    };

  }
}

#endif /* CHESS_STATE_CHECKMATESTATE_H_ */
