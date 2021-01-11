#ifndef CHESS_STATE_PATHSCANSTATE_H_
#define CHESS_STATE_PATHSCANSTATE_H_

#include "Chess.h"

#include "State/BaseState.h"
#include "GameState.h"
#include "Scans/Scans.h"
#include "Scans/BaseScan.h"


namespace Chess
{
  namespace State
  {

    class PathScanState
      : public BaseState
    {
    public:
      //-- types

      //-- construction
      inline PathScanState( GameState& gameState ) 
        : BaseState(gameState, "PathScanState")
      { }

      //-- BaseState interface
      virtual StatePtr executeImpl() override;
      
    protected:
      //-- protected methods
      shared_ptr<BaseScan> identifyScan();
      void evaluateScanResult(Scans::ScanResultPtr&);

      //-- protected members
    };

  }
}

#endif /* CHESS_STATE_PATHSCANSTATE_H_ */
