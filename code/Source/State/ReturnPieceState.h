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
      //-- types
      typedef shared_ptr<Interface> InterfacePtr;
      typedef shared_ptr<Board>     BoardPtr;

      //-- construction
      inline ReturnPieceState( InterfacePtr interface, BoardPtr board ) 
        : interface_(interface),
          board_(board)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );

    protected:
      //-- protected methods
      void returnPiece( PiecePtr pieceToReturn, int rowToReturn, int colToReturn );

      //-- protected members
      InterfacePtr interface_;
      BoardPtr     board_;
    };

  }
}

#endif /* CHESS_STATE_RETURNPIECESTATE_H_ */
