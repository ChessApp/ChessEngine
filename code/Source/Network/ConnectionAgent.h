#ifndef CHESS_NETWORK_CONNECTIONAGENT_H_
#define CHESS_NETWORK_CONNECTIONAGENT_H_

#include "Chess.h"

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>

#include "Network/Buffer.h"


namespace Chess
{
  namespace Network
  {

    class ConnectionAgent
      : public boost::enable_shared_from_this<ConnectionAgent>  
    {  
    public:
      //-- types
      typedef boost::shared_ptr<ConnectionAgent> ConnectionAgentPtr;
      typedef boost::asio::ip::tcp::socket       Socket;

      //-- construction
      ConnectionAgent( boost::asio::io_service & ioService, bool & pendingUserInput, string & userInput, Buffer & os )
        : outStream_(os),
          socket_(ioService),
          pendingUserInput_(pendingUserInput),
          userInput_(userInput)
      { }  
      
      //-- public methods
      static ConnectionAgentPtr create( boost::asio::io_service & ioService, bool & pendingUserInput, string & userInput, Buffer & os ); 
      Socket & socket( );
      void     start( );
      void     handleRead( const boost::system::error_code & err, size_t bytesTransferred );
      void     handleWrite( const boost::system::error_code & err, size_t bytesTransferred );

    protected:  
      //-- protected members
      Buffer & outStream_;
      Socket   socket_;  
      string   confirmationMsg_ = "";  
      enum     {bufferLength = 1024};  
      char     inputBuffer_[bufferLength];  
      bool &   pendingUserInput_;
      string & userInput_;
    };

  }
}

#endif /* CHESS_NETWORK_CONNECTIONAGENT_H_ */
