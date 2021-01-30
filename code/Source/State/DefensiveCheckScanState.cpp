#include "State/DefensiveCheckScanState.h"

#include "Pieces/Pieces.h"
#include "Scans/Scans.h"
#include "Scans/BaseScan.h"
#include "Board.h"


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

      void executeScans( ScanList& scanList, PiecePtr& kingToScan )
      {
        for( auto scan : scanList )
        {
          PiecePtr detectedPiece = scan->execute()->detectedPiece;
          if( !detectedPiece->validDirection(kingToScan) )
            continue;
          if( detectedPiece->getColor() != kingToScan->getColor() )
            throw Exception("This move will put you in check!", "DefensiveCheckScanState::executeImpl");
        }
      }
    }

    BaseState::StatePtr DefensiveCheckScanState::executeImpl()
    {
      PiecePtr kingToScan = gameState_.getKingOfAttacker();
      ScanList scanList;
      configureScans(scanList, gameState_.board, kingToScan->getLocation());
      executeScans(scanList, kingToScan);

      return nextState_;
    }

  }
}