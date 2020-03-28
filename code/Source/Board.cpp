#include "Board.h"


namespace Chess
{

  Board::Board( )
  { }

  void Board::init( PieceList & nullPieceList )
  { }

  void Board::setPiece( PiecePtr setPiece, int row, int col )
  {
    board[row][col] = setPiece;
  }

  void Board::clrPiece( int row, int col )
  {
    PiecePtr pieceToClr = board[row][col];

    if( pieceToClr != NULL )
      board[row][col] = NULL;
  }

  Board::PiecePtr Board::getPiece( int row, int col )
  {
    return board[row][col];
  }

  string Board::getPieceName ( int row, int col )
  {
    if( board[row][col] != NULL )
      return (board[row][col])->getName();
    else
      return ".. ";
  }
 
}
