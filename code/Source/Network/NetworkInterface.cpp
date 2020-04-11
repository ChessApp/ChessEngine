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
        outStream_(),
        webServer_(new WebServer(ioService_, pendingUserInput_, userInput_, outStream_)),
        networkThread_(ioService_),
        networkHandle_(networkThread_)
    { }

    void NetworkInterface::getInput( )
    {
      outStream_ << currentTurn_->getTurn();
      outStream_ << "'s move: ";

      // A blocking semaphore should probably be implemented here...
      // For now, we just block on an empty while loop. The network
      // thread has access to this flag, and will set it false once
      // it successfully reads any messages sent to its TCP port.
      while(pendingUserInput_) { }
      // std::this_thread::sleep_for(std::chrono::milliseconds(3000));

      // Immediately set the flag true again, so the network thread must
      // break the while loop again on the next iteration.
      pendingUserInput_ = true;

      cout << userInput_ << endl;

      if(userInput_ == "")
        exit(0);
    }

    void NetworkInterface::printBoard( )
    {
      updateUserBoard();
      outStream_.put("\n");
      
      for( int y = 0; y<11; ++y )
      {
        for( int x = 0; x<11; ++x )
          outStream_.put(userBoard_[y][x]);

        outStream_.put("\n");
      }
    }

    void NetworkInterface::printGameConds( )
    {
      // print game conditions
      outStream_ << "In check: " << checkStatus_ << "\n";
      outStream_ << "Move: " << currentTurn_->getTurn() << "\n";
      outStream_ << "Please enter your next move in the following format: source,destination\nExample: A2,A4 (Capital letters)\n";
    }

    // Prints a message if the user attempts to 
    // make an invalid move.
    void NetworkInterface::invalidMoveMessage( )
    {
      outStream_ << "The move you entered was not valid." << "\n";
      outStream_ << "Please enter a valid move in the format provided." << "\n";
    }

    // Prints a message whenever the user attempts
    // to make a move that leaves them in check.
    void NetworkInterface::inCheckMessage( )
    {
      outStream_ << "You are, or will be, in check." << "\n";
      outStream_ << "Please enter a move so you are not in check." << "\n";
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
