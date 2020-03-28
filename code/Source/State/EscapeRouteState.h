#ifndef CHESS_STATE_ESCAPEROUTESTATE_H_
#define CHESS_STATE_ESCAPEROUTESTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "BaseTurn.h"
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
      //-- construction
      inline EscapeRouteState( 
        Interface * interface, 
        Board * board, 
        BaseTurn *& currentTurn ) 
        : interface_(interface),
          board_(board),
          currentTurn_(currentTurn)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );

    protected:
      //-- protected methods
      void setPiece( Pieces * pieceToSet, int rowToSet, int colToSet );
      void returnPiece( Pieces * pieceToReturn, int rowToReturn, int colToReturn );
      void configureScans( Pieces * kingToScan );
      bool executeScans( Pieces * kingToEscape );

      //-- protected members
      Interface *              interface_;
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

#endif /* CHESS_STATE_ESCAPEROUTESTATE_H_ */
