#include "State/PathScanState.h"

#include "Scans/Scans.h"
#include "Pieces/Pieces.h"
#include "State/Utility/PathScan.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr PathScanState::executeImpl()
    {
      auto piece = gameState_.board.getPiece(gameState_.moveRequest.front());
      if( !Utility::PathScan::execute(gameState_.board, piece, gameState_.moveRequest.back()) )
        throw Exception("The path to the desired destination is not valid!", "PathScanState::executeImpl");
      return nextState_;
    }

  }
}
