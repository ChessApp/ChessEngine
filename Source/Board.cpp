#include "Board.h"


namespace Chess
{

  Board::Board ( )
  {
    Chess::NullPiece * nullpiece = new Chess::NullPiece ( ".. ", this ) ;

    for ( int i = 0; i < 8; i++)
    {
      for ( int j = 0; j < 8; j++)
      {
        board[j][i] = nullpiece ;
      }
    }
  }

  void Board::setPiece ( Pieces * setPiece, int row, int col )
  {
    board[row][col] = setPiece ;
    setPiece->setLocation( row, col ) ;
  }

  void Board::clrPiece ( int row, int col )
  {
    Pieces * pieceToClr = board[row][col] ;
    if ( pieceToClr != NULL )
    {
      pieceToClr->clrLocation() ;
      board[row][col] = NULL ;
    }
    
  }

  Pieces * Board::getPiece ( int row, int col )
  {
    return board[row][col] ;
  }

  string Board::getPieceName ( int row, int col )
  {
    if ( board[row][col] != NULL )
    {
      return (board[row][col])->getName() ;
    }
    else
    {
      return ".. " ;
    }
  }
 
}