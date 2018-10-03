#include "InitState.h"

namespace Chess
{
  namespace State
  {

    BaseState * InitState::execute ( )
    {
      std::cout << "Init state" << std::endl ;

      vector< Pieces * > nullPieceList ;
      for ( int j = 0; j < 8; j++ )
      {
        for ( int i = 0; i < 8; i++ )
        {
          Pieces * np = new NullPiece( ".. ", board_ ) ;
          setPiece( np, j, i ) ;
          nullPieceList.push_back( np ) ;
        }  
      }

      board_->init( nullPieceList ) ;

      Pieces * wr1 = new Chess::Rook ( "WR ", board_ ) ;
      Pieces * wr2 = new Chess::Rook ( "WR ", board_ ) ;
      Pieces * br1 = new Chess::Rook ( "BR ", board_ ) ;
      Pieces * br2 = new Chess::Rook ( "BR ", board_ ) ;
      Pieces * wb1 = new Chess::Bishop ( "WB ", board_ ) ;
      Pieces * wb2 = new Chess::Bishop ( "WB ", board_ ) ;
      Pieces * bb1 = new Chess::Bishop ( "BB ", board_ ) ;
      Pieces * bb2 = new Chess::Bishop ( "BB ", board_ ) ;
      Pieces * wn1 = new Chess::Knight ( "WN ", board_ ) ;
      Pieces * wn2 = new Chess::Knight ( "WN ", board_ ) ;
      Pieces * bn1 = new Chess::Knight ( "BN ", board_ ) ;
      Pieces * bn2 = new Chess::Knight ( "BN ", board_ ) ;
      Pieces * wp1 = new Chess::WhitePawn ( "WP ", board_ ) ;
      Pieces * wp2 = new Chess::WhitePawn ( "WP ", board_ ) ;
      Pieces * wp3 = new Chess::WhitePawn ( "WP ", board_ ) ;
      Pieces * wp4 = new Chess::WhitePawn ( "WP ", board_ ) ;
      Pieces * wp5 = new Chess::WhitePawn ( "WP ", board_ ) ;
      Pieces * wp6 = new Chess::WhitePawn ( "WP ", board_ ) ;
      Pieces * wp7 = new Chess::WhitePawn ( "WP ", board_ ) ;
      Pieces * wp8 = new Chess::WhitePawn ( "WP ", board_ ) ;
      Pieces * bp1 = new Chess::BlackPawn ( "BP ", board_ ) ;
      Pieces * bp2 = new Chess::BlackPawn ( "BP ", board_ ) ;
      Pieces * bp3 = new Chess::BlackPawn ( "BP ", board_ ) ;
      Pieces * bp4 = new Chess::BlackPawn ( "BP ", board_ ) ;
      Pieces * bp5 = new Chess::BlackPawn ( "BP ", board_ ) ;
      Pieces * bp6 = new Chess::BlackPawn ( "BP ", board_ ) ;
      Pieces * bp7 = new Chess::BlackPawn ( "BP ", board_ ) ;
      Pieces * bp8 = new Chess::BlackPawn ( "BP ", board_ ) ;
      Pieces * wq  = new Chess::Queen ( "WQ ", board_ ) ;
      Pieces * bq  = new Chess::Queen ( "BQ ", board_ ) ;
      Pieces * wk  = new Chess::King ( "WK ", board_ ) ;
      Pieces * bk  = new Chess::King ( "BK ", board_ ) ;

      

      setPiece (wr1, 7, 0) ;
      setPiece (wr2, 7, 7) ;
      setPiece (br1, 0, 0) ;
      setPiece (br2, 0, 7) ;
      setPiece (wb1, 7, 2) ;
      setPiece (wb2, 7, 5) ;
      setPiece (bb1, 0, 2) ;
      setPiece (bb2, 0, 5) ;
      setPiece (wn1, 7, 1) ;
      setPiece (wn2, 7, 6) ;
      setPiece (bn1, 0, 1) ;
      setPiece (bn2, 0, 6) ;
      // setPiece (wp1, 6, 0) ;
      setPiece (wp2, 6, 1) ;
      setPiece (wp3, 6, 2) ;
      setPiece (wp4, 6, 3) ;
      setPiece (wp5, 6, 4) ;
      setPiece (wp6, 6, 5) ;
      setPiece (wp7, 6, 6) ;
      setPiece (wp8, 6, 7) ;
      setPiece (bp1, 1, 0) ;
      setPiece (bp2, 1, 1) ;
      setPiece (bp3, 1, 2) ;
      setPiece (bp4, 1, 3) ;
      setPiece (bp5, 1, 4) ;
      setPiece (bp6, 1, 5) ;
      setPiece (bp7, 1, 6) ;
      setPiece (bp8, 1, 7) ;
      setPiece (wq , 7, 3) ;
      setPiece (bq , 0, 3) ;
      setPiece (wk , 7, 4) ;
      setPiece (bk , 0, 4) ;

      
      interface_->printBoard( ) ;

      return nextState_ ;
    }

    void InitState::setPiece( Pieces * pieceToSet, int rowToSet, int colToSet )
    {
      pieceToSet->setLocation( rowToSet, colToSet ) ;
      board_->setPiece( pieceToSet, rowToSet, colToSet ) ;
    }

  }
}