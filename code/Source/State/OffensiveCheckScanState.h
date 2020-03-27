#ifndef OFFENSIVECHECKSCANSTATE_H_
#define OFFENSIVECHECKSCANSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "PotentialPin.h"
#include "BaseTurn.h"
#include "Scans/Scanner.h"
#include "Interface.h"
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

      typedef vector< PotentialPin * > & PotentialPinList ;
      typedef vector< Pieces * > & PieceList ;

      virtual StatePtr execute( ) ;

      inline OffensiveCheckScanState ( 
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

#endif /* OFFENSIVECHECKSCANSTATE_H_ */