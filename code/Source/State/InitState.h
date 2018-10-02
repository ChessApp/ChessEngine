#ifndef INITSTATE_H_
#define INITSTATE_H_

#include <string>
#include <sstream>
#include <vector>

#include "BaseState.h"
#include "../Board.h"
#include "../Interface.h"

#include "../Pieces/Pieces.h"
#include "../Pieces/NullPiece.h"
#include "../Pieces/Rook.h"
#include "../Pieces/Knight.h"
#include "../Pieces/Bishop.h"
#include "../Pieces/Queen.h"
#include "../Pieces/King.h"
#include "../Pieces/Pawn.h"
#include "../StandardInitialPieceLocations.h"


namespace Chess
{
  namespace State
  {

    class InitState
      : public BaseState
    {
    public:
      virtual BaseState * execute( ) ;

      inline InitState ( 
        Interface * interface,
        Board * board )
        : interface_(interface),
          board_(board)
      { }
      // inline InitState ( BaseState * nextState )
      //   : BaseState( nextState )
      // { }
      
      // virtual void updateDiagnostics( ) ;

      protected:
        void setPiece( Pieces * pieceToSet, int rowToSet, int colToSet ) ;

        Interface * interface_ ;
        Board * board_ ;

    };

  }
}

#endif /* INITSTATE_H_ */