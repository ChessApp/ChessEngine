#ifndef CHESS_STATE_PINSCANSTATE_H_
#define CHESS_STATE_PINSCANSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"


namespace Chess
{
  namespace State
  {

    class PinScanState
      : public BaseState
    {
    public:
      //-- types

      //-- construction
      inline PinScanState( GameState& gameState )
        : BaseState(gameState, "PinScanState")
      { }

      //-- BaseState interface
      virtual StatePtr executeImpl();
      
    protected:
      //-- protected methods

      //-- protected members
    };

  }
}

#endif /* CHESS_STATE_PINSCANSTATE_H_ */
