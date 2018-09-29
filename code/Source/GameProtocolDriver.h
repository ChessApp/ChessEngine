
#ifndef GAMEPROTOCOLDRIVER_H_
#define GAMEPROTOCOLDRIVER_H_

#include <string>
#include <sstream>
#include <vector>

#include "Pieces/Pieces.h"
#include "Pieces/NullPiece.h"
#include "Pieces/Rook.h"
#include "Pieces/Knight.h"
#include "Pieces/Bishop.h"
#include "Pieces/Queen.h"
#include "Pieces/King.h"
#include "Pieces/Pawn.h"
#include "Interface.h"
#include "Board.h"

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


using namespace std;

namespace Chess
{

  class GameProtocolDriver
  {

  public:

   GameProtocolDriver ( ) ;
   // ~GameProtocolDriver( ) ;

   static void moveHandler ( 
     Pieces * pieceToMove, Board * board ) ;

  protected:
    Interface * interface_ ;
    Board * board_ ;

    Chess::Rook * wr1 = NULL ;
    Chess::Rook * wr2 = NULL ;
    Chess::Rook * br1 = NULL ;
    Chess::Rook * br2 = NULL ;
    Chess::Bishop * wb1 = NULL ;
    Chess::Bishop * wb2 = NULL ;
    Chess::Bishop * bb1 = NULL ;
    Chess::Bishop * bb2 = NULL ;
    Chess::Knight * wn1 = NULL ;
    Chess::Knight * wn2 = NULL ;
    Chess::Knight * bn1 = NULL ;
    Chess::Knight * bn2 = NULL ;
    Chess::Pawn * wp1 = NULL ;
    Chess::Pawn * wp2 = NULL ;
    Chess::Pawn * wp3 = NULL ;
    Chess::Pawn * wp4 = NULL ;
    Chess::Pawn * wp5 = NULL ;
    Chess::Pawn * wp6 = NULL ;
    Chess::Pawn * wp7 = NULL ;
    Chess::Pawn * wp8 = NULL ;
    Chess::Pawn * bp1 = NULL ;
    Chess::Pawn * bp2 = NULL ;
    Chess::Pawn * bp3 = NULL ;
    Chess::Pawn * bp4 = NULL ;
    Chess::Pawn * bp5 = NULL ;
    Chess::Pawn * bp6 = NULL ;
    Chess::Pawn * bp7 = NULL ;
    Chess::Pawn * bp8 = NULL ;
    Chess::Queen * wq = NULL ;
    Chess::Queen * bq = NULL ;
    Chess::King * wk  = NULL ;
    Chess::King * bk  = NULL ;

    vector< Pieces * > pieceList ;


  };

}

#endif /* GAMEPROTOCOLDRIVER_H_ */