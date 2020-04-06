#include "Network/WebServer.h"

#include <boost/bind.hpp>

using namespace boost::asio;  
using ip::tcp; 


namespace Chess
{
  namespace Network
  {

    WebServer::WebServer( boost::asio::io_service & ioService, bool & pendingUserInput, string & userInput )
      : acceptor_(ioService, ip::tcp::endpoint(ip::tcp::v4(), 2345)),
        pendingUserInput_(pendingUserInput),
        userInput_(userInput)
    {  
      startAccept(pendingUserInput, userInput);  
    }

    void WebServer::handleAccept( ConnectionAgent::ConnectionAgentPtr connection, const boost::system::error_code & err )
    {  
      if(!err)
        connection->start();

      startAccept(pendingUserInput_, userInput_);  
    }

    void WebServer::startAccept( bool & pendingUserInput, string & userInput )
    {
      // socket  
      ConnectionAgent::ConnectionAgentPtr connection = ConnectionAgent::create(acceptor_.get_io_service(), pendingUserInput, userInput);  
      // asynchronous accept operation and wait for a new connection.  
      acceptor_.async_accept(
        connection->socket(),  
        boost::bind(&WebServer::handleAccept, this, connection,  
        boost::asio::placeholders::error) );
    }

  }
}
