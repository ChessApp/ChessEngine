#include "Network/Buffer.h"


namespace Chess
{
  namespace Network
  {

    void Buffer::put( string data )
    {
      std::lock_guard<std::mutex> g(m_);
      data_.append(data);
    }

    string Buffer::get( )
    {
      std::lock_guard<std::mutex> g(m_);
      return data_;
    }

    string Buffer::pop( )
    {
      std::lock_guard<std::mutex> g(m_);
      string data = data_;
      data_ = "";
      return data;
    }

  }
}
