#ifndef CHESS_STATE_BLOCKSCANSTATE_H_
#define CHESS_STATE_BLOCKSCANSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "BaseTurn.h"


namespace Chess
{
  namespace State
  {

    class BlockScanState
      : public BaseState
    {
    public:
      //-- construction
      inline BlockScanState( BaseTurn *& currentTurn ) 
        : currentTurn_(currentTurn)
      { }

      //-- BaseState interface
      StatePtr execute( );

    protected:
      //-- protected members
      BaseTurn *& currentTurn_;
    };

  }
}

#endif /* CHESS_STATE_BLOCKSCANSTATE_H_ */
