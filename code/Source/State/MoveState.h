#ifndef CHESS_STATE_MOVESTATE_H_
#define CHESS_STATE_MOVESTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "Interface.h"
#include "Board.h"


namespace Chess
{
  namespace State
  {

    class MoveState
      : public BaseState
    {
    public:
      //-- construction
      inline MoveState ( Interface * interface, Board * board ) 
        : interface_(interface),
          board_(board)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );

    protected:
      //-- protected methods
      void setPiece( Pieces * pieceToSet, int rowToSet, int colToSet );

      //-- protected members
      Interface * interface_;
      Board *     board_;

    };

  }
}

#endif /* CHESS_STATE_MOVESTATE_H_ */
