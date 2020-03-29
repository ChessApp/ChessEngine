#include "State/OffensiveCheckScanState.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr OffensiveCheckScanState::execute( )
    {
      typedef shared_ptr<PotentialPin>  PotentialPinPtr;
      typedef vector<PotentialPinPtr>   PotentialPinList;
      typedef vector<PiecePtr>          PieceList;

      std::cout << "Offensive check scan state" << std::endl;
      
      status_ = false;
      PotentialPinList & potentialPinList = currentTurn_->getPotentialPinList();
      PieceList & causingCheckList = currentTurn_->getCausingCheckList();
      PiecePtr kingToScan = currentTurn_->getOffensiveKing();
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
        
        if( detectedPiece->getColor() == kingToScan->getColor() )
        {
          potentialPinList.push_back( PotentialPinPtr( new PotentialPin(detectedPiece, currentScan) ) );
        }
        else if( detectedPiece->validDirection(kingToScan->getRow(), kingToScan->getCol()) )
        {
          causingCheckList.push_back(detectedPiece); 
          currentTurn_->addCheckScanData(scanResult);       
          status_ = true; 
        }
      }
      
      if(status_)
        return nextState_;
      else
        return returnState_;
    }

    void OffensiveCheckScanState::configureScans( PiecePtr kingToScan )
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
