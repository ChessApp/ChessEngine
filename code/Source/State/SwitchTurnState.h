#ifndef CHESS_STATE_SWITCHTURNSTATE_H_
#define CHESS_STATE_SWITCHTURNSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "BaseTurn.h"
#include "Interface.h"


namespace Chess
{
  namespace State
  {

    class SwitchTurnState
      : public BaseState
    {
    public:
      //-- construction
      inline SwitchTurnState( 
        Interface * interface,
        BaseTurn * whiteTurn,
        BaseTurn * blackTurn,
        BaseTurn *& currentTurn ) 
        : interface_(interface),
          whiteTurn_(whiteTurn),
          blackTurn_(blackTurn),
          currentTurn_(currentTurn)      
      { }

      //-- BaseState interface
      virtual StatePtr execute( );
      
    protected:
      //-- protected members
      Interface * interface_;
      BaseTurn *& currentTurn_;
      BaseTurn *  whiteTurn_;
      BaseTurn *  blackTurn_;
    };

  }
}

#endif /* CHESS_STATE_SWITCHTURNSTATE_H_ */
