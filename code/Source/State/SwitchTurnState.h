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
      //-- types
      typedef shared_ptr<Interface> InterfacePtr;
      typedef shared_ptr<BaseTurn>  BaseTurnPtr;

      //-- construction
      inline SwitchTurnState( 
        InterfacePtr interface,
        BaseTurnPtr whiteTurn,
        BaseTurnPtr blackTurn,
        BaseTurnPtr & currentTurn ) 
        : interface_(interface),
          whiteTurn_(whiteTurn),
          blackTurn_(blackTurn),
          currentTurn_(currentTurn)      
      { }

      //-- BaseState interface
      virtual StatePtr execute( );
      
    protected:
      //-- protected methods
      void updateGameState();

      //-- protected members
      InterfacePtr  interface_;
      BaseTurnPtr   whiteTurn_;
      BaseTurnPtr   blackTurn_;
      BaseTurnPtr & currentTurn_;
    };

  }
}

#endif /* CHESS_STATE_SWITCHTURNSTATE_H_ */
