#include "Board.h"


namespace Chess
{

  Board::Board ( )
  {
    // Chess::NullPiece * nullpiece = new Chess::NullPiece ( ".. ", this ) ;
 
  }

  void Board::init ( vector< Pieces * > & pieceList, Pieces * nullpiece )
  {
    pieceList_ = pieceList ;
    nullpiece_ = nullpiece ;

    for ( int j = 6; j <= MAX_ROW; j++ )
    {
      for ( int i = 0; i <= MAX_COLUMN; i++ )
      {
        
        if( pieceList.size() )
        {
          board[j][i] = pieceList.back( ) ;
          pieceList.pop_back( ) ;
        }
        
      }
    }

    if ( pieceList.size() )
    {
      for ( int j = 2; j <= 5; j++ )
      {
        for ( int i = 0; i <= MAX_COLUMN; i++ )
        {
          pieceList.back( ) ;
        }
      }
      pieceList.pop_back( ) ;
    }

    for ( int j = 0; j <= 1; j++ )
    {
      for ( int i = 0; i <= MAX_COLUMN; i++ )
      {
        
        if( pieceList.size() )
        {
          board[j][i] = pieceList.back( ) ;
          pieceList.pop_back( ) ;
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