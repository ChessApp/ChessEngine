#ifndef DEFENSIVECHECKSCANSTATE_H_
#define DEFENSIVECHECKSCANSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "BaseTurn.h"
#include "Scans/Scanner.h"
#include "Interface.h"
#include "Board.h"
#include "Pieces/Pieces.h"


namespace Chess
{
  namespace State
  {

    class DefensiveCheckScanState
      : public BaseState
    {
    public:
      virtual StatePtr execute( ) ;

      inline DefensiveCheckScanState ( 
        Interface * interface, 
        Board * board, 
        BaseTurn *& currentTurn ) 
        : interface_(interface),
          board_(board),
          currentTurn_(currentTurn)
      { }
      void configureScans( Pieces * kingToScan ) ;
      
    protected:
      Interface * interface_ ;
      Board *     board_ ;
      BaseTurn *& currentTurn_ ;
      vector< BaseScan * > scanList_ ;
      Scanner::LeftScan * ls_ ;
      Scanner::RightScan * rs_ ;
      Scanner::UpScan * us_ ;
      Scanner::DownScan * ds_ ;
      Scanner::UpLeftScan * uls_ ;
      Scanner::UpRightScan * urs_ ;
      Scanner::DownLeftScan * dls_ ;
      Scanner::DownRightScan * drs_ ;
      bool status_ ;

    };

  }
}

#endif /* DEFENSIVECHECKSCANSTATE_H_ */