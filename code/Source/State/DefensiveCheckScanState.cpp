#include "State/DefensiveCheckScanState.h"

#include "Tools/pugixml/pugixml.hpp"

#include "Pieces/Pieces.h"
#include "Scans/Scans.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr DefensiveCheckScanState::executeImpl()
    {
      PiecePtr kingToScan = gameState_.getDefensiveKing();
      configureScans(kingToScan);
      Scans::ScanResultPtr scanResult;
      PiecePtr detectedPiece;
      BaseScanPtr currentScan;

      while( scanList_.size() )
      {
        currentScan = scanList_.back();
        scanList_.pop_back();
        scanResult = currentScan->execute();
        detectedPiece = scanResult->detectedPiece;
        try
        {
          detectedPiece->validDirection(kingToScan);
        }
        catch(...)
        {
          continue;
        }
        if( detectedPiece->getColor() != kingToScan->getColor() )
        {
          status_ = true;
          break;
        }
      }

      if(status_)
        throw Exception("This move will put you in check!", "DefensiveCheckScanState::executeImpl");

      return nextState_;
    }

    void DefensiveCheckScanState::configureScans( PiecePtr kingToScan )
    {
      scanList_.push_back( BaseScanPtr( new Scans::LeftScan(      gameState_.board, kingToScan->getLocation(), {kingToScan->getRow( ), 0} ) ) );
      scanList_.push_back( BaseScanPtr( new Scans::RightScan(     gameState_.board, kingToScan->getLocation(), {kingToScan->getRow( ), 7} ) ) );
      scanList_.push_back( BaseScanPtr( new Scans::UpScan(        gameState_.board, kingToScan->getLocation(), {0, kingToScan->getCol( )} ) ) );
      scanList_.push_back( BaseScanPtr( new Scans::DownScan(      gameState_.board, kingToScan->getLocation(), {7, kingToScan->getCol( )} ) ) );
      scanList_.push_back( BaseScanPtr( new Scans::UpLeftScan(    gameState_.board, kingToScan->getLocation(), {0, 0} ) ) );
      scanList_.push_back( BaseScanPtr( new Scans::DownLeftScan(  gameState_.board, kingToScan->getLocation(), {7, 0} ) ) );
      scanList_.push_back( BaseScanPtr( new Scans::UpRightScan(   gameState_.board, kingToScan->getLocation(), {0, 7} ) ) );
      scanList_.push_back( BaseScanPtr( new Scans::DownRightScan( gameState_.board, kingToScan->getLocation(), {7, 7} ) ) );
    }

  }
}