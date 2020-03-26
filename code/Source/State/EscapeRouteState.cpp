#include "State/EscapeRouteState.h"

namespace Chess
{
  namespace State
  {

    BaseState * EscapeRouteState::execute ( )
    {
      std::cout << "Escape route state" << std::endl ;

      status_ = false ;
      Pieces * kingToEscape = currentTurn_->getOffensiveKing( ) ;
      int originalKingRow = kingToEscape->getRow( ) ;
      int originalKingCol = kingToEscape->getCol( ) ;
      
      for ( int j = -1; j <= 1; j++ )
      {
        for ( int i = -1; i <= 1; i++ )
        {
          int destRow = originalKingRow + j ;
          int destCol = originalKingCol + i ;
          if ( kingToEscape->validDirection( destRow, destCol ) && kingToEscape->pathScan( destRow, destCol ) )
          {
            setPiece( kingToEscape, destRow, destCol ) ;
            configureScans( kingToEscape ) ;
            if ( !executeScans( kingToEscape ) )
            {
              status_ = true ;
            }
            returnPiece( kingToEscape, originalKingRow, originalKingCol ) ;
          }
        }
      }     

      if ( status_ )
      {
        return returnState_ ;
      }
      else
      {
        return nextState_ ;
      }
      
    }

    bool EscapeRouteState::executeScans( Pieces * kingToEscape )
    {
      while ( scanList_.size( ) )
      {
        BaseScan * currentScan = scanList_.back( ) ;
        scanList_.pop_back( ) ;
        ScanResult * scanResult = currentScan->execute( ) ;
        Pieces * detectedPiece = scanResult->detectedPiece ;
        if ( detectedPiece->getColor( ) == kingToEscape->getColor( ) )
        {
        }
        else if ( detectedPiece->validDirection( kingToEscape->getRow( ), kingToEscape->getCol( ) ) )
        {        
          return true ;
        }
      }
      return false ;
    }

    void EscapeRouteState::setPiece( Pieces * pieceToSet, int rowToSet, int colToSet )
    {
      pieceToSet->setLocation( rowToSet, colToSet ) ;
      board_->setPiece( pieceToSet, rowToSet, colToSet ) ;
      Pieces * np = new NullPiece( ".. " ) ;
      np->setLocation( interface_->sourceRow, interface_->sourceCol ) ;
      board_->setPiece( np, interface_->sourceRow, interface_->sourceCol ) ;
    }

    void EscapeRouteState::returnPiece( Pieces * pieceToReturn, int rowToReturn, int colToReturn )
    {
      pieceToReturn->setLocation( rowToReturn, colToReturn ) ;
      board_->setPiece( pieceToReturn, rowToReturn, colToReturn ) ;
      Pieces * np = new NullPiece( ".. " ) ;
      np->setLocation( interface_->destRow, interface_->destCol ) ;
      board_->setPiece( np, interface_->destRow, interface_->destCol ) ;
    }

    void EscapeRouteState::configureScans( Pieces * kingToScan )
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