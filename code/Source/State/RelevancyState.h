#ifndef CHESS_STATE_RELEVANCYSTATE_H_
#define CHESS_STATE_RELEVANCYSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "Interface.h"


namespace Chess
{
  namespace State
  {

    class RelevancyState
      : public BaseState
    {
    public:
      //-- construction
      inline RelevancyState( Interface * interface ) 
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

#endif /* CHESS_STATE_RELEVANCYSTATE_H_ */
