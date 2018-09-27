// This header file houses all of the data 
// and functions that compose the Mastermind 
// class. This class performs all of the
// analysis that runs the game, in conjunction
// with data provided from the Interface and
// Pieces files.


#ifndef MASTERMIND_H_
#define MASTERMIND_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include "Interface.h"
#include "Pieces.h"

using namespace std;

class Mastermind
{
public:

	Interface &interface;
	Pieces* pwr1;
	Pieces* pwr2;
	Pieces* pwb1;
	Pieces* pwb2;
	Pieces* pwk1;
	Pieces* pwp1;
	Pieces* pwp2;
	Pieces* pwp3;
	Pieces* pwp4;
	Pieces* pwp5;
	Pieces* pwp6;
	Pieces* pwp7;
	Pieces* pwp8;
	Pieces* pbr1;
	Pieces* pbr2;
	Pieces* pbb1;
	Pieces* pbb2;
	Pieces* pbk1;
	Pieces* pbp1;
	Pieces* pbp2;
	Pieces* pbp3;
	Pieces* pbp4;
	Pieces* pbp5;
	Pieces* pbp6;
	Pieces* pbp7;
	Pieces* pbp8;
	Pieces* pnullpiece;

	Pieces* board[11][11];
	int in_check;
	char prev_check_status;
	char turn;
	char check_status;
	Pieces* psource_piece;
	Pieces* pdest_piece;
	Pieces* pcurrent_piece;
	int* psource_col;
	int* psource_row;
	int* pdest_col;
	int* pdest_row;
	Pieces* potential_pin;
	string pin_list[8];
	int pin_index;

	int uprow_blockcheck[7];
	int upcol_blockcheck[7];
	int up_index;
	int downrow_blockcheck[7];
	int downcol_blockcheck[7];
	int down_index;
	int rightrow_blockcheck[7];
	int rightcol_blockcheck[7];
	int right_index;
	int leftrow_blockcheck[7];
	int leftcol_blockcheck[7];
	int left_index;
	int uprightrow_blockcheck[7];
	int uprightcol_blockcheck[7];
	int upright_index;
	int upleftrow_blockcheck[7];
	int upleftcol_blockcheck[7];
	int upleft_index;
	int downrightrow_blockcheck[7];
	int downrightcol_blockcheck[7];
	int downright_index;
	int downleftrow_blockcheck[7];
	int downleftcol_blockcheck[7];
	int downleft_index;
	int* prow_array[7];
	int* pcol_array[7];
	int* pindex;

	// Constructs the mastermind object, which recieves the
	// interface and piece objects as pointer arguments. The constructor
	// creates a matrix of pointers (the board), which are set to hold the 
	// memory addresses of the piece objects. It then stores 
	// the appropriate piece addresses in the respective pointers
	// for the start of the game. All board squares that are not 
	// occupied by a piece receive the memory address of a 
	// "nullpiece" object. The initial check status and turn are 
	// also set here.
	Mastermind(Interface &interface, Pieces *nullpiece,
		Pieces* wr1, Pieces* wr2, Pieces* wb1,
		Pieces* wb2, Pieces* wk1,
		Pieces* wp1, Pieces* wp2, Pieces* wp3,
		Pieces* wp4, Pieces* wp5, Pieces* wp6,
		Pieces* wp7, Pieces* wp8,
		Pieces* br1, Pieces* br2, Pieces* bb1,
		Pieces* bb2, Pieces* bk1,
		Pieces* bp1, Pieces* bp2, Pieces* bp3,
		Pieces* bp4, Pieces* bp5, Pieces* bp6,
		Pieces* bp7, Pieces* bp8);

	// Stores the memory address of the source piece object 
	// and the destination piece object specified by the user
	// into the respective pointers for source and destination
	// piece. Calls the parallel interface function which updates 
	// the respective variables within the interface class for 
	// printing purposes.
	void updateMoveSpecs(void);

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

	// Ensures the leftward path from the source location to 
	// the destination location does not have any pieces in 
	// between. This is to prevent pieces from "flying" (a
	// capability that only knights possess) over 
	// other pieces on their way to the destination.
	bool moveLeftValidity(void);

	bool moveRightValidity(void);

	bool moveUpValidity(void);

	bool moveDownValidity(void);

	bool moveUpLeftValidity(void);

	bool moveUpRightValidity(void);

	bool moveDownLeftValidity(void);

	bool moveDownRightValidity(void);

	bool bValidPath(void);

	bool bRunChecks(void);

	bool rValidPath(void);

	bool kMoveValidity(void);

	bool pMoveWhiteValidity(void);

	bool pMoveBlackValidity(void);

	bool rRunChecks(void);

	bool checkBlock(void);

	

	void checkPinLeft(Pieces* king, int i, int row);

	void checkPinRight(Pieces* king, int i, int row);

	void checkPinUp(Pieces* king, int col, int j);

	void checkPinDown(Pieces* king, int col, int j);

	void checkPinUpLeft(Pieces* king, int i, int j);

	void checkPinDownLeft(Pieces* king, int i, int j);

	void checkPinUpRight(Pieces* king, int i, int j);

	void checkPinDownRight(Pieces* king, int i, int j);

	bool addToPinList(Pieces* king, char attacker, Pieces* potential_pin);

	bool runRadar(Pieces* king);

	bool escapeRoutes(Pieces* king);

	void pointToBlockableSqrs(void);

	bool runBlockChecks(void);

	void movePiece(void);

	void returnPiece(void);

	void updatePinStatus(void);

	void switchTurn(void);

	void updateGameData(void);

	void updateInterfaceBoard(void);

	void printInterface(void);

	bool runChecks(void);

};



#endif /* MASTERMIND_H_ */
