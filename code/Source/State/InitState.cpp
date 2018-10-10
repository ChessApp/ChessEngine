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
      Pieces * bk  = new Chess::King ( "BK ", board_ ) ;
      Pieces * wr1 = new Chess::Rook ( "WR ", board_ ) ;
      wr1->setKing( wk ) ;
      Pieces * wr2 = new Chess::Rook ( "WR ", board_ ) ;
      wr2->setKing( wk ) ;
      Pieces * br1 = new Chess::Rook ( "BR ", board_ ) ;
      br1->setKing( bk ) ;
      Pieces * br2 = new Chess::Rook ( "BR ", board_ ) ;
      br2->setKing( bk ) ;
      Pieces * wb1 = new Chess::Bishop ( "WB ", board_ ) ;
      wb1->setKing( wk ) ;
      Pieces * wb2 = new Chess::Bishop ( "WB ", board_ ) ;
      wb2->setKing( wk ) ;
      Pieces * bb1 = new Chess::Bishop ( "BB ", board_ ) ;
      bb1->setKing( bk ) ;
      Pieces * bb2 = new Chess::Bishop ( "BB ", board_ ) ;
      bb2->setKing( bk ) ;
      Pieces * wn1 = new Chess::Knight ( "WN ", board_ ) ;
      wn1->setKing( wk ) ;
      Pieces * wn2 = new Chess::Knight ( "WN ", board_ ) ;
      wn2->setKing( wk ) ;
      Pieces * bn1 = new Chess::Knight ( "BN ", board_ ) ;
      bn1->setKing( bk ) ;
      Pieces * bn2 = new Chess::Knight ( "BN ", board_ ) ;
      bn2->setKing( bk ) ;
      Pieces * wp1 = new Chess::WhitePawn ( "WP ", board_ ) ;
      wp1->setKing( wk ) ;
      Pieces * wp2 = new Chess::WhitePawn ( "WP ", board_ ) ;
      wp2->setKing( wk ) ;
      Pieces * wp3 = new Chess::WhitePawn ( "WP ", board_ ) ;
      wp3->setKing( wk ) ;
      Pieces * wp4 = new Chess::WhitePawn ( "WP ", board_ ) ;
      wp4->setKing( wk ) ;
      Pieces * wp5 = new Chess::WhitePawn ( "WP ", board_ ) ;
      wp5->setKing( wk ) ;
      Pieces * wp6 = new Chess::WhitePawn ( "WP ", board_ ) ;
      wp6->setKing( wk ) ;
      Pieces * wp7 = new Chess::WhitePawn ( "WP ", board_ ) ;
      wp7->setKing( wk ) ;
      Pieces * wp8 = new Chess::WhitePawn ( "WP ", board_ ) ;
      wp8->setKing( wk ) ;
      Pieces * bp1 = new Chess::BlackPawn ( "BP ", board_ ) ;
      bp1->setKing( bk ) ;
      Pieces * bp2 = new Chess::BlackPawn ( "BP ", board_ ) ;
      bp2->setKing( bk ) ;
      Pieces * bp3 = new Chess::BlackPawn ( "BP ", board_ ) ;
      bp3->setKing( bk ) ;
      Pieces * bp4 = new Chess::BlackPawn ( "BP ", board_ ) ;
      bp4->setKing( bk ) ;
      Pieces * bp5 = new Chess::BlackPawn ( "BP ", board_ ) ;
      bp5->setKing( bk ) ;
      Pieces * bp6 = new Chess::BlackPawn ( "BP ", board_ ) ;
      bp6->setKing( bk ) ;
      Pieces * bp7 = new Chess::BlackPawn ( "BP ", board_ ) ;
      bp7->setKing( bk ) ;
      Pieces * bp8 = new Chess::BlackPawn ( "BP ", board_ ) ;
      bp8->setKing( bk ) ;
      Pieces * wq  = new Chess::Queen ( "WQ ", board_ ) ;
      wq->setKing( wk ) ;
      Pieces * bq  = new Chess::Queen ( "BQ ", board_ ) ;
      bq->setKing( bk ) ;
      
      whiteTurn_->setDefensiveKing( wk ) ;
      whiteTurn_->setOffensiveKing( bk ) ;
      blackTurn_->setDefensiveKing( bk ) ;
      blackTurn_->setOffensiveKing( wk ) ;
      currentTurn_ = whiteTurn_ ;

      nextState_->setWhiteKing( wk ) ;
      nextState_->setBlackKing( bk ) ;

      

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