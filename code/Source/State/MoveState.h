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
      //-- types
      typedef shared_ptr<Interface> InterfacePtr;
      typedef shared_ptr<Board>     BoardPtr;

      //-- construction
      inline MoveState ( InterfacePtr interface, BoardPtr board ) 
        : interface_(interface),
          board_(board)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );

    protected:
      //-- protected methods
      void setPiece( PiecePtr pieceToSet, int rowToSet, int colToSet );

      //-- protected members
      InterfacePtr interface_;
      BoardPtr     board_;
    };

  }
}

#endif /* CHESS_STATE_MOVESTATE_H_ */
