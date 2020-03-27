#ifndef ESCAPEROUTESTATE_H_
#define ESCAPEROUTESTATE_H_

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

    class EscapeRouteState
      : public BaseState
    {
    public:

      typedef vector< Pieces * > & PinList ;

      virtual StatePtr execute( ) ;

      inline EscapeRouteState ( 
        Interface * interface, 
        Board * board, 
        BaseTurn *& currentTurn ) 
        : interface_(interface),
          board_(board),
          currentTurn_(currentTurn)
      { }
      
    protected:
      void setPiece( Pieces * pieceToSet, int rowToSet, int colToSet ) ;
      void returnPiece( Pieces * pieceToReturn, int rowToReturn, int colToReturn ) ;
      void configureScans( Pieces * kingToScan ) ;
      bool executeScans( Pieces * kingToEscape ) ;

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

#endif /* ESCAPEROUTESTATE_H_ */