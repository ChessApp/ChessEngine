#ifndef CHESS_NETWORK_BUFFER_H_
#define CHESS_NETWORK_BUFFER_H_

#include "Chess.h"

#include <mutex>


namespace Chess
{
  namespace Network
  {

    class Buffer
    {  
    public:
      //-- types

      //-- construction
      Buffer( )
      { }  
      
      //-- public methods
      void   put( string );
      string get( );
      string pop( );
      Buffer & operator<< ( string s )
      {
        put(s);
        return (*this);
      }
      Buffer & operator<< ( char c )
      {
        string temp(1,c);
        put(temp);
        return (*this);
      }

    protected:  
      //-- protected members
      string data_;
      std::mutex m_;
    };

  }
}

#endif /* CHESS_NETWORK_BUFFER_H_ */
