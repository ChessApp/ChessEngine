// This header file houses all of the data
// and functions that compose the Interface 
// class. The main service of this class is
// to drive the user interface.


#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

#include "Board.h"
#include "BaseTurn.h"
#include "Pieces/Pieces.h"

using namespace std;

namespace Chess
{

  class Interface
  {

    typedef vector< Pieces * > PinList ;

  public:

    Board * board ;
    Pieces * currentPiece ;
    Pieces * destPiece ;
  	string userBoard[11][11];
  	string userInput;
  	string empty_sqr;
  	int userSourceCol;
  	int userSourceRow;
  	int userDestCol;
  	int userDestRow;
    int sourceCol;
    int sourceRow;
    int destCol;
    int destRow;

  	char check_status;
  	char turn;
    BaseTurn *& currentTurn_ ;

  	// Constructs the interface object, with all of
  	// its initial conditions set.
  	Interface( 
      Board * board, 
      BaseTurn *& currentTurn ) ;

    void printPinListDiagnostics( ) ;

    void updateUserBoard ( ) ; 

    // Ensures that the user has specified board coordinates
    // that exist on the board, in the proper format.
    bool inputContent(void);

    // Ensures that the user input is 5 characters long (proper
    // format).
    bool inputSize(void);

    // Ensures that the user did not try to move a piece to 
    // the square that it is already located.
    bool inputDiffSqr(void);

    // Ensures that the user did not try to move a piece to 
    // a square where a piece of the same color is already
    // located.
    bool inputSqrAvailable(void);

    // Ensures that the piece being moved corresponds to the 
    // color of the given turn.
    bool inputPieceOwner(void);

    // Runs the 5 functions listed above, and returns false 
    // if any of those functions return false.
    bool inputValidityChecks(void);

  	// Interacts with the standard output stream 
  	// to print the names of each piece object
  	// as a matrix of strings which resemble the
  	// state of the current board.
  	void printBoard(void);

  	// Prints game conditions to the standard output
  	// stream, which appear below the board.
  	void printGameConds(void);

  	// Interacts with the standard input stream in order
  	// to recieve instructions from the user about
  	// where to move pieces.
  	void getInput(void);

  	// Takes user input from the standard input
  	// stream and performs an ASCII conversion 
  	// to translate piece coordinate columns to match the 
  	// proper indices of the Mastermind board.
  	int colLocation(char user_col);

  	// Takes user input from the standard input
  	// stream and performs an ASCII conversion 
  	// to translate piece coordinate rows to match the 
  	// proper indices of the Mastermind board.
  	int rowLocation(char user_row);

  	// Takes the raw user input and applies the
  	// colLocation and rowLocation functions to 
  	// specific characters, and then stores those
  	// converted ASCII codes in respective memory 
  	// locations to be used by the Mastermind files.
  	void updateMoveSpecs(void);

  	// Prints a message if the user attempts to 
  	// make an invalid move.
  	void invalidMoveMessage(void);

  	// Prints a message whenever the user attempts
  	// to make a move that leaves them in check.
  	void inCheckMessage(void);

  	// Prints a message when the game is over, which
  	// states which team won the game.
  	void checkmateStatus(void);
  };

}



#endif /* INTERFACE_H_ */

