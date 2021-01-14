#ifndef CHESS_STATE_DEFENSIVECHECKSCANSTATE_H_
#define CHESS_STATE_DEFENSIVECHECKSCANSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "GameState.h"


namespace Chess
{
  namespace State
  {

    class DefensiveCheckScanState
      : public BaseState
    {
    public:
      //-- types

      //-- construction
      inline DefensiveCheckScanState( GameState& gameState ) 
        : BaseState(gameState, "DefensiveCheckScanState")
      { }

      //-- BaseState interface
      virtual StatePtr executeImpl();
      
    protected:
      //-- protected methods

      //-- protected members
    };

  }
}

#endif /* CHESS_STATE_DEFENSIVECHECKSCANSTATE_H_ */
