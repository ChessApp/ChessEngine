#ifndef CHESS_STATE_PINSCANSTATE_H_
#define CHESS_STATE_PINSCANSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "BaseTurn.h"
#include "Board.h"


namespace Chess
{
  namespace State
  {

    class PinScanState
      : public BaseState
    {
    public:
      //-- types
      typedef shared_ptr<Board>     BoardPtr;
      typedef shared_ptr<BaseTurn>  BaseTurnPtr;

      //-- construction
      inline PinScanState( 
        BoardPtr board, 
        BaseTurnPtr & currentTurn ) 
        : board_(board),
          currentTurn_(currentTurn)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );
      
    protected:
      //-- protected methods
      void removePiece( PiecePtr pieceToRemove );
      void returnPiece( PiecePtr pieceToReturn );

      //-- protected members
      BoardPtr      board_;
      BaseTurnPtr & currentTurn_;
    };

  }
}

#endif /* CHESS_STATE_PINSCANSTATE_H_ */
