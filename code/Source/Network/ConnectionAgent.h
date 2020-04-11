#ifndef CHESS_NETWORK_CONNECTIONAGENT_H_
#define CHESS_NETWORK_CONNECTIONAGENT_H_

#include "Chess.h"

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>


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
      ConnectionAgent( boost::asio::io_service & ioService, bool & pendingUserInput, string & userInput )
        : socket_(ioService),
          pendingUserInput_(pendingUserInput),
          userInput_(userInput)
      { }  
      
      //-- public methods
      static ConnectionAgentPtr create( boost::asio::io_service & ioService, bool & pendingUserInput, string & userInput ); 
      Socket & socket( );
      void     start( );
      void     handleRead( const boost::system::error_code & err, size_t bytesTransferred );
      void     handleWrite( const boost::system::error_code & err, size_t bytesTransferred );
      void     send( string outboundData );
      // string & getOutputBuffer() const { return confirmationMsg_; }

    protected:  
      //-- protected members
      Socket   socket_;  
      string   confirmationMsg_ = "Server received input!";  
      enum     {bufferLength = 1024};  
      char     inputBuffer_[bufferLength];  
      bool &   pendingUserInput_;
      string & userInput_;
    };

  }
}

#endif /* CHESS_NETWORK_CONNECTIONAGENT_H_ */
