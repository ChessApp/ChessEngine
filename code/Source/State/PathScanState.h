#ifndef PATHSCANSTATE_H_
#define PATHSCANSTATE_H_

#include <sstream>
#include <vector>

#include "Chess.h"
#include "State/BaseState.h"
#include "Interface.h"
#include "Board.h"
#include "Pieces/Pieces.h"


namespace Chess
{
  namespace State
  {

    class PathScanState
      : public BaseState
    {
    public:
      virtual StatePtr execute( ) ;

      inline PathScanState ( Interface * interface, Board * board ) 
        : interface_(interface),
          board_(board)
      { }
      
    protected:
      Interface * interface_ ;
      Board *     board_ ;

    };

  }
}

#endif /* PATHSCANSTATE_H_ */