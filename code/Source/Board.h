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
    Board();

    //-- public methods
    void     setPiece( PiecePtr piece, const pair<int,int>& destination );
    void     clrPiece( PiecePtr piece );
    PiecePtr getPiece( const pair<int,int>& location );

  private:
    //-- protected methods

    //-- protected members
    std::unordered_map<string, PiecePtr> board_;
  };

}

#endif /* CHESS_BOARD_H_ */
