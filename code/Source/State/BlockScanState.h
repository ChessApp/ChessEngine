#ifndef BLOCKSCANSTATE_H_
#define BLOCKSCANSTATE_H_

#include <string>
#include <sstream>
#include <vector>

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

    class BlockScanState
      : public BaseState
    {
    public:

      typedef vector< Pieces * > & PieceList ;

      StatePtr execute( ) ;

      inline BlockScanState ( 
        Interface * interface, 
        Board * board, 
        BaseTurn *& currentTurn ) 
        : interface_(interface),
          board_(board),
          currentTurn_(currentTurn)
      { }
      
    protected:
      Interface * interface_ ;
      Board *     board_ ;
      BaseTurn *& currentTurn_ ;

      bool status_ ;
      ScanResult result_ ;

    };

  }
}

#endif /* BLOCKSCANSTATE_H_ */