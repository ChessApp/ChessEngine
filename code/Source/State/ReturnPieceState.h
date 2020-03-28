#ifndef CHESS_STATE_RETURNPIECESTATE_H_
#define CHESS_STATE_RETURNPIECESTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "Interface.h"
#include "Board.h"


namespace Chess
{
  namespace State
  {

    class ReturnPieceState
      : public BaseState
    {
    public:
      //-- construction
      inline ReturnPieceState ( Interface * interface, Board * board ) 
        : interface_(interface),
          board_(board)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );

    protected:
      //-- protected methods
      void returnPiece( Pieces * pieceToReturn, int rowToReturn, int colToReturn );

      //-- protected members
      Interface * interface_;
      Board *     board_;
    };

  }
}

#endif /* CHESS_STATE_RETURNPIECESTATE_H_ */
