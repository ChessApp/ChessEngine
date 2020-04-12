#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

#include <boost/asio.hpp>  
  
using namespace boost::asio;  
using ip::tcp;  
using std::string;  
using std::cout;  
using std::endl; 


bool newInput;
bool turn;
std::mutex m;

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

void pollingThread( )
{
  while(1)
  {
    {
      // cout << "connecting..." << endl;
      std::lock_guard<std::mutex> g(m);

      boost::asio::streambuf    receive_buffer;
      boost::system::error_code error;
      boost::asio::io_service io_service;  
      
      //socket creation  
      tcp::socket socket(io_service);
      socket.connect( tcp::endpoint( boost::asio::ip::address::from_string("127.0.0.1"), 2347 ) );

      // getting a response from the server
      boost::asio::read_until(socket, receive_buffer, "\r\n\r\n", error);
      if( error && error != boost::asio::error::eof )
      {  
        cout << "receive failed: " << error.message() << endl;
      }
      else
      {
        if( receive_buffer.size() > 4 )
        {
          const char * data = boost::asio::buffer_cast<const char *>(receive_buffer.data());
          string stringData(data);
          eraseAllSubStr(stringData, "\r\n\r\n");
          receive_buffer.consume(receive_buffer.size());
          cout << stringData << endl;
          if(stringData != "")
          {
            newInput = true;
            if( stringData.find("B's move") != std::string::npos )
            {
              turn = true;
            }
            else
            {
              turn = false;
            }
          }
        }
      }
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

int main()
{
  newInput = false;

  //connection  
  std::thread pollThread(pollingThread);

  while(1)
  {
    if(newInput && turn)
    {
      newInput = false;
      string input;
      // // request/message from client
      cout << "Please enter a move: " << endl;
      std::getline(std::cin, input);
      
      std::lock_guard<std::mutex> g(m);
      boost::asio::streambuf    receive_buffer;
      boost::system::error_code error;
      boost::asio::io_service io_service;  
        
      //socket creation  
      tcp::socket socket(io_service);
      socket.connect( tcp::endpoint( boost::asio::ip::address::from_string("127.0.0.1"), 2347 ) );

      const string msg = input;  
      boost::asio::write( socket, boost::asio::buffer(msg), error );
      if( !error )
      {
      }  
      else
      {  
        cout << "send failed: " << error.message() << endl;  
      }
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;  
}  
