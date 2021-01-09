#ifndef CHESS_STATE_FINISHSTATE_H_
#define CHESS_STATE_FINISHSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "GameState.h"


namespace Chess
{
  namespace State
  {

    class FinishState
      : public BaseState
    {
    public:
      //-- types

      //-- construction
      inline FinishState( GameState& gameState )
        : BaseState("FinishState", gameState)
      { }

      //-- BaseState interface
      virtual StatePtr executeImpl() override;

    protected:
      //-- protected methods

      //-- protected members
    };

  }
}

#endif /* CHESS_STATE_FINISHSTATE_H_ */
