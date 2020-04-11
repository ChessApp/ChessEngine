#include "Network/WebServer.h"

#include <boost/bind.hpp>

using namespace boost::asio;  
using ip::tcp; 


namespace Chess
{
  namespace Network
  {

    WebServer::WebServer( boost::asio::io_service & ioService, bool & pendingUserInput, string & userInput, Buffer & os )
      : acceptor_(ioService, ip::tcp::endpoint(ip::tcp::v4(), 2345)),
        pendingUserInput_(pendingUserInput),
        userInput_(userInput),
        connection_( ConnectionAgentPtr() ),
        outStream_(os)
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
      connection_ = ConnectionAgent::create(acceptor_.get_io_service(), pendingUserInput, userInput, outStream_);  
      // asynchronous accept operation and wait for a new connection.  
      acceptor_.async_accept(
        connection_->socket(),  
        boost::bind(&WebServer::handleAccept, this, connection_,  
        boost::asio::placeholders::error) );
    }

  }
}
