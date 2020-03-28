#ifndef CHESS_STATE_INITSTATE_H_
#define CHESS_STATE_INITSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "Board.h"
#include "Interface.h"
#include "BaseTurn.h"


namespace Chess
{
  namespace State
  {

    class InitState
      : public BaseState
    {
    public:
      //-- construction
      inline InitState ( 
        const char * configFileName,
        Interface * interface,
        Board * board,
        BaseTurn * whiteTurn,
        BaseTurn * blackTurn,
        BaseTurn *& currentTurn )
        : interface_(interface),
          board_(board),
          whiteTurn_(whiteTurn),
          blackTurn_(blackTurn),
          currentTurn_(currentTurn),
          configFileName_(configFileName)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );

    protected:
      //-- protected methods
      void setPiece( PiecePtr pieceToSet, int rowToSet, int colToSet );
      void parseXMLFile( );

      //-- protected members
      Interface *   interface_;
      Board *       board_;
      BaseTurn *    whiteTurn_;
      BaseTurn *    blackTurn_;
      BaseTurn *&   currentTurn_;
      const char *  configFileName_;
    };

  }
}

#endif /* CHESS_STATE_INITSTATE_H_ */
