#ifndef CHESS_NETWORK_WEBSERVER_H_
#define CHESS_NETWORK_WEBSERVER_H_

#include "Chess.h"

#include <boost/asio.hpp>

#include "Network/ConnectionAgent.h"
#include "Network/Buffer.h"


namespace Chess
{
  namespace Network
  {

    class WebServer
    {
    public:
      //-- types
      typedef boost::asio::ip::tcp::acceptor      Acceptor;
      typedef ConnectionAgent::ConnectionAgentPtr ConnectionAgentPtr;

      //-- construction 
      WebServer( boost::asio::io_service & ioService, bool & pendingUserInput, string & userInput, Buffer & os, size_t port );
      
      //-- public methods
      void handleAccept( ConnectionAgent::ConnectionAgentPtr connection, const boost::system::error_code & err );
      inline ConnectionAgentPtr getConnection() const { return connection_; }

    protected:  
      //-- protected methods
      void startAccept( bool & pendingUserInput, string & userInput );

      //-- protected members
      Acceptor acceptor_;
      bool &   pendingUserInput_;
      string & userInput_;
      ConnectionAgentPtr connection_;
      Buffer &           outStream_;
    };  

  }
}

#endif /* CHESS_NETWORK_WEBSERVER_H_ */
