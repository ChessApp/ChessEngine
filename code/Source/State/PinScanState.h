#ifndef PINSCANSTATE_H_
#define PINSCANSTATE_H_

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

    class PinScanState
      : public BaseState
    {
    public:

      typedef vector< PotentialPin * > & PotentialPinList ;
      typedef vector< Pieces * > & PieceList ;

      virtual BaseState * execute( ) ;

      inline PinScanState ( 
        Interface * interface, 
        Board * board, 
        BaseTurn *& currentTurn ) 
        : interface_(interface),
          board_(board),
          currentTurn_(currentTurn)
      { }
      
    protected:
      void removePiece( Pieces * pieceToRemove ) ;
      void returnPiece( Pieces * pieceToReturn ) ;

      Interface * interface_ ;
      Board *     board_ ;
      BaseTurn *& currentTurn_ ;
      

    };

  }
}

#endif /* PINSCANSTATE_H_ */