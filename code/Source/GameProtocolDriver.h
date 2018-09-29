
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