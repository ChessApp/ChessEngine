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

      Pieces * wk  = new Chess::King ( "WK ", board_ ) ;
      whiteTurn_->setActivePiece( wk ) ;
      Pieces * bk  = new Chess::King ( "BK ", board_ ) ;
      blackTurn_->setActivePiece( bk ) ;
      Pieces * wr1 = new Chess::Rook ( "WR ", board_ ) ;
      wr1->setKing( wk ) ;
      whiteTurn_->setActivePiece( wr1 ) ;
      Pieces * wr2 = new Chess::Rook ( "WR ", board_ ) ;
      wr2->setKing( wk ) ;
      whiteTurn_->setActivePiece( wr2 ) ;
      Pieces * br1 = new Chess::Rook ( "BR ", board_ ) ;
      br1->setKing( bk ) ;
      blackTurn_->setActivePiece( br1 ) ;
      Pieces * br2 = new Chess::Rook ( "BR ", board_ ) ;
      br2->setKing( bk ) ;
      blackTurn_->setActivePiece( br2 ) ;
      Pieces * wb1 = new Chess::Bishop ( "WB ", board_ ) ;
      wb1->setKing( wk ) ;
      whiteTurn_->setActivePiece( wb1 ) ;
      Pieces * wb2 = new Chess::Bishop ( "WB ", board_ ) ;
      wb2->setKing( wk ) ;
      whiteTurn_->setActivePiece( wb2 ) ;
      Pieces * bb1 = new Chess::Bishop ( "BB ", board_ ) ;
      bb1->setKing( bk ) ;
      blackTurn_->setActivePiece( bb1 ) ;
      Pieces * bb2 = new Chess::Bishop ( "BB ", board_ ) ;
      bb2->setKing( bk ) ;
      blackTurn_->setActivePiece( bb2 ) ;
      Pieces * wn1 = new Chess::Knight ( "WN ", board_ ) ;
      wn1->setKing( wk ) ;
      whiteTurn_->setActivePiece( wn1 ) ;
      Pieces * wn2 = new Chess::Knight ( "WN ", board_ ) ;
      wn2->setKing( wk ) ;
      whiteTurn_->setActivePiece( wn2 ) ;
      Pieces * bn1 = new Chess::Knight ( "BN ", board_ ) ;
      bn1->setKing( bk ) ;
      blackTurn_->setActivePiece( bn1 ) ;
      Pieces * bn2 = new Chess::Knight ( "BN ", board_ ) ;
      bn2->setKing( bk ) ;
      blackTurn_->setActivePiece( bn2 ) ;
      Pieces * wp1 = new Chess::WhitePawn ( "WP ", board_ ) ;
      wp1->setKing( wk ) ;
      whiteTurn_->setActivePiece( wp1 ) ;
      Pieces * wp2 = new Chess::WhitePawn ( "WP ", board_ ) ;
      wp2->setKing( wk ) ;
      whiteTurn_->setActivePiece( wp2 ) ;
      Pieces * wp3 = new Chess::WhitePawn ( "WP ", board_ ) ;
      wp3->setKing( wk ) ;
      whiteTurn_->setActivePiece( wp3 ) ;
      Pieces * wp4 = new Chess::WhitePawn ( "WP ", board_ ) ;
      wp4->setKing( wk ) ;
      whiteTurn_->setActivePiece( wp4 ) ;
      Pieces * wp5 = new Chess::WhitePawn ( "WP ", board_ ) ;
      wp5->setKing( wk ) ;
      whiteTurn_->setActivePiece( wp5 ) ;
      Pieces * wp6 = new Chess::WhitePawn ( "WP ", board_ ) ;
      wp6->setKing( wk ) ;
      whiteTurn_->setActivePiece( wp6 ) ;
      Pieces * wp7 = new Chess::WhitePawn ( "WP ", board_ ) ;
      wp7->setKing( wk ) ;
      whiteTurn_->setActivePiece( wp7 ) ;
      Pieces * wp8 = new Chess::WhitePawn ( "WP ", board_ ) ;
      wp8->setKing( wk ) ;
      whiteTurn_->setActivePiece( wp8 ) ;
      Pieces * bp1 = new Chess::BlackPawn ( "BP ", board_ ) ;
      bp1->setKing( bk ) ;
      blackTurn_->setActivePiece( bp1 ) ;
      Pieces * bp2 = new Chess::BlackPawn ( "BP ", board_ ) ;
      bp2->setKing( bk ) ;
      blackTurn_->setActivePiece( bp2 ) ;
      Pieces * bp3 = new Chess::BlackPawn ( "BP ", board_ ) ;
      bp3->setKing( bk ) ;
      blackTurn_->setActivePiece( bp3 ) ;
      Pieces * bp4 = new Chess::BlackPawn ( "BP ", board_ ) ;
      bp4->setKing( bk ) ;
      blackTurn_->setActivePiece( bp4 ) ;
      Pieces * bp5 = new Chess::BlackPawn ( "BP ", board_ ) ;
      bp5->setKing( bk ) ;
      blackTurn_->setActivePiece( bp5 ) ;
      Pieces * bp6 = new Chess::BlackPawn ( "BP ", board_ ) ;
      bp6->setKing( bk ) ;
      blackTurn_->setActivePiece( bp6 ) ;
      Pieces * bp7 = new Chess::BlackPawn ( "BP ", board_ ) ;
      bp7->setKing( bk ) ;
      blackTurn_->setActivePiece( bp7 ) ;
      Pieces * bp8 = new Chess::BlackPawn ( "BP ", board_ ) ;
      bp8->setKing( bk ) ;
      blackTurn_->setActivePiece( bp8 ) ;
      Pieces * wq  = new Chess::Queen ( "WQ ", board_ ) ;
      wq->setKing( wk ) ;
      blackTurn_->setActivePiece( wq ) ;
      Pieces * bq  = new Chess::Queen ( "BQ ", board_ ) ;
      bq->setKing( bk ) ;
      blackTurn_->setActivePiece( bq ) ;
      
      whiteTurn_->setDefensiveKing( wk ) ;
      whiteTurn_->setOffensiveKing( bk ) ;
      blackTurn_->setDefensiveKing( bk ) ;
      blackTurn_->setOffensiveKing( wk ) ;
      currentTurn_ = whiteTurn_ ;

      setPiece (wr1, 6, 4) ;
      setPiece (wr2, 7, 7) ;
      setPiece (br1, 6, 1) ;
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
      // setPiece (wp2, 6, 1) ;
      // setPiece (wp3, 6, 2) ;
      // setPiece (wp4, 6, 3) ;
      // setPiece (wp5, 6, 4) ;
      // setPiece (wp6, 6, 5) ;
      // setPiece (wp7, 6, 6) ;
      // setPiece (wp8, 6, 7) ;
      // setPiece (bp1, 1, 0) ;
      // setPiece (bp2, 1, 1) ;
      // setPiece (bp3, 1, 2) ;
      // setPiece (bp4, 1, 3) ;
      // setPiece (bp5, 1, 4) ;
      // setPiece (bp6, 1, 5) ;
      // setPiece (bp7, 1, 6) ;
      // setPiece (bp8, 1, 7) ;
      setPiece (wq , 7, 3) ;
      setPiece (bq , 0, 3) ;
      setPiece (wk , 7, 4) ;
      setPiece (bk , 6, 0) ;

      
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