#include "State/EscapeRouteState.h"

#include "Pieces/Pieces.h"
#include "Pieces/NullPiece.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr EscapeRouteState::execute( )
    {
      std::cout << "Escape route state" << std::endl;

      status_ = false;
      PiecePtr kingToEscape = currentTurn_->getOffensiveKing();
      int originalKingRow = kingToEscape->getRow();
      int originalKingCol = kingToEscape->getCol();
      
      for( int j = -1; j <= 1; j++ )
      {
        for( int i = -1; i <= 1; i++ )
        {
          int destRow = originalKingRow + j;
          int destCol = originalKingCol + i;
          if( kingToEscape->validDirection(destRow, destCol) && kingToEscape->pathScan(destRow, destCol) )
          {
            setPiece(kingToEscape, destRow, destCol);
            configureScans(kingToEscape);
            
            if( !executeScans(kingToEscape) )
              status_ = true;

            returnPiece(kingToEscape, originalKingRow, originalKingCol);
          }
        }
      }     

      if(status_)
        return returnState_;
      else
        return nextState_;
    }

    bool EscapeRouteState::executeScans( PiecePtr kingToEscape )
    {
      while( scanList_.size() )
      {
        BaseScanPtr currentScan = scanList_.back();
        scanList_.pop_back();
        Scanner::ScanResultPtr scanResult = currentScan->execute();
        PiecePtr detectedPiece = scanResult->detectedPiece;

        if( detectedPiece->validDirection(kingToEscape->getRow(), kingToEscape->getCol()) )
          return true;
      }
      return false;
    }

    void EscapeRouteState::setPiece( PiecePtr pieceToSet, int rowToSet, int colToSet )
    {
      pieceToSet->setLocation(rowToSet, colToSet);
      board_->setPiece(pieceToSet, rowToSet, colToSet);
      PiecePtr np( new NullPiece(".. ") );
      np->setLocation(interface_->sourceRow, interface_->sourceCol);
      board_->setPiece(np, interface_->sourceRow, interface_->sourceCol);
    }

    void EscapeRouteState::returnPiece( PiecePtr pieceToReturn, int rowToReturn, int colToReturn )
    {
      pieceToReturn->setLocation(rowToReturn, colToReturn);
      board_->setPiece(pieceToReturn, rowToReturn, colToReturn);
      PiecePtr np( new NullPiece(".. ") );
      np->setLocation(interface_->destRow, interface_->destCol);
      board_->setPiece(np, interface_->destRow, interface_->destCol);
    }

    void EscapeRouteState::configureScans( PiecePtr kingToScan )
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
