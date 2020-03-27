#ifndef INITSTATE_H_
#define INITSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "Board.h"
#include "Interface.h"
#include "BaseTurn.h"

#include "Pieces/Pieces.h"
#include "Pieces/NullPiece.h"
#include "Pieces/Rook.h"
#include "Pieces/Knight.h"
#include "Pieces/Bishop.h"
#include "Pieces/Queen.h"
#include "Pieces/King.h"
#include "Pieces/WhitePawn.h"
#include "Pieces/BlackPawn.h"
#include "StandardInitialPieceLocations.h"


namespace Chess
{
  namespace State
  {

    class InitState
      : public BaseState
    {
    public:

      virtual StatePtr execute( ) ;

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
      // inline InitState ( BaseState * nextState )
      //   : BaseState( nextState )
      // { }
      
      // virtual void updateDiagnostics( ) ;

      protected:
        //-- protected methods
        void setPiece( PiecePtr pieceToSet, int rowToSet, int colToSet ) ;
        void parseXMLFile();

        Interface * interface_ ;
        Board * board_ ;
        BaseTurn * whiteTurn_ ;
        BaseTurn * blackTurn_ ;
        BaseTurn *& currentTurn_ ;
        const char * configFileName_;

    };

  }
}

#endif /* INITSTATE_H_ */