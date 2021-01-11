#include "State/PathScanState.h"

#include "Scans/Scans.h"
#include "Pieces/Pieces.h"


namespace Chess
{
  namespace State
  {

    void PathScanState::evaluateScanResult( Scans::ScanResultPtr& result )
    {
      pair<int,int> destination = gameState_.moveRequest.back();
      pair<int,int> source      = gameState_.moveRequest.front();
      Pieces::PiecePtr currentPiece = gameState_.board.getPiece(source);
      Pieces::PiecePtr detectedPiece = result->detectedPiece;
      
      if( detectedPiece->getColor() == currentPiece->getColor() )
        throw Exception("The destination specified is blocked by a " + detectedPiece->getType() + " on the same team!", "Pieces::pathScan");
      if( detectedPiece->getRow() != destination.first || detectedPiece->getCol() != destination.second )
        throw Exception("The destination specified is blocked by a " + detectedPiece->getType() + " on the other team!", "Pieces::pathScan");
    }

    BaseState::StatePtr PathScanState::executeImpl()
    {
      DEBUG_CONSOLE_1ARG("State: PATH SCAN");
      
      PiecePtr piece = gameState_.board.getPiece(gameState_.moveRequest.front());
      if( piece->requiresPathScan() )
      {
        Scans::ScanResultPtr result = identifyScan()->execute();
        evaluateScanResult(result);
      }
      return nextState_;
    }

    shared_ptr<BaseScan> PathScanState::identifyScan()
    {
      pair<int,int> destination = gameState_.moveRequest.back();
      pair<int,int> source      = gameState_.moveRequest.front();
      int rowDiff = destination.first - source.first;
      int colDiff = destination.second - source.second;

      using namespace Scans;

      if( rowDiff > 0 && colDiff == 0 )
        return std::make_shared<DownScan>(gameState_.board, source, destination);
      else if( rowDiff < 0 && colDiff == 0 )
        return std::make_shared<UpScan>(gameState_.board, source, destination);
      else if( colDiff > 0 && rowDiff == 0 )
        return std::make_shared<RightScan>(gameState_.board, source, destination);
      else if( colDiff < 0 && rowDiff == 0 )
        return std::make_shared<LeftScan>(gameState_.board, source, destination);
      else if( rowDiff > 0 && colDiff < 0 )
        return std::make_shared<DownLeftScan>(gameState_.board, source, destination);
      else if( rowDiff > 0 && colDiff > 0 )
        return std::make_shared<DownRightScan>(gameState_.board, source, destination);
      else if( rowDiff < 0 && colDiff > 0 )
        return std::make_shared<UpRightScan>(gameState_.board, source, destination);
      else if( rowDiff < 0 && colDiff < 0 )
        return std::make_shared<UpLeftScan>(gameState_.board, source, destination);
      else
        throw Exception("Scan could not be identified because destination is invalid!", "PathScanState::identifyScan");
    }

  }
}
