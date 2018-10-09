#include "OffensiveCheckScanState.h"

namespace Chess
{
  namespace State
  {

    BaseState * OffensiveCheckScanState::execute ( )
    {
      std::cout << "Offensive check scan state" << std::endl ;
      
      status_ = false ;
      Pieces * kingToScan = currentTurn_->getOffensiveKing( ) ;
      configureScans( kingToScan ) ;
      Pieces * detectedPiece ;
      BaseScan * currentScan ;
      while ( scanList_.size( ) )
      {
        currentScan = scanList_.back( ) ;
        scanList_.pop_back( ) ;
        detectedPiece = currentScan->execute( ) ;
        if ( detectedPiece->validDirection( kingToScan->getRow( ), kingToScan->getCol( ) ) )
        {
          if ( detectedPiece->getColor( ) != kingToScan->getColor( ) )
          {
            status_ = true ;
            break ;
          } 
        }
      }
      scanList_.erase( scanList_.begin( ), scanList_.end( ) ) ;

      if ( status_ )
      {
        return nextState_ ;
      }
      else
      {
        return returnState_ ;
      }
      
    }

    void OffensiveCheckScanState::configureScans( Pieces * kingToScan )
    {
      scanList_.push_back( new Scanner::LeftScan( board_, kingToScan->getRow( ), kingToScan->getCol( ), kingToScan->getRow( ), 0 ) ) ;
      scanList_.push_back( new Scanner::RightScan( board_, kingToScan->getRow( ), kingToScan->getCol( ), kingToScan->getRow( ), 7 ) ) ;
      scanList_.push_back( new Scanner::UpScan( board_, kingToScan->getRow( ), kingToScan->getCol( ), 0, kingToScan->getCol( ) ) ) ;
      scanList_.push_back( new Scanner::DownScan( board_, kingToScan->getRow( ), kingToScan->getCol( ), 7, kingToScan->getCol( ) ) ) ;
      scanList_.push_back( new Scanner::UpLeftScan( board_, kingToScan->getRow( ), kingToScan->getCol( ), 0, 0 ) ) ;
      scanList_.push_back( new Scanner::DownLeftScan( board_, kingToScan->getRow( ), kingToScan->getCol( ), 7, 0 ) ) ;
      scanList_.push_back( new Scanner::UpRightScan( board_, kingToScan->getRow( ), kingToScan->getCol( ), 0, 7 ) ) ;
      scanList_.push_back( new Scanner::DownRightScan( board_, kingToScan->getRow( ), kingToScan->getCol( ), 7, 7 ) ) ;
    }

  }
}