#ifndef CHESS_STATE_DEFENSIVECHECKSCANSTATE_H_
#define CHESS_STATE_DEFENSIVECHECKSCANSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "BaseTurn.h"
#include "Scans/Scanner.h"
#include "Board.h"


namespace Chess
{
  namespace State
  {

    class DefensiveCheckScanState
      : public BaseState
    {
    public:
      //-- construction
      inline DefensiveCheckScanState( Board * board, BaseTurn *& currentTurn ) 
        : board_(board),
          currentTurn_(currentTurn)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );
      
    protected:
      //-- protected methods
      void configureScans( Pieces * kingToScan );

      //-- protected members
      Board *                  board_;
      BaseTurn *&              currentTurn_;
      vector< BaseScan * >     scanList_;
      Scanner::LeftScan *      ls_;
      Scanner::RightScan *     rs_;
      Scanner::UpScan *        us_;
      Scanner::DownScan *      ds_;
      Scanner::UpLeftScan *    uls_;
      Scanner::UpRightScan *   urs_;
      Scanner::DownLeftScan *  dls_;
      Scanner::DownRightScan * drs_;
      bool                     status_;
    };

  }
}

#endif /* CHESS_STATE_DEFENSIVECHECKSCANSTATE_H_ */
