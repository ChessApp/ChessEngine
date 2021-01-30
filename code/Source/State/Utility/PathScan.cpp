#include "State/Utility/PathScan.h"
#include "Scans/Scans.h"


namespace Chess
{
  namespace State
  {
    namespace Utility
    {
      namespace PathScan
      {

        shared_ptr<BaseScan> identifyScan( Board& board, const pair<int,int>& source, const pair<int,int>& destination )
        {
          int rowDiff = destination.first - source.first;
          int colDiff = destination.second - source.second;

          using namespace Scans;

          if( rowDiff > 0 && colDiff == 0 )
            return std::make_shared<DownScan>(board, source, destination);
          else if( rowDiff < 0 && colDiff == 0 )
            return std::make_shared<UpScan>(board, source, destination);
          else if( colDiff > 0 && rowDiff == 0 )
            return std::make_shared<RightScan>(board, source, destination);
          else if( colDiff < 0 && rowDiff == 0 )
            return std::make_shared<LeftScan>(board, source, destination);
          else if( rowDiff > 0 && colDiff < 0 )
            return std::make_shared<DownLeftScan>(board, source, destination);
          else if( rowDiff > 0 && colDiff > 0 )
            return std::make_shared<DownRightScan>(board, source, destination);
          else if( rowDiff < 0 && colDiff > 0 )
            return std::make_shared<UpRightScan>(board, source, destination);
          else if( rowDiff < 0 && colDiff < 0 )
            return std::make_shared<UpLeftScan>(board, source, destination);
          else
            throw Exception("Scan could not be identified because destination is invalid!", "Utility::PathScan::identifyScan");
        }

        bool evaluateScanResult( Board& board, Scans::ScanResultPtr& result, const pair<int,int>& source, const pair<int,int>& destination )
        {
          Pieces::PiecePtr currentPiece = board.getPiece(source);
          Pieces::PiecePtr detectedPiece = result->detectedPiece;
          
          if( detectedPiece->getType() == "" )
            return true;
          if( detectedPiece->getColor() == currentPiece->getColor() )
            return false;
          if( detectedPiece->getRow() != destination.first || detectedPiece->getCol() != destination.second )
            return false;

          return true;
        }

        bool execute( Board& board, Pieces::PiecePtr& sourcePiece, const pair<int,int>& destination )
        {
          if( sourcePiece->requiresPathScan() )
          {
            Scans::ScanResultPtr result = identifyScan(board, sourcePiece->getLocation(), destination)->execute();
            return evaluateScanResult(board, result, sourcePiece->getLocation(), destination);
          }
          return true;
        }

      }
    }
  }
}
