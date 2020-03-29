#ifndef CHESS_STATE_CHECKMATESTATE_H_
#define CHESS_STATE_CHECKMATESTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "Interface.h"


namespace Chess
{
  namespace State
  {

    class CheckmateState
      : public BaseState
    {
    public:
      //-- types
      typedef shared_ptr<Interface> InterfacePtr;

      //-- construction
      inline CheckmateState( InterfacePtr interface ) 
        : interface_(interface)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );
 
    protected:
      //-- protected members
      InterfacePtr interface_;
    };

  }
}

#endif /* CHESS_STATE_CHECKMATESTATE_H_ */
