#ifndef CHECKMATESTATE_H_
#define CHECKMATESTATE_H_

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
      virtual StatePtr execute( ) ;

      inline CheckmateState ( Interface * interface ) 
        : interface_(interface)
      { }
      
    protected:
      Interface * interface_ ;

    };

  }
}

#endif /* CHECKMATESTATE_H_ */