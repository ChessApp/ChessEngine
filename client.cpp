#include <iostream>
#include <chrono>
#include <thread>

#include <boost/asio.hpp>  
  
using namespace boost::asio;  
using ip::tcp;  
using std::string;  
using std::cout;  
using std::endl; 

/* Erase all Occurrences of given substring from main string.
 */
void eraseAllSubStr(std::string & mainStr, const std::string & toErase)
{
  size_t pos = std::string::npos;
 
  // Search for the substring in string in a loop untill nothing is found
  while ((pos  = mainStr.find(toErase) )!= std::string::npos)
  {
    // If found then erase it from string
    mainStr.erase(pos, toErase.length());
  }
}

int main()
{
  bool init = true;
  while(1)
  {
    boost::asio::io_service io_service;  
    
    //socket creation  
    tcp::socket socket(io_service);  
    
    //connection  
    socket.connect( tcp::endpoint( boost::asio::ip::address::from_string("127.0.0.1"), 2345 ) );
    
    // getting a response from the server  
    boost::asio::streambuf receive_buffer;
    boost::system::error_code     error;
    boost::asio::read_until(socket, receive_buffer, "\r\n\r\n", error);
    if( error && error != boost::asio::error::eof )
    {  
      cout << "receive failed: " << error.message() << endl;  
    }  
    else
    {  
      const char * data = boost::asio::buffer_cast<const char *>(receive_buffer.data());
      string stringData(data);
      eraseAllSubStr(stringData, "\r\n\r\n");
      cout << stringData;  
    }

    string input;
    // // request/message from client
    // cout << "Please enter a move: " << endl;
    std::getline(std::cin, input);
    
    const string msg = input;  
    boost::asio::write( socket, boost::asio::buffer(msg), error );
    if( !error )
    { 
    }  
    else
    {  
      cout << "send failed: " << error.message() << endl;  
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
  }

  return 0;  
}  
