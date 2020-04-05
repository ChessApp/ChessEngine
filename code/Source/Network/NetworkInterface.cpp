#include "Network/NetworkInterface.h"

#include <boost/asio.hpp>

#include "Network/WebServer.h"


namespace Chess
{
  namespace Network
  {

    /* Defines an object function operator for starting and
     * running the the network thread. The implementation of
     * the function operator defines the startup code for the
     * asynchronous thread. The WebServer object is created and
     * enables the IO Service, which ultimately listens to a TCP
     * port and then updates memory shared between the network 
     * thread and the game engine thread. Splitting networking
     * into a separate thread allows the game engine to operate
     * while the network thread can maintain a socket with the TCP
     * port.
     */
    class NetworkThread
    {
    public:
      //-- construction
      inline NetworkThread( bool & pending, string & userInput )
        : pending_(pending),
          userInput_(userInput)
      { }

      //-- public methods
      void operator() ( )
      {
        boost::asio::io_service ioService;
        WebServer webServer(ioService, pending_, userInput_);
        ioService.run();
      }

    protected:
      //-- protected members
      bool &   pending_;
      string & userInput_;
    };

    NetworkInterface::NetworkInterface( BoardPtr board, BaseTurnPtr & currentTurn )
      : Interface(board, currentTurn),
        pendingUserInput_(true),
        networkHandle_(NetworkThread(pendingUserInput_, userInput_))
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

      cout << userInput_ << endl;

      if(userInput_ == "")
        exit(0);
    }

  }
}
