#ifndef CHESS_STATE_SWITCHTURNSTATE_H_
#define CHESS_STATE_SWITCHTURNSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"


namespace Chess
{
  namespace State
  {

    class SwitchTurnState
      : public BaseState
    {
    public:
      //-- types

      //-- construction
      inline SwitchTurnState( GameState& gameState )
        : BaseState(gameState, "SwitchTurnState")  
      { }

      //-- BaseState interface
      virtual StatePtr executeImpl();
      
    protected:
      //-- protected methods

      //-- protected members
    };

  }
}

#endif /* CHESS_STATE_SWITCHTURNSTATE_H_ */
