#ifndef BASESTATE_H_
#define BASESTATE_H_

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

// #include "../Interface.h"

namespace Chess
{
  namespace State
  {

    class BaseState
    {
    public:

      inline BaseState ( )
      { }

      virtual void setTransitionStates ( BaseState * nextState, BaseState * returnState ) ;
      virtual BaseState * execute( ) = 0 ;
      // virtual void updateDiagnostics( ) ;

    protected:

      BaseState * nextState_ ;
      BaseState * returnState_ ;
      bool active_ ;
      int runs_ ;
      int returns_ ;
      int nexts_ ;
    };

  }
}

#endif /* BASESTATE_H_ */