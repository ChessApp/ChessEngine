// This is the main file.
// It uses the other support files to actually
// execute the chess game.

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Interface.h"
#include "Pieces/Pieces.h"
#include "Pieces/NullPiece.h"
// #include "Mastermind.h"
#include "Pieces/Rook.h"
#include "Pieces/Bishop.h"
#include "Pieces/Pawn.h"
#include "Pieces/Knight.h"
#include "Pieces/Queen.h"
#include "Pieces/King.h"
#include "Board.h"
#include "Scans/Scanner.h"
// #include "SingleAxisScan.h"
// #include "DualAxisScan.h"
#include "GameProtocolDriver.h"

// Uncomment the line below to run unit tests
// #define RUN_UNIT_TESTS

using namespace std;

Chess::Interface * interface = NULL ;

Chess::Rook * wr1 = NULL ;
Chess::Rook * wr2 = NULL ;
Chess::Rook * br1 = NULL ;
Chess::Rook * br2 = NULL ;
Chess::Bishop * wb1 = NULL ;
Chess::Bishop * wb2 = NULL ;
Chess::Bishop * bb1 = NULL ;
Chess::Bishop * bb2 = NULL ;
Chess::Knight * wn1 = NULL ;
Chess::Knight * wn2 = NULL ;
Chess::Knight * bn1 = NULL ;
Chess::Knight * bn2 = NULL ;
Chess::Pawn * wp1 = NULL ;
Chess::Pawn * wp2 = NULL ;
Chess::Pawn * wp3 = NULL ;
Chess::Pawn * wp4 = NULL ;
Chess::Pawn * wp5 = NULL ;
Chess::Pawn * wp6 = NULL ;
Chess::Pawn * wp7 = NULL ;
Chess::Pawn * wp8 = NULL ;
Chess::Pawn * bp1 = NULL ;
Chess::Pawn * bp2 = NULL ;
Chess::Pawn * bp3 = NULL ;
Chess::Pawn * bp4 = NULL ;
Chess::Pawn * bp5 = NULL ;
Chess::Pawn * bp6 = NULL ;
Chess::Pawn * bp7 = NULL ;
Chess::Pawn * bp8 = NULL ;
Chess::Queen * wq = NULL ;
Chess::Queen * bq = NULL ;
Chess::King * wk  = NULL ;
Chess::King * bk  = NULL ;

Chess::Board * gameBoard;

