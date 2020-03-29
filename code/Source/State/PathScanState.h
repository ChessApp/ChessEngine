#ifndef CHESS_STATE_PATHSCANSTATE_H_
#define CHESS_STATE_PATHSCANSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "Interface.h"
#include "Board.h"


namespace Chess
{
  namespace State
  {

    class PathScanState
      : public BaseState
    {
    public:
      //-- types
      typedef shared_ptr<Interface> InterfacePtr;
      typedef shared_ptr<Board>     BoardPtr;

      //-- construction
      inline PathScanState( InterfacePtr interface, BoardPtr board ) 
        : interface_(interface),
          board_(board)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );
      
    protected:
      //-- protected members
      InterfacePtr interface_;
      BoardPtr     board_;
    };

  }
}

#endif /* CHESS_STATE_PATHSCANSTATE_H_ */
