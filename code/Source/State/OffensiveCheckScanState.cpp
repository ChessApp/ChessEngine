#include "State/OffensiveCheckScanState.h"

#include "Pieces/Pieces.h"
#include "Scans/Scans.h"
#include "Scans/BaseScan.h"


namespace Chess
{
  namespace State
  {

    typedef shared_ptr<BaseScan> BaseScanPtr;
    typedef vector<BaseScanPtr>  ScanList;
    typedef shared_ptr<Pieces>   PiecePtr;

    namespace
    {
      void configureScans( ScanList& scanList, Board& board, const GameState::Coordinates& scanSource )
      {
        scanList.push_back( std::make_shared<Scans::LeftScan>(      board, scanSource, pair<int,int>{scanSource.first, 0} ) );
        scanList.push_back( std::make_shared<Scans::RightScan>(     board, scanSource, pair<int,int>{scanSource.first, 7} ) );
        scanList.push_back( std::make_shared<Scans::UpScan>(        board, scanSource, pair<int,int>{0, scanSource.second} ) );
        scanList.push_back( std::make_shared<Scans::DownScan>(      board, scanSource, pair<int,int>{7, scanSource.second} ) );
        scanList.push_back( std::make_shared<Scans::UpLeftScan>(    board, scanSource, pair<int,int>{0, 0} ) );
        scanList.push_back( std::make_shared<Scans::DownLeftScan>(  board, scanSource, pair<int,int>{7, 0} ) );
        scanList.push_back( std::make_shared<Scans::UpRightScan>(   board, scanSource, pair<int,int>{0, 7} ) );
        scanList.push_back( std::make_shared<Scans::DownRightScan>( board, scanSource, pair<int,int>{7, 7} ) );
      }

      bool executeScans( GameState& gameState, ScanList& scanList, PiecePtr& kingToScan )
      {
        bool inCheck = false;
        for( auto scan : scanList )
        {
          PiecePtr detectedPiece = scan->execute()->detectedPiece;
          if( detectedPiece->getColor() == kingToScan->getColor() )
          {
            gameState.potentialPins.push_back( std::make_shared<PotentialPin>(detectedPiece, scan) );
          }
          else if( detectedPiece->validDirection(kingToScan) )
          {
            inCheck = true;
            gameState.checkInducers.push_back(detectedPiece);
          }
        }
        return inCheck;
      }
    }

    BaseState::StatePtr OffensiveCheckScanState::executeImpl()
    {
      PiecePtr kingToScan = gameState_.getKingUnderAttack();
      ScanList scanList;
      configureScans(scanList, gameState_.board, kingToScan->getLocation());
      if( executeScans(gameState_, scanList, kingToScan) )
        return nextState_;
      else
        return returnState_;
    }

  }
}
