#ifndef CHESS_BOARD_H_
#define CHESS_BOARD_H_

#include "Chess.h"
#include "Pieces/Pieces.h"


namespace Chess
{

  class Board
  {
  public:
    //-- types
    typedef shared_ptr<Pieces> PiecePtr;
    typedef vector<PiecePtr>   PieceList;

    //-- construction
    Board( );

    //-- public methods
    void     init( PieceList & nullPieceList );
    void     setPiece( PiecePtr setPiece, int row, int col );
    void     clrPiece( int row, int col );
    PiecePtr getPiece( int row, int col );
    string   getPieceName( int row, int col );

  protected:
    //-- protected members
    PiecePtr board[8][8];
  };

}

#endif /* CHESS_BOARD_H_ */
