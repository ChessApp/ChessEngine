#include "Network/NetworkInterface.h"

#include <chrono>
#include <thread>


namespace Chess
{
  namespace Network
  {

    NetworkInterface::NetworkInterface( BoardPtr board, BaseTurnPtr & currentTurn )
      : Interface(board, currentTurn),
        pendingUserInput_(true),
        ioService_(),
        ioServiceBlack_(),
        outStream_(),
        outStreamBlack_(),
        webServer_(new WebServer(ioService_, pendingUserInput_, userInput_, outStream_, 2346)),
        webServerBlack_(new WebServer(ioServiceBlack_, pendingUserInputBlack_, userInput_, outStreamBlack_, 2347)),
        networkThread_(ioService_),
        networkThreadBlack_(ioServiceBlack_),
        networkHandle_(networkThread_),
        networkHandleBlack_(networkThreadBlack_)
    { }

    void NetworkInterface::getInput( )
    {
      outStream_ << currentTurn_->getTurn();
      outStreamBlack_ << currentTurn_->getTurn();
      outStream_ << "'s move: ";
      outStreamBlack_ << "'s move: ";

      // A blocking semaphore should probably be implemented here...
      // For now, we just block on an empty while loop. The network
      // thread has access to this flag, and will set it false once
      // it successfully reads any messages sent to its TCP port.
      if( (currentTurn_->getTurn() == 'W') )
      {
        pendingUserInput_ = true;
        while(pendingUserInput_) { }
      }
      else if( currentTurn_->getTurn() == 'B' )
      {
        pendingUserInputBlack_ = true;
        while(pendingUserInputBlack_) { }
      }

      cout << userInput_ << endl;

      if(userInput_ == "")
        exit(0);
    }

    void NetworkInterface::printBoard( )
    {
      updateUserBoard();
      outStream_.put("\n");
      outStreamBlack_.put("\n");
      
      for( int y = 0; y<11; ++y )
      {
        for( int x = 0; x<11; ++x )
        {
          outStream_.put(userBoard_[y][x]);
          outStreamBlack_.put(userBoard_[y][x]);
        }

        outStream_.put("\n");
        outStreamBlack_.put("\n");
      }
    }

    void NetworkInterface::printGameConds( )
    {
      // print game conditions
      outStream_ << "In check: " << checkStatus_ << "\n";
      outStream_ << "Move: " << currentTurn_->getTurn() << "\n";
      outStream_ << "Please enter your next move in the following format: source,destination\nExample: A2,A4 (Capital letters)\n";

      outStreamBlack_ << "In check: " << checkStatus_ << "\n";
      outStreamBlack_ << "Move: " << currentTurn_->getTurn() << "\n";
      outStreamBlack_ << "Please enter your next move in the following format: source,destination\nExample: A2,A4 (Capital letters)\n";
    }

    // Prints a message if the user attempts to 
    // make an invalid move.
    void NetworkInterface::invalidMoveMessage( )
    {
      outStream_ << "The move you entered was not valid." << "\n";
      outStream_ << "Please enter a valid move in the format provided." << "\n";

      outStreamBlack_ << "The move you entered was not valid." << "\n";
      outStreamBlack_ << "Please enter a valid move in the format provided." << "\n";
    }

    // Prints a message whenever the user attempts
    // to make a move that leaves them in check.
    void NetworkInterface::inCheckMessage( )
    {
      outStream_ << "You are, or will be, in check." << "\n";
      outStream_ << "Please enter a move so you are not in check." << "\n";

      outStreamBlack_ << "You are, or will be, in check." << "\n";
      outStreamBlack_ << "Please enter a move so you are not in check." << "\n";
    }

    // Prints a message when the game is over, which
    // states which team won the game.
    void NetworkInterface::checkmateStatus( )
    {
      printBoard();

      if(currentTurn_->getTurn() == 'W')
        outStream_ << "Checkmate! Winner: W" << "\n";
      if(currentTurn_->getTurn() == 'B')
        outStream_ << "Checkmate! Winner: B" << "\n";
    }

  }
}
