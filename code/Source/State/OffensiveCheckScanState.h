#ifndef CHESS_STATE_OFFENSIVECHECKSCANSTATE_H_
#define CHESS_STATE_OFFENSIVECHECKSCANSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"


namespace Chess
{
  namespace State
  {

    class OffensiveCheckScanState
      : public BaseState
    {
    public:
      //-- types

      //-- construction
      inline OffensiveCheckScanState( GameState& gameState ) 
        : BaseState(gameState, "OffensiveCheckScanState")
      { }

      //-- BaseState interface
      virtual StatePtr executeImpl();
      
    protected:
      //-- protected methods

      //-- protected members
    };

  }
}

#endif /* CHESS_STATE_OFFENSIVECHECKSCANSTATE_H_ */
