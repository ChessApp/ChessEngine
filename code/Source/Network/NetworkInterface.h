#ifndef CHESS_NETWORK_NETWORKINTERFACE_H_
#define CHESS_NETWORK_NETWORKINTERFACE_H_

#include "Chess.h"
#include "Interface.h"

#include <thread>


namespace Chess
{
  namespace Network
  {

    class NetworkInterface
      : public Interface
    {
    public:
      //-- construction
      NetworkInterface( BoardPtr board, BaseTurnPtr & currentTurn );

      //-- Interface override
      virtual void getInput( );

    protected:
      //-- protected members
      bool   pendingUserInput_;
      thread networkHandle_;
    };

  }
}

#endif /* CHESS_NETWORK_NETWORKINTERFACE_H_ */
