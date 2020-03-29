#ifndef CHESS_STATE_OFFENSIVECHECKSCANSTATE_H_
#define CHESS_STATE_OFFENSIVECHECKSCANSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "PotentialPin.h"
#include "BaseTurn.h"
#include "Scans/BaseScan.h"
#include "Scans/Scanner.h"
#include "Board.h"


namespace Chess
{
  namespace State
  {

    class OffensiveCheckScanState
      : public BaseState
    {
    public:
      //-- types
      typedef shared_ptr<Board>     BoardPtr;
      typedef shared_ptr<BaseTurn>  BaseTurnPtr;
      typedef shared_ptr<BaseScan>  BaseScanPtr;

      //-- construction
      inline OffensiveCheckScanState( 
        BoardPtr board, 
        BaseTurnPtr & currentTurn ) 
        : board_(board),
          currentTurn_(currentTurn)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );
      
    protected:
      //-- protected methods
      void configureScans( PiecePtr kingToScan );

      //-- protected members
      BoardPtr           board_;
      BaseTurnPtr &      currentTurn_;
      vector<BaseScanPtr> scanList_;
      bool               status_;
    };

  }
}

#endif /* CHESS_STATE_OFFENSIVECHECKSCANSTATE_H_ */
