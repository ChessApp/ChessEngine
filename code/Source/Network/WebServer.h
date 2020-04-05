#ifndef CHESS_NETWORK_WEBSERVER_H_
#define CHESS_NETWORK_WEBSERVER_H_

#include "Chess.h"

#include <boost/asio.hpp>

#include "Network/ConnectionAgent.h"


namespace Chess
{
  namespace Network
  {

    class WebServer
    {
    public:
      //-- types
      typedef boost::asio::ip::tcp::acceptor Acceptor;

      //-- construction 
      WebServer( boost::asio::io_service & ioService, bool & pendingUserInput, string & userInput );
      
      //-- public methods
      void handleAccept( ConnectionAgent::ConnectionAgentPtr connection, const boost::system::error_code & err );

    protected:  
      //-- protected methods
      void startAccept( bool & pendingUserInput, string & userInput );

      //-- protected members
      Acceptor acceptor_;
      bool &   pendingUserInput_;
      string & userInput_;
    };  

  }
}

#endif /* CHESS_NETWORK_WEBSERVER_H_ */
