#ifndef CHESS_NETWORK_NETWORKINTERFACE_H_
#define CHESS_NETWORK_NETWORKINTERFACE_H_

#include "Chess.h"
#include "Interface.h"

#include <thread>
#include <boost/asio.hpp>

#include "Network/WebServer.h"
#include "Network/Buffer.h"


namespace Chess
{
  namespace Network
  {

    class NetworkInterface
      : public Interface
    {
    public:
      //-- construction
      NetworkInterface( BoardPtr board, BaseTurnPtr & currentTurn );

      //-- Interface override
      virtual void getInput( );
      virtual void printBoard( );
      virtual void printGameConds( );
      virtual void invalidMoveMessage( );
      virtual void inCheckMessage( );
      virtual void checkmateStatus( );

    protected:
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
        //-- types
        typedef shared_ptr<WebServer> WebServerPtr;

        //-- construction
        inline NetworkThread( boost::asio::io_service & ios )
          : ioService_(ios)
        { }

        //-- public methods
        void operator() ( )
        {
          ioService_.run();
        }

      protected:
        boost::asio::io_service & ioService_;
      };

      typedef shared_ptr<WebServer> WebServerPtr;

      // void printBoard( string & output );
    
      //-- protected members
      Buffer                    outStream_;
      Buffer                    outStreamBlack_;
      bool                      pendingUserInput_;
      bool                      pendingUserInputBlack_;
      boost::asio::io_service   ioService_;
      boost::asio::io_service   ioServiceBlack_;
      WebServerPtr              webServer_;
      WebServerPtr              webServerBlack_;
      NetworkThread             networkThread_;
      std::thread               networkHandle_;
      NetworkThread             networkThreadBlack_;
      std::thread               networkHandleBlack_;
    };

  }
}

#endif /* CHESS_NETWORK_NETWORKINTERFACE_H_ */
