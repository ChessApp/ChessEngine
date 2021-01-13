#ifndef CHESS_STATE_DEFENSIVECHECKSCANSTATE_H_
#define CHESS_STATE_DEFENSIVECHECKSCANSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "GameState.h"
#include "Scans/BaseScan.h"
#include "Pieces/Pieces.h"


namespace Chess
{
  namespace State
  {

    class DefensiveCheckScanState
      : public BaseState
    {
    public:
      //-- types
      typedef shared_ptr<BaseScan> BaseScanPtr;
      typedef shared_ptr<Pieces>   PiecePtr;

      //-- construction
      inline DefensiveCheckScanState( GameState& gameState ) 
        : BaseState(gameState, "DefensiveCheckScanState"),
          status_(false)
      { }

      //-- BaseState interface
      virtual StatePtr executeImpl();
      
    protected:
      //-- protected methods
      void updateGameState();
      void configureScans( PiecePtr kingToScan );

      //-- protected members
      vector<BaseScanPtr>  scanList_;
      bool                 status_;
    };

  }
}

#endif /* CHESS_STATE_DEFENSIVECHECKSCANSTATE_H_ */
