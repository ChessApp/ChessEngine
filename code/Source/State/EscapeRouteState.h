#ifndef CHESS_STATE_ESCAPEROUTESTATE_H_
#define CHESS_STATE_ESCAPEROUTESTATE_H_

#include "Chess.h"
#include "State/BaseState.h"


namespace Chess
{
  namespace State
  {

    class EscapeRouteState
      : public BaseState
    {
    public:
      //-- types

      //-- construction
      inline EscapeRouteState( GameState& gameState )
        : BaseState(gameState, "EscapeRouteState")
      { }

      //-- BaseState interface
      virtual StatePtr executeImpl();

    protected:
      //-- protected methods

      //-- protected members
    };

  }
}

#endif /* CHESS_STATE_ESCAPEROUTESTATE_H_ */