int main( int argc, char ** argv )
{

  #ifdef RUN_UNIT_TESTS
  ::testing::InitGoogleMock ( & argc, argv ) ;
  RUN_ALL_TESTS ( ) ;
  #endif /* RUN_UNIT_TESTS */

  new Chess::GameProtocolDriver ( ) ;

  // gameBoard = new Chess::Board ( ) ;

  // interface = new Chess::Interface ( gameBoard ) ;

  // wr1 = new Chess::Rook ( "WR ", gameBoard ) ;
  // wr2 = new Chess::Rook ( "WR ", gameBoard ) ;
  // br1 = new Chess::Rook ( "BR ", gameBoard ) ;
  // br2 = new Chess::Rook ( "BR ", gameBoard ) ;
  // wb1 = new Chess::Bishop ( "WB ", gameBoard ) ;
  // wb2 = new Chess::Bishop ( "WB ", gameBoard ) ;
  // bb1 = new Chess::Bishop ( "BB ", gameBoard ) ;
  // bb2 = new Chess::Bishop ( "BB ", gameBoard ) ;
  // wn1 = new Chess::Knight ( "WN ", gameBoard ) ;
  // wn2 = new Chess::Knight ( "WN ", gameBoard ) ;
  // bn1 = new Chess::Knight ( "BN ", gameBoard ) ;
  // bn2 = new Chess::Knight ( "BN ", gameBoard ) ;
  // wp1 = new Chess::Pawn ( "WP ", gameBoard ) ;
  // wp2 = new Chess::Pawn ( "WP ", gameBoard ) ;
  // wp3 = new Chess::Pawn ( "WP ", gameBoard ) ;
  // wp4 = new Chess::Pawn ( "WP ", gameBoard ) ;
  // wp5 = new Chess::Pawn ( "WP ", gameBoard ) ;
  // wp6 = new Chess::Pawn ( "WP ", gameBoard ) ;
  // wp7 = new Chess::Pawn ( "WP ", gameBoard ) ;
  // wp8 = new Chess::Pawn ( "WP ", gameBoard ) ;
  // bp1 = new Chess::Pawn ( "BP ", gameBoard ) ;
  // bp2 = new Chess::Pawn ( "BP ", gameBoard ) ;
  // bp3 = new Chess::Pawn ( "BP ", gameBoard ) ;
  // bp4 = new Chess::Pawn ( "BP ", gameBoard ) ;
  // bp5 = new Chess::Pawn ( "BP ", gameBoard ) ;
  // bp6 = new Chess::Pawn ( "BP ", gameBoard ) ;
  // bp7 = new Chess::Pawn ( "BP ", gameBoard ) ;
  // bp8 = new Chess::Pawn ( "BP ", gameBoard ) ;
  // wq  = new Chess::Queen ( "WQ ", gameBoard ) ;
  // bq  = new Chess::Queen ( "BQ ", gameBoard ) ;
  // wk  = new Chess::King ( "WK ", gameBoard ) ;
  // bk  = new Chess::King ( "BK ", gameBoard ) ;

  // gameBoard->setPiece (wr1, 7, 0) ;
  // gameBoard->setPiece (wr2, 7, 7) ;
  // gameBoard->setPiece (br1, 0, 0) ;
  // gameBoard->setPiece (br2, 0, 7) ;
  // gameBoard->setPiece (wb1, 7, 2) ;
  // gameBoard->setPiece (wb2, 7, 5) ;
  // gameBoard->setPiece (bb1, 0, 2) ;
  // gameBoard->setPiece (bb2, 0, 5) ;
  // gameBoard->setPiece (wn1, 7, 1) ;
  // gameBoard->setPiece (wn2, 7, 6) ;
  // gameBoard->setPiece (bn1, 0, 1) ;
  // gameBoard->setPiece (bn2, 0, 6) ;
  // gameBoard->setPiece (wp1, 6, 0) ;
  // gameBoard->setPiece (wp2, 6, 1) ;
  // gameBoard->setPiece (wp3, 6, 2) ;
  // gameBoard->setPiece (wp4, 6, 3) ;
  // gameBoard->setPiece (wp5, 6, 4) ;
  // gameBoard->setPiece (wp6, 6, 5) ;
  // gameBoard->setPiece (wp7, 6, 6) ;
  // gameBoard->setPiece (wp8, 6, 7) ;
  // gameBoard->setPiece (bp1, 1, 0) ;
  // gameBoard->setPiece (bp2, 1, 1) ;
  // gameBoard->setPiece (bp3, 1, 2) ;
  // gameBoard->setPiece (bp4, 1, 3) ;
  // gameBoard->setPiece (bp5, 1, 4) ;
  // gameBoard->setPiece (bp6, 1, 5) ;
  // gameBoard->setPiece (bp7, 1, 6) ;
  // gameBoard->setPiece (bp8, 1, 7) ;
  // gameBoard->setPiece (wq , 7, 3) ;
  // gameBoard->setPiece (bq , 0, 3) ;
  // gameBoard->setPiece (wk , 7, 4) ;
  // gameBoard->setPiece (bk , 0, 4) ;


  // interface->printBoard() ;

  system ( "pause" ) ;
  



// INPUT:

// 	mastermind.printInterface();

// 	mastermind.updateMoveSpecs();

// 	if (!mastermind.inputValidityChecks())
// 	{
// 		interface.invalidMoveMessage();
// 		goto INPUT;
// 	}

// 	*************************************************
// 	***Call proper functions based on Source Piece****
// 	************************************************

// 	mastermind.pcurrent_piece = mastermind.psource_piece;

// 	if (!mastermind.runChecks())
// 	{
// 		interface.invalidMoveMessage();
// 		goto INPUT;
// 	}

// 	mastermind.movePiece();

// 	/*********************************************
// 	*******Scan Check Status of Both Kings*******
// 	********************************************/


// 	mastermind.runRadar(&wk1);

// 	if (wk1.in_check && mastermind.turn == 'W')
// 	{
// 		mastermind.returnPiece();
// 		interface.inCheckMessage();
// 		goto INPUT;
// 	}

// 	mastermind.runRadar(&bk1);

// 	if (bk1.in_check && mastermind.turn == 'B')
// 	{
// 		mastermind.returnPiece();
// 		interface.inCheckMessage();
// 		goto INPUT;
// 	}

// 	if (wk1.in_check)
// 	{
// 		mastermind.check_status = 'W';
// 		if (mastermind.in_check > 1 || !mastermind.runBlockChecks())
// 		{
// 			goto ESCAPEROUTES;
// 		}
// 	}

// 	if (bk1.in_check)
// 	{
// 		mastermind.check_status = 'B';
// 		if (mastermind.in_check > 1 || !mastermind.runBlockChecks())
// 		{
// 			goto ESCAPEROUTES;
// 		}
// 	}

// 	if (!(wk1.in_check) && !(bk1.in_check))
// 	{
// 		mastermind.check_status = 'N';
// 	}

// 	mastermind.updateGameData();
// 	goto INPUT;


// ESCAPEROUTES:

// 	if (bk1.in_check)
// 	{
// 		if (mastermind.escapeRoutes(&bk1))
// 		{
// 			mastermind.updateGameData();
// 			goto INPUT;
// 		}
// 	}
// 	if (wk1.in_check)
// 	{
// 		if (mastermind.escapeRoutes(&wk1))
// 		{
// 			mastermind.updateGameData();
// 			goto INPUT;
// 		}
// 	}


// CHECKMATE:

// 	mastermind.updateInterfaceBoard();
// 	interface.checkmateStatus();

}



