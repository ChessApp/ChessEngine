#ifndef CHESS_STATE_MOVEVALIDITYSTATE_H_
#define CHESS_STATE_MOVEVALIDITYSTATE_H_

#include "Chess.h"

#include "State/BaseState.h"
#include "Board.h"
#include "Interface.h"


namespace Chess
{
  namespace State
  {

    class MoveValidityState
      : public BaseState
    {
    public:
      //-- types
      typedef shared_ptr<Interface> InterfacePtr;
      typedef shared_ptr<Board>     BoardPtr;

      //-- construction
      inline MoveValidityState( InterfacePtr interface, BoardPtr board ) 
        : interface_(interface),
          board_(board)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );
      
    protected:
      //-- protected methods
      void updateGameState();

      //-- protected members
      InterfacePtr interface_;
      BoardPtr     board_;
    };

  }
}

#endif /* CHESS_STATE_MOVEVALIDITYSTATE_H_ */
