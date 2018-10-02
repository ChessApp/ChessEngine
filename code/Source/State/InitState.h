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

#define WR1_ROW 7
#define WR1_COL 0
#define BR1_ROW 0
#define BR1_COL 0
#define WN1_ROW 7
#define WN1_COL 1
#define BN1_ROW 0
#define BN1_COL 1
#define WB1_ROW 7
#define WB1_COL 2
#define BB1_ROW 0
#define BB1_COL 2
#define WR2_ROW 7
#define WR2_COL 7
#define BR2_ROW 0
#define BR2_COL 7
#define WN2_ROW 7
#define WN2_COL 6
#define BN2_ROW 0
#define BN2_COL 6
#define WB2_ROW 7
#define WB2_COL 5
#define BB2_ROW 0
#define BB2_COL 5
#define WK_ROW  7
#define WK_COL  4
#define BK_ROW  0
#define BK_COL  4
#define WQ_ROW  7
#define WQ_COL  3
#define BQ_ROW  0
#define BQ_COL  3
#define WP_ROW  6
#define BP_ROW  1

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
        Interface * interface_ ;
        Board * board_ ;
        vector<Pieces *> pieceList ;

    };

  }
}

#endif /* INITSTATE_H_ */