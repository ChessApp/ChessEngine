#ifndef MOVESTATE_H_
#define MOVESTATE_H_

#include <string>
#include <sstream>
#include <vector>

#include "BaseState.h"
#include "../Interface.h"
#include "../Board.h"
#include "../Pieces/Pieces.h"
#include "../Pieces/NullPiece.h"

namespace Chess
{
  namespace State
  {

    class MoveState
      : public BaseState
    {
    public:
      virtual BaseState * execute( ) ;

      inline MoveState ( Interface * interface, Board * board ) 
        : interface_(interface),
          board_(board)
      { }

      void setPiece( Pieces * pieceToSet, int rowToSet, int colToSet ) ;
      
    protected:
      Interface * interface_ ;
      Board *     board_ ;

    };

  }
}

#endif /* MOVESTATE_H_ */