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
      typedef Interface * InterfacePtr;

      //-- construction
      inline MoveValidityState( InterfacePtr interface, Board * board ) 
        : interface_(interface),
          board_(board)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );
      
    protected:
      //-- protected members
      Board *      board_;
      InterfacePtr interface_;
    };

  }
}

#endif /* CHESS_STATE_MOVEVALIDITYSTATE_H_ */
