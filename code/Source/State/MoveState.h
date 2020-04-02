#ifndef CHESS_STATE_MOVESTATE_H_
#define CHESS_STATE_MOVESTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "Interface.h"
#include "Board.h"
#include "BaseTurn.h"


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
      typedef shared_ptr<BaseTurn>  BaseTurnPtr;

      //-- construction
      inline MoveState( InterfacePtr interface, BoardPtr board, BaseTurnPtr & currentTurn ) 
        : interface_(interface),
          board_(board),
          currentTurn_(currentTurn)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );

    protected:
      //-- protected methods
      void setPiece( PiecePtr pieceToSet, int rowToSet, int colToSet );

      //-- protected members
      InterfacePtr  interface_;
      BoardPtr      board_;
      BaseTurnPtr & currentTurn_;
    };

  }
}

#endif /* CHESS_STATE_MOVESTATE_H_ */
