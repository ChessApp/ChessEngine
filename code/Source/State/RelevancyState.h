#ifndef RELEVANCYSTATE_H_
#define RELEVANCYSTATE_H_

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
      virtual BaseState * execute( ) ;

      inline RelevancyState ( Interface * interface ) 
        : interface_(interface)
      { }
      
    protected:
      Interface * interface_ ;

    };

  }
}

#endif /* RELEVANCYSTATE_H_ */