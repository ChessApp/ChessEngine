#include "Network/NetworkInterface.h"


namespace Chess
{
  namespace Network
  {

    NetworkInterface::NetworkInterface( BoardPtr board, BaseTurnPtr & currentTurn )
      : Interface(board, currentTurn),
        pendingUserInput_(true),
        ioService_(),
        webServer_(new WebServer(ioService_, pendingUserInput_, userInput_)),
        networkThread_(ioService_),
        networkHandle_(networkThread_)
    { }

    void NetworkInterface::getInput( )
    {
      cout << currentTurn_->getTurn() << "'s move: ";

      // A blocking semaphore should probably be implemented here...
      // For now, we just block on an empty while loop. The network
      // thread has access to this flag, and will set it false once
      // it successfully reads any messages sent to its TCP port.
      while(pendingUserInput_) { }

      // Immediately set the flag true again, so the network thread must
      // break the while loop again on the next iteration.
      pendingUserInput_ = true;

      // string msg = "huncho";
      // string & output = webServer_->getConnection()->getOutputBuffer();
      string output = "";
      printBoard(output);
      webServer_->getConnection()->send(output);

      cout << userInput_ << endl;

      if(userInput_ == "")
        exit(0);
    }

    void NetworkInterface::printBoard( string & output )
    {
      updateUserBoard();

      for( int y = 0; y<11; ++y )
      {
        for( int x = 0; x<11; ++x )
          output.append(userBoard_[y][x]);

        output.append("\n");
      }
    }

  }
}
