#ifndef CHESS_STATE_ESCAPEROUTESTATE_H_
#define CHESS_STATE_ESCAPEROUTESTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "BaseTurn.h"
#include "Scans/BaseScan.h"
#include "Scans/Scanner.h"
#include "Interface.h"
#include "Board.h"


namespace Chess
{
  namespace State
  {

    class EscapeRouteState
      : public BaseState
    {
    public:
      //-- types
      typedef shared_ptr<Interface> InterfacePtr;
      typedef shared_ptr<Board>     BoardPtr;
      typedef shared_ptr<BaseTurn>  BaseTurnPtr;
      typedef shared_ptr<BaseScan>  BaseScanPtr;

      //-- construction
      inline EscapeRouteState( 
        InterfacePtr interface, 
        BoardPtr board, 
        BaseTurnPtr & currentTurn ) 
        : interface_(interface),
          board_(board),
          currentTurn_(currentTurn)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );

    protected:
      //-- protected methods
      void setPiece( PiecePtr pieceToSet, int rowToSet, int colToSet );
      void returnPiece( PiecePtr pieceToReturn, int rowToReturn, int colToReturn, PiecePtr originalPiece );
      void configureScans( PiecePtr kingToScan );
      bool executeScans( PiecePtr kingToEscape );

      //-- protected members
      InterfacePtr         interface_;
      BoardPtr             board_;
      BaseTurnPtr &        currentTurn_;
      vector<BaseScanPtr>  scanList_;
    };

  }
}

#endif /* CHESS_STATE_ESCAPEROUTESTATE_H_ */
