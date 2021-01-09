#include "Board.h"

#include <memory>

#include "Pieces/NullPiece.h"


namespace Chess
{

  Board::Board()
    : board_(8, vector<PiecePtr>(8, std::make_shared<Pieces>(NullPiece(".. "))))
  { }


  void Board::setPiece( PiecePtr setPiece, int row, int col )
  {
    board_[row][col] = setPiece;
  }

  void Board::clrPiece( int row, int col )
  {
    PiecePtr pieceToClr = board_[row][col];

    if( pieceToClr != NULL )
      board_[row][col] = NULL;
  }

  Board::PiecePtr Board::getPiece( int row, int col )
  {
    return board_[row][col];
  }

  string Board::getPieceName ( int row, int col )
  {
    if( board_[row][col] != NULL )
      return (board_[row][col])->getName();
    else
      return ".. ";
  }
 
}
