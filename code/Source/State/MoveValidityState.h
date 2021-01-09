#ifndef CHESS_STATE_MOVEVALIDITYSTATE_H_
#define CHESS_STATE_MOVEVALIDITYSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"


namespace Chess
{
  namespace State
  {

    class MoveValidityState
      : public BaseState
    {
    public:
      //-- types

      //-- construction
      inline MoveValidityState( GameState& gameState ) 
        : BaseState("MoveValidityState", gameState)
      { }

      //-- BaseState interface
      virtual StatePtr executeImpl() override;
      
    protected:
      //-- protected methods

      //-- protected members
    };

  }
}

#endif /* CHESS_STATE_MOVEVALIDITYSTATE_H_ */
