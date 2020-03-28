#ifndef CHESS_STATE_OFFENSIVECHECKSCANSTATE_H_
#define CHESS_STATE_OFFENSIVECHECKSCANSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "PotentialPin.h"
#include "BaseTurn.h"
#include "Scans/Scanner.h"
#include "Board.h"
#include "Pieces/Pieces.h"


namespace Chess
{
  namespace State
  {

    class OffensiveCheckScanState
      : public BaseState
    {
    public:
      //-- types
      typedef PotentialPin *            PotentialPinPtr;
      typedef Pieces *                  PiecePtr;
      typedef vector<PotentialPinPtr> & PotentialPinList;
      typedef vector<PiecePtr> &        PieceList;

      //-- construction
      inline OffensiveCheckScanState( 
        Board * board, 
        BaseTurn *& currentTurn ) 
        : board_(board),
          currentTurn_(currentTurn)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );
      
    protected:
      //-- protected methods
      void configureScans( Pieces * kingToScan );

      //-- protected members
      Board *     board_;
      BaseTurn *& currentTurn_;
      vector< BaseScan * > scanList_;
      Scanner::LeftScan * ls_;
      Scanner::RightScan * rs_;
      Scanner::UpScan * us_;
      Scanner::DownScan * ds_;
      Scanner::UpLeftScan * uls_;
      Scanner::UpRightScan * urs_;
      Scanner::DownLeftScan * dls_;
      Scanner::DownRightScan * drs_;
      bool status_;
    };

  }
}

#endif /* CHESS_STATE_OFFENSIVECHECKSCANSTATE_H_ */
