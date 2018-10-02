#include "InitState.h"

namespace Chess
{
  namespace State
  {

    BaseState * InitState::execute ( )
    {
      std::cout << "Init state" << std::endl ;

      pieceList.push_back( new Rook( "WR ", board_, WR2_ROW, WR2_COL ) ) ;
      pieceList.push_back( new Knight( "WR ", board_, WN2_ROW, WN2_COL ) ) ;
      pieceList.push_back( new Bishop( "WB ", board_, WB2_ROW, WB2_COL ) ) ;
      pieceList.push_back( new King( "WK ", board_, WK_ROW, WK_COL ) ) ;
      pieceList.push_back( new Queen( "WQ ", board_, WQ_ROW, WQ_COL ) ) ;
      pieceList.push_back( new Bishop( "WB ", board_, WB1_ROW, WB1_COL ) ) ;
      pieceList.push_back( new Knight( "WN ", board_, WN1_ROW, WN1_COL ) ) ;
      pieceList.push_back( new Rook( "WR ", board_, WR1_ROW, WR1_COL ) ) ;
      for ( int i = 7; i >= 0; i-- )
      {
        pieceList.push_back( new Pawn( "WP ", board_, WP_ROW, i ) ) ;
      }

      pieceList.push_back( new NullPiece( ".. ", board_ ) ) ;

      pieceList.push_back( new Rook( "BR ", board_, BR2_ROW, BR2_COL ) ) ;
      pieceList.push_back( new Knight( "BR ", board_, BN2_ROW, BN2_COL ) ) ;
      pieceList.push_back( new Bishop( "BB ", board_, BB2_ROW, BB2_COL ) ) ;
      pieceList.push_back( new King( "BK ", board_, BK_ROW, BK_COL ) ) ;
      pieceList.push_back( new Queen( "BQ ", board_, BQ_ROW, BQ_COL ) ) ;
      pieceList.push_back( new Bishop( "BB ", board_, BB1_ROW, BB1_COL ) ) ;
      pieceList.push_back( new Knight( "BN ", board_, BN1_ROW, BN1_COL ) ) ;
      pieceList.push_back( new Rook( "BR ", board_, BR1_ROW, BR1_COL ) ) ;
      for ( int i = 7; i >= 0; i-- )
      {
        pieceList.push_back( new Pawn( "BP ", board_, BP_ROW, i ) ) ;
      }

      board_->init( pieceList, new NullPiece( ".. ", board_ ) ) ;
      interface_->printBoard( ) ;

      return nextState_ ;
    }

  }
}