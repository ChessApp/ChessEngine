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
      //-- construction
      inline PathScanState( Interface * interface, Board * board ) 
        : interface_(interface),
          board_(board)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );
      
    protected:
      //-- protected members
      Interface * interface_;
      Board *     board_;
    };

  }
}

#endif /* CHESS_STATE_PATHSCANSTATE_H_ */
