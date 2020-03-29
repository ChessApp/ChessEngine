#include "State/DefensiveCheckScanState.h"

#include "Pieces/Pieces.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr DefensiveCheckScanState::execute( )
    {
      std::cout << "Defensive check scan state" << std::endl;
      
      status_ = false;
      PiecePtr kingToScan = currentTurn_->getDefensiveKing();
      configureScans(kingToScan);
      Scanner::ScanResultPtr scanResult;
      PiecePtr detectedPiece;
      BaseScanPtr currentScan;

      while( scanList_.size() )
      {
        currentScan = scanList_.back();
        scanList_.pop_back();
        scanResult = currentScan->execute();
        detectedPiece = scanResult->detectedPiece;
        if( detectedPiece->validDirection(kingToScan->getRow(), kingToScan->getCol()) )
        {
          if( detectedPiece->getColor() != kingToScan->getColor() )
          {
            status_ = true;
            break;
          } 
        }
      }
      scanList_.erase( scanList_.begin(), scanList_.end() );

      if(status_)
      {
        cout << "This move will put you in check." << endl;
        return returnState_;
      }
      else
      {
        currentTurn_->deactivatePiece();
        return nextState_;
      }
      
    }

    void DefensiveCheckScanState::configureScans( PiecePtr kingToScan )
    {
      scanList_.push_back( BaseScanPtr( new Scanner::LeftScan(      board_, kingToScan->getRow( ), kingToScan->getCol( ), kingToScan->getRow( ), 0 ) ) );
      scanList_.push_back( BaseScanPtr( new Scanner::RightScan(     board_, kingToScan->getRow( ), kingToScan->getCol( ), kingToScan->getRow( ), 7 ) ) );
      scanList_.push_back( BaseScanPtr( new Scanner::UpScan(        board_, kingToScan->getRow( ), kingToScan->getCol( ), 0, kingToScan->getCol( ) ) ) );
      scanList_.push_back( BaseScanPtr( new Scanner::DownScan(      board_, kingToScan->getRow( ), kingToScan->getCol( ), 7, kingToScan->getCol( ) ) ) );
      scanList_.push_back( BaseScanPtr( new Scanner::UpLeftScan(    board_, kingToScan->getRow( ), kingToScan->getCol( ), 0, 0 ) ) );
      scanList_.push_back( BaseScanPtr( new Scanner::DownLeftScan(  board_, kingToScan->getRow( ), kingToScan->getCol( ), 7, 0 ) ) );
      scanList_.push_back( BaseScanPtr( new Scanner::UpRightScan(   board_, kingToScan->getRow( ), kingToScan->getCol( ), 0, 7 ) ) );
      scanList_.push_back( BaseScanPtr( new Scanner::DownRightScan( board_, kingToScan->getRow( ), kingToScan->getCol( ), 7, 7 ) ) );
    }

  }
}