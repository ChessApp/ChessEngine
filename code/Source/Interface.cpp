// This source file houses all of the associated
// logic that composes the functions within the
// Interface class, which is described in the 
// included Interface header file.
#include "Interface.h"


namespace Chess
{

  Interface::Interface( BoardPtr board, BaseTurnPtr & currentTurn )
   : board_(board),
     currentTurn_(currentTurn)
  {
  	// set initial check status so that neither team 
  	// is in check
  	checkStatus_ = 'N';

  	/*********************************************
  	Initial Board Content
  	********************************************/

  	// add upper left content
  	userBoard_[0][0] = "   ";

  	// add lower left content
  	userBoard_[9][0] = "   ";
  	userBoard_[10][0] = "   ";

  	// add lower right content
  	userBoard_[9][9] = "   ";
  	userBoard_[10][9] = "   ";

  	// add upper right content
  	userBoard_[0][9] = "   ";

  	// add first row of board content
  	for( int x = 1; x < 9; ++x )
  		userBoard_[0][x] = "---";

  	// add right column of board content
  	for( int y = 1; y < 9; ++y )
  		userBoard_[y][9] = "|";

  	// add far right column of board empties
  	for( int y = 0; y < 11; ++y )
  		userBoard_[y][10] = "   ";

  	// add column and row labels
  	userBoard_[9][1] = "---";
  	userBoard_[9][2] = "---";
  	userBoard_[9][3] = "---";
  	userBoard_[9][4] = "---";
  	userBoard_[9][5] = "---";
  	userBoard_[9][6] = "---";
  	userBoard_[9][7] = "---";
  	userBoard_[9][8] = "---";
  	userBoard_[10][1] = "A  ";
  	userBoard_[10][2] = "B  ";
  	userBoard_[10][3] = "C  ";
  	userBoard_[10][4] = "D  ";
  	userBoard_[10][5] = "E  ";
  	userBoard_[10][6] = "F  ";
  	userBoard_[10][7] = "G  ";
  	userBoard_[10][8] = "H  ";
  	userBoard_[1][0] = "8| ";
  	userBoard_[2][0] = "7| ";
  	userBoard_[3][0] = "6| ";
  	userBoard_[4][0] = "5| ";
  	userBoard_[5][0] = "4| ";
  	userBoard_[6][0] = "3| ";
  	userBoard_[7][0] = "2| ";
  	userBoard_[8][0] = "1| ";

    updateUserBoard();
  }

  void Interface::printPinListDiagnostics( )
  {
    typedef vector<PiecePtr> PinList;
    cout << "List of pinned pieces: " << endl;
    PinList pinList = currentTurn_->getPinList();
    for( int i = 0; i < pinList.size(); i++ )
    {
      PiecePtr pinnedPiece = pinList[i] ;
      cout << "Name: " << pinnedPiece->getName() << endl;
      cout << "Row: "  << pinnedPiece->getRow()  << endl;
      cout << "Col: "  << pinnedPiece->getCol()  << endl;
    }
  }

  void Interface::updateUserBoard( )
  {
    for( int y = 1; y <= 8; y++ )
    {
      for( int x = 1; x <= 8; x++ )
        userBoard_[y][x] = board_->getPieceName( (y-1), (x-1) );
    }
  }

  // Ensures that the user input is 5 characters long (proper
  // format).
  bool Interface::inputSize( )
  {
    if( userInput_.size() == 5 )
      return true;
    else
      return false;
  }

  // Ensures that the user did not try to move a piece to 
  // the square that it is already located.
  bool Interface::inputDiffSqr( )
  {
    if( userInput_[0] != userInput_[3] || userInput_[1] != userInput_[4] )
      return true;
    else
      return false;
  }

  // Ensures that the user has specified board coordinates
  // that exist on the board, in the proper format.
  bool Interface::inputContent( )
  {
    if( (userInput_[0] == 'A' || userInput_[0] == 'B' || userInput_[0] == 'C' || userInput_[0] == 'D' ||
         userInput_[0] == 'E' || userInput_[0] == 'F' || userInput_[0] == 'G' || userInput_[0] == 'H')
        &&
        (userInput_[1] == '1' || userInput_[1] == '2' || userInput_[1] == '3' || userInput_[1] == '4' ||
         userInput_[1] == '5' || userInput_[1] == '6' || userInput_[1] == '7' || userInput_[1] == '8')
        &&
         userInput_[2] == ','
        &&
        (userInput_[3] == 'A' || userInput_[3] == 'B' || userInput_[3] == 'C' || userInput_[3] == 'D' ||
         userInput_[3] == 'E' || userInput_[3] == 'F' || userInput_[3] == 'G' || userInput_[3] == 'H')
        &&
        (userInput_[4] == '1' || userInput_[4] == '2' || userInput_[4] == '3' || userInput_[4] == '4' ||
         userInput_[4] == '5' || userInput_[4] == '6' || userInput_[4] == '7' || userInput_[4] == '8') )
      return true;
    else
      return false;
  }

