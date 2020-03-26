#ifndef INPUTSTATE_H_
#define INPUTSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "Interface.h"


namespace Chess
{
  namespace State
  {

    class InputState
      : public BaseState
    {
    public:
      virtual BaseState * execute( ) ;

      inline InputState ( Interface * interface ) 
        : interface_(interface)
      { }
      
    protected:
      Interface * interface_ ;

    };

  }
}

#endif /* INPUTSTATE_H_ */