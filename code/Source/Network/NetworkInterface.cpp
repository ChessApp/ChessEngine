#include "Network/NetworkInterface.h"


namespace Chess
{
  namespace Network
  {

    NetworkInterface::NetworkInterface( BoardPtr board, BaseTurnPtr & currentTurn )
      : Interface(board, currentTurn),
        pendingWhiteUserInput_(true),
        whiteIOService_(),
        blackIOService_(),
        outStreamWhite_(),
        outStreamBlack_(),
        whiteWebServer_(new WebServer(whiteIOService_, pendingWhiteUserInput_, userInput_, outStreamWhite_, 2346)),
        blackWebServer_(new WebServer(blackIOService_, pendingBlackUserInput_, userInput_, outStreamBlack_, 2347)),
        whiteNetworkThread_(whiteIOService_),
        blackNetworkThread_(blackIOService_),
        whiteNetworkHandle_(whiteNetworkThread_),
        blackNetworkHandle_(blackNetworkThread_)
    { }

    void NetworkInterface::getInput( )
    {
      outStreamWhite_ << currentTurn_->getTurn();
      outStreamBlack_ << currentTurn_->getTurn();
      outStreamWhite_ << "'s move: ";
      outStreamBlack_ << "'s move: ";

      // A blocking semaphore should probably be implemented here...
      // For now, we just block on an empty while loop. The network
      // thread has access to this flag, and will set it false once
      // it successfully reads any messages sent to its TCP port.
      if( (currentTurn_->getTurn() == 'W') )
      {
        pendingWhiteUserInput_ = true;
        while(pendingWhiteUserInput_) { }
      }
      else if( currentTurn_->getTurn() == 'B' )
      {
        pendingBlackUserInput_ = true;
        while(pendingBlackUserInput_) { }
      }

      cout << userInput_ << endl;

      if(userInput_ == "")
        exit(0);
    }

    void NetworkInterface::printBoard( )
    {
      updateUserBoard();
      outStreamWhite_.put("\n");
      outStreamBlack_.put("\n");
      
      for( int y = 0; y<11; ++y )
      {
        for( int x = 0; x<11; ++x )
        {
          outStreamWhite_.put(userBoard_[y][x]);
          outStreamBlack_.put(userBoard_[y][x]);
        }

        outStreamWhite_.put("\n");
        outStreamBlack_.put("\n");
      }
    }

    void NetworkInterface::printGameConds( )
    {
      // print game conditions
      outStreamWhite_ << "In check: " << checkStatus_ << "\n";
      outStreamWhite_ << "Move: " << currentTurn_->getTurn() << "\n";
      outStreamWhite_ << "Please enter your next move in the following format: source,destination\nExample: A2,A4 (Capital letters)\n";

      outStreamBlack_ << "In check: " << checkStatus_ << "\n";
      outStreamBlack_ << "Move: " << currentTurn_->getTurn() << "\n";
      outStreamBlack_ << "Please enter your next move in the following format: source,destination\nExample: A2,A4 (Capital letters)\n";
    }

    // Prints a message if the user attempts to 
    // make an invalid move.
    void NetworkInterface::invalidMoveMessage( )
    {
      outStreamWhite_ << "The move you entered was not valid." << "\n";
      outStreamWhite_ << "Please enter a valid move in the format provided." << "\n";

      outStreamBlack_ << "The move you entered was not valid." << "\n";
      outStreamBlack_ << "Please enter a valid move in the format provided." << "\n";
    }

    // Prints a message whenever the user attempts
    // to make a move that leaves them in check.
    void NetworkInterface::inCheckMessage( )
    {
      outStreamWhite_ << "You are, or will be, in check." << "\n";
      outStreamWhite_ << "Please enter a move so you are not in check." << "\n";

      outStreamBlack_ << "You are, or will be, in check." << "\n";
      outStreamBlack_ << "Please enter a move so you are not in check." << "\n";
    }

    // Prints a message when the game is over, which
    // states which team won the game.
    void NetworkInterface::checkmateStatus( )
    {
      printBoard();

      if(currentTurn_->getTurn() == 'W')
      {
        outStreamWhite_ << "Checkmate! Winner: W" << "\n";
        outStreamBlack_ << "Checkmate! Winner: W" << "\n";
      }
      if(currentTurn_->getTurn() == 'B')
      {
        outStreamWhite_ << "Checkmate! Winner: B" << "\n";
        outStreamBlack_ << "Checkmate! Winner: B" << "\n";
      }
    }

    void NetworkInterface::startupMessage( )
    {
      outStreamWhite_ << "\n";
      outStreamWhite_ << "Firin' up the ol' war game" << "\n";
      outStreamWhite_ << "Courtesy of Booty and Sons" << "\n" << "\n";

      outStreamBlack_ << "\n";
      outStreamBlack_ << "Firin' up the ol' war game" << "\n";
      outStreamBlack_ << "Courtesy of Booty and Sons" << "\n" << "\n";
    }

  }
}