  // Ensures that the user did not try to move a piece to 
  // a square where a piece of the same color is already
  // located.
  bool Interface::inputSqrAvailable( )
  {
    if( destPiece_->getColor() != currentPiece_->getColor() )
      return true;
    else
      return false;
  }

  // Ensures that the piece being moved corresponds to the 
  // color of the given turn.
  bool Interface::inputPieceOwner( )
  {
    if( currentTurn_->getTurn() == currentPiece_->getColor() )
      return true;
    else
      return false;
  }

  // Runs the 5 functions listed above, and returns false 
  // if any of those functions return false.
  bool Interface::inputValidityChecks( )
  {
    if( inputContent() )
    {
      currentPiece_ = board_->getPiece(sourceRow, sourceCol);
      destPiece_    = board_->getPiece(destRow, destCol);

      if( inputDiffSqr() &&
          inputSqrAvailable() &&
          inputPieceOwner() )
        return true;
    }
    
    return false;
  }

  // Interacts with the standard output stream 
  // to print the names of each piece object
  // as a matrix of strings which resemble the
  // state of the current board.
  void Interface::printBoard( )
  {
    updateUserBoard();

  	for( int y = 0; y<11; ++y )
  	{
  		for( int x = 0; x<11; ++x )
  			cout << userBoard_[y][x];

  		cout << endl;
  	}
  }

  // Prints game conditions to the standard output
  // stream, which appear below the board.
  void Interface::printGameConds( )
  {
  	// print game conditions
  	cout << "In check: " << checkStatus_ << endl;
  	cout << "Move: " << currentTurn_->getTurn() << endl;
  	cout << "Please enter your next move in the following format: source,destination\nExample: A2,A4 (Capital letters)" << endl;
  }

  // Interacts with the standard input stream in order
  // to recieve instructions from the user about
  // where to move pieces.
  void Interface::getInput( )
  {
    cout << currentTurn_->getTurn() << "'s move: ";
  	getline(cin, userInput_);
    cout << userInput_ << endl;
    if(userInput_ == "")
      exit(0);
  }

  // Takes user input from the standard input
  // stream and performs an ASCII conversion 
  // to translate piece coordinate columns to match the 
  // proper indices of the Mastermind board.
  int Interface::colLocation( char user_col )
  {
  	return (int) (user_col - 64);
  }

  // Takes user input from the standard input
  // stream and performs an ASCII conversion 
  // to translate piece coordinate rows to match the 
  // proper indices of the Mastermind board.
  int Interface::rowLocation( char user_row )
  {
  	return (int) -(user_row - 57);
  }

  // Takes the raw user input and applies the
  // colLocation and rowLocation functions to 
  // specific characters, and then stores those
  // converted ASCII codes in respective memory 
  // locations to be used by the Mastermind files.
  void Interface::updateMoveSpecs( )
  {
  	int userSourceCol = colLocation(userInput_[0]);
  	int userSourceRow = rowLocation(userInput_[1]);
  	int userDestCol   = colLocation(userInput_[3]);
  	int userDestRow   = rowLocation(userInput_[4]);

    sourceCol = userSourceCol - 1;
    sourceRow = userSourceRow - 1;
    destCol   = userDestCol - 1;
    destRow   = userDestRow - 1;
  }

  // Prints a message if the user attempts to 
  // make an invalid move.
  void Interface::invalidMoveMessage( )
  {
  	cout << "The move you entered was not valid." << endl;
  	cout << "Please enter a valid move in the format provided." << endl;
  }

  // Prints a message whenever the user attempts
  // to make a move that leaves them in check.
  void Interface::inCheckMessage( )
  {
  	cout << "You are, or will be, in check." << endl;
  	cout << "Please enter a move so you are not in check." << endl;
  }

  // Prints a message when the game is over, which
  // states which team won the game.
  void Interface::checkmateStatus( )
  {
  	printBoard();

  	if(currentTurn_->getTurn() == 'W')
  		cout << "Checkmate! Winner: W" << endl;
  	if(currentTurn_->getTurn() == 'B')
  		cout << "Checkmate! Winner: B" << endl;
  }

  void Interface::startupMessage( )
  {
    cout << "\n";
    cout << "Firin' up the ol' war game" << "\n";
    cout << "Courtesy of Booty and Sons" << "\n" << "\n";
  }

}
