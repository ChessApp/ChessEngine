#ifndef BLOCKSCANSTATE_H_
#define BLOCKSCANSTATE_H_

#include <string>
#include <sstream>
#include <vector>

#include "BaseState.h"
#include "../PotentialPin.h"
#include "../BaseTurn.h"
#include "../Scans/Scanner.h"
#include "../Interface.h"
#include "../Board.h"
#include "../Pieces/Pieces.h"

namespace Chess
{
  namespace State
  {

    class BlockScanState
      : public BaseState
    {
    public:

      typedef vector< PotentialPin * > & PotentialPinList ;
      typedef vector< Pieces * > & PieceList ;

      virtual BaseState * execute( ) ;

      inline BlockScanState ( 
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

#endif /* BLOCKSCANSTATE_H_ */