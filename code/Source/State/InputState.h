#ifndef CHESS_STATE_INPUTSTATE_H_
#define CHESS_STATE_INPUTSTATE_H_

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
      //-- construction
      inline InputState( Interface * interface ) 
        : interface_(interface)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );
      
    protected:
      //-- protected members
      Interface * interface_;
    };

  }
}

#endif /* CHESS_STATE_INPUTSTATE_H_ */
