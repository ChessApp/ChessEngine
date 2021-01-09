#ifndef CHESS_STATE_RELEVANCYSTATE_H_
#define CHESS_STATE_RELEVANCYSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"


namespace Chess
{
  namespace State
  {

    class RelevancyState
      : public BaseState
    {
    public:
      //-- types

      //-- construction
      inline RelevancyState( GameState& gameState ) 
        : BaseState("RelevancyState", gameState)
      { }

      //-- BaseState interface
      virtual StatePtr executeImpl() override;
      
    protected:
      //-- protected methods

      //-- protected members
    };

  }
}

#endif /* CHESS_STATE_RELEVANCYSTATE_H_ */
