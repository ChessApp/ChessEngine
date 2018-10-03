#include "Board.h"


namespace Chess
{

  Board::Board ( )
  {
    // Chess::NullPiece * nullpiece = new Chess::NullPiece ( ".. ", this ) ;
 
  }

  void Board::init ( vector< Pieces * > & nullPieceList )
  {

    for ( int j = 0; j <= 7; j++ )
    {
      for ( int i = 0; i <= 7; i++ )
      {
        if ( nullPieceList.size( ) )
        {
          board[j][i] = nullPieceList.back( ) ;
          (board[j][i])->setLocation( j, i ) ;
          nullPieceList.pop_back( ) ;
        }
        else
        {
          std::cout << "Error initializing board." << std::endl ;
        }
      }
    }

  }

  void Board::setPiece ( Pieces * setPiece, int row, int col )
  {
    board[row][col] = setPiece ;
    // setPiece->setLocation( row, col ) ;
  }

  void Board::clrPiece ( int row, int col )
  {
    Pieces * pieceToClr = board[row][col] ;
    if ( pieceToClr != NULL )
    {
      // pieceToClr->clrLocation() ;
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