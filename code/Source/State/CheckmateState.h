#ifndef CHESS_STATE_CHECKMATESTATE_H_
#define CHESS_STATE_CHECKMATESTATE_H_

#include "Chess.h"
#include "State/BaseState.h"


namespace Chess
{
  namespace State
  {

    class CheckmateState
      : public BaseState
    {
    public:
      //-- types

      //-- construction
      inline CheckmateState( GameState& gameState ) 
        : BaseState(gameState, "CheckmateState")
      { }

      //-- BaseState interface
      virtual StatePtr executeImpl();
 
    protected:
      //-- protected methods

      //-- protected members
    };

  }
}

#endif /* CHESS_STATE_CHECKMATESTATE_H_ */
