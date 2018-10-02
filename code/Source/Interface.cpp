// This source file houses all of the associated
// logic that composes the functions within the
// Interface class, which is described in the 
// included Interface header file.


#include "Interface.h"


namespace Chess
{

  Interface::Interface( Board * board )
   : board(board)
  {
  	// set initial turn to White
  	turn = 'W';

  	// set initial check status so that neither team 
  	// is in check
  	check_status = 'N';

  	/*********************************************
  	Initial Board Content
  	********************************************/

  	//add upper left content
  	userBoard[0][0] = "   ";

  	//add lower left content
  	userBoard[9][0] = "   ";
  	userBoard[10][0] = "   ";

  	//add lower right content
  	userBoard[9][9] = "   ";
  	userBoard[10][9] = "   ";

  	//add upper right content
  	userBoard[0][9] = "   ";

  	//add first row of board content
  	for (int x = 1; x < 9; ++x)
  	{
  		userBoard[0][x] = "---";
  	}

  	//add right column of board content
  	for (int y = 1; y < 9; ++y)
  	{
  		userBoard[y][9] = "|";
  	}

  	//add far right column of board empties
  	for (int y = 0; y < 11; ++y)
  	{
  		userBoard[y][10] = "   ";
  	}

  	// add column and row labels
  	userBoard[9][1] = "---";
  	userBoard[9][2] = "---";
  	userBoard[9][3] = "---";
  	userBoard[9][4] = "---";
  	userBoard[9][5] = "---";
  	userBoard[9][6] = "---";
  	userBoard[9][7] = "---";
  	userBoard[9][8] = "---";
  	userBoard[10][1] = "A  ";
  	userBoard[10][2] = "B  ";
  	userBoard[10][3] = "C  ";
  	userBoard[10][4] = "D  ";
  	userBoard[10][5] = "E  ";
  	userBoard[10][6] = "F  ";
  	userBoard[10][7] = "G  ";
  	userBoard[10][8] = "H  ";
  	userBoard[1][0] = "8| ";
  	userBoard[2][0] = "7| ";
  	userBoard[3][0] = "6| ";
  	userBoard[4][0] = "5| ";
  	userBoard[5][0] = "4| ";
  	userBoard[6][0] = "3| ";
  	userBoard[7][0] = "2| ";
  	userBoard[8][0] = "1| ";

    updateUserBoard() ;

  }

  void Interface::updateUserBoard ( )
  {
    for ( int y = 1; y <= 8; y++ )
    {
      for ( int x = 1; x <= 8; x++ )
      {
        userBoard[y][x] = board->getPieceName ( (y-1), (x-1) ) ;
      }
    }
  }

  bool Interface::inputSize(void)
  {
    if (userInput.size() == 5)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool Interface::inputDiffSqr(void)
  {
    if (userInput[0] != userInput[3] || userInput[1] != userInput[4])
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool Interface::inputContent(void)
  {
    if (
      (userInput[0] == 'A' || userInput[0] == 'B' || userInput[0] == 'C' || userInput[0] == 'D' ||
        userInput[0] == 'E' || userInput[0] == 'F' || userInput[0] == 'G' || userInput[0] == 'H')
      &&
      (userInput[1] == '1' || userInput[1] == '2' || userInput[1] == '3' || userInput[1] == '4' ||
        userInput[1] == '5' || userInput[1] == '6' || userInput[1] == '7' || userInput[1] == '8')
      &&
      userInput[2] == ','
      &&
      (userInput[3] == 'A' || userInput[3] == 'B' || userInput[3] == 'C' || userInput[3] == 'D' ||
        userInput[3] == 'E' || userInput[3] == 'F' || userInput[3] == 'G' || userInput[3] == 'H')
      &&
      (userInput[4] == '1' || userInput[4] == '2' || userInput[4] == '3' || userInput[4] == '4' ||
        userInput[4] == '5' || userInput[4] == '6' || userInput[4] == '7' || userInput[4] == '8')
      )
    {
      return true;
    }
    else
    {
      return false;
    }
  }


  bool Interface::inputSqrAvailable(void)
  {

    if ( destPiece->getColor() != currentPiece->getColor() )
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool Interface::inputPieceOwner(void)
  {
    if ( turn == currentPiece->getColor() )
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool Interface::inputValidityChecks(void)
  {
    currentPiece = board->getPiece ( sourceRow, sourceCol ) ;
    destPiece = board->getPiece ( destRow, destCol ) ;

    if ( inputContent() &&
      inputDiffSqr() &&
      inputSqrAvailable() &&
      inputPieceOwner() )
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  void Interface::printBoard(void)
  {
    updateUserBoard() ;

  	for (int y = 0; y<11; ++y)
  	{
  		for (int x = 0; x<11; ++x)
  		{
  			cout << userBoard[y][x];
  		}
  		cout << endl;
  	}
  }

  void Interface::printGameConds(void)
  {
  	//print game conditions
  	cout << "In check: " << check_status << endl;
  	cout << "Move: " << turn << endl;
  	cout << "Please enter your next move in the following format: source,destination\nExample: A2,A4 (Capital letters)" << endl;
  }

  void Interface::getInput(void)
  {
  	getline(cin, userInput);
  }

  int Interface::colLocation(char user_col)
  {
  	return (int)user_col - 64;
  }

  int Interface::rowLocation(char user_row)
  {
  	return (int)-(user_row - 57);
  }

  void Interface::updateMoveSpecs(void)
  {
  	userSourceCol = colLocation(userInput[0]);
  	userSourceRow = rowLocation(userInput[1]);
  	userDestCol = colLocation(userInput[3]);
  	userDestRow = rowLocation(userInput[4]);

    sourceCol = userSourceCol - 1 ;
    sourceRow = userSourceRow - 1 ;
    destCol = userDestCol - 1 ;
    destRow = userDestRow - 1 ;
  }

  void Interface::invalidMoveMessage(void)
  {
  	cout << "The move you entered was not valid." << endl;
  	cout << "Please enter a valid move in the format provided." << endl;
  }

  void Interface::inCheckMessage(void)
  {
  	cout << "You are, or will be, in check." << endl;
  	cout << "Please enter a move so you are not in check." << endl;
  }


  void Interface::checkmateStatus(void)
  {
  	printBoard();
  	if (turn == 'W')
  	{
  		cout << "Checkmate! Winner: W" << endl;
  	}
  	if (turn == 'B')
  	{
  		cout << "Checkmate! Winner: B" << endl;
  	}
  }

}




