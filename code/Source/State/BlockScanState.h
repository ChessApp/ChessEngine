#ifndef CHESS_STATE_BLOCKSCANSTATE_H_
#define CHESS_STATE_BLOCKSCANSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"


namespace Chess
{
  namespace State
  {

    class BlockScanState
      : public BaseState
    {
    public:
      //-- types

      //-- construction
      inline BlockScanState( GameState& gameState ) 
        : BaseState(gameState, "BlockScanState")
      { }

      //-- BaseState interface
      StatePtr executeImpl();

    protected:
      //-- protected members
    };

  }
}

#endif /* CHESS_STATE_BLOCKSCANSTATE_H_ */
