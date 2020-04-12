#include "Network/ConnectionAgent.h"

#include <chrono>
#include <thread>

#include <boost/bind.hpp>

using namespace boost::asio;  
using ip::tcp;


namespace Chess
{
  namespace Network
  {

    ConnectionAgent::ConnectionAgentPtr ConnectionAgent::create( boost::asio::io_service & ioService, bool & pendingUserInput, string & userInput, Buffer & os )
    {
      return ConnectionAgentPtr( new ConnectionAgent(ioService, pendingUserInput, userInput, os) );
    }

    ConnectionAgent::Socket & ConnectionAgent::socket()
    {
      return socket_;
    }

    void ConnectionAgent::start()
    {
      socket_.async_read_some(
        boost::asio::buffer(inputBuffer_, bufferLength),  
        boost::bind(&ConnectionAgent::handleRead,  
        shared_from_this(),  
        boost::asio::placeholders::error,  
        boost::asio::placeholders::bytes_transferred) );  
  
      socket_.async_write_some(
        boost::asio::buffer(confirmationMsg_, bufferLength),  
        boost::bind(&ConnectionAgent::handleWrite,  
        shared_from_this(),  
        boost::asio::placeholders::error,  
        boost::asio::placeholders::bytes_transferred) );  
    }

    void ConnectionAgent::handleRead( const boost::system::error_code & err, size_t bytesTransferred )
    {
      if(!err)
      {
        // Only read the input stream if it is a valid time to be getting user input.
        if(pendingUserInput_)
        {
          // copy the contents of the inputBuffer (char * buffer) to a temporary string...
          // This is a roundabout way to convert a char * type to a string using c++ string
          // constructor semantics
          string temp(inputBuffer_);
          // set the content of the temporary string equal to our shared memory address...
          // updating this memory address affects the main game engine thread...
          // this is not a thread-safe way of managing memory and should probably be fixed
          // soon...
          userInput_ = temp;
          // clear the content of the input buffer to start fresh next time traffic
          // enters the port
          memset(inputBuffer_, 0, sizeof inputBuffer_);
          // signal to the main game engine thread that user input is available...
          // again, this is not thread-safe...we should probably use a semaphore or
          // some other thread-safe construct here...
          pendingUserInput_ = false;
        }
      }   
      else
      {
        socket_.close();  
      }  
    }

    void ConnectionAgent::handleWrite( const boost::system::error_code & err, size_t bytesTransferred )
    {
      if(err)
      {
        cout << "handleWrite" << endl;
        std::cerr << "error: " << err.message() << endl;  
        socket_.close();  
      }
      else
      {
        // Add the delimiter signal to the end of the stream before sending it.
        outStream_.put("\r\n\r\n");
        boost::asio::write( socket_, boost::asio::buffer(outStream_.pop()) );
      }
    }

  }
}
