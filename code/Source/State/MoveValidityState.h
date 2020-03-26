#ifndef MOVEVALIDITYSTATE_H_
#define MOVEVALIDITYSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "Interface.h"
#include "Board.h"
#include "Pieces/Pieces.h"


namespace Chess
{
  namespace State
  {

    class MoveValidityState
      : public BaseState
    {
    public:
      virtual BaseState * execute( ) ;

      inline MoveValidityState ( Interface * interface, Board * board ) 
        : interface_(interface),
          board_(board)
      { }
      
    protected:
      Interface * interface_ ;
      Board *     board_ ;

    };

  }
}

#endif /* MOVEVALIDITYSTATE_H_ */