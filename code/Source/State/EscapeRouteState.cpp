#include "State/EscapeRouteState.h"

#include "Pieces/Pieces.h"
#include "Pieces/NullPiece.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr EscapeRouteState::execute( )
    {
      DEBUG_CONSOLE_1ARG("State: ESCAPE ROUTE");

      bool escapeRoute = false;
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
            // Stash the original piece at the destination location
            // so we can return it after scan.
            PiecePtr originalPiece = board_->getPiece(destRow, destCol);

            setPiece(kingToEscape, destRow, destCol);
            configureScans(kingToEscape);

            // Check if there are any valid escape routes.
            if( !executeScans(kingToEscape) )
              escapeRoute = true;

            returnPiece(kingToEscape, originalKingRow, originalKingCol, originalPiece);
          }
        }
      }     

      if(escapeRoute)
        return returnState_;
      else
        return nextState_;
    }

    /* Executes a scan in every direction from the location of the King
       that is attempting to escape. If another piece is detected on any
       of these scans, the piece will be checked to see if it can attack
       on the scan path, and that it is on the opposite team. This method
       returns true if there are any valid escape routes.
     */
    bool EscapeRouteState::executeScans( PiecePtr kingToEscape )
    {
      while( scanList_.size() )
      {
        BaseScanPtr currentScan = scanList_.back();
        scanList_.pop_back();
        Scanner::ScanResultPtr scanResult = currentScan->execute();
        PiecePtr detectedPiece = scanResult->detectedPiece;

        // Verify that the detected piece can attack the king, and that they are on opposite
        // teams.
        if( detectedPiece->validDirection(kingToEscape->getRow(), kingToEscape->getCol()) )
          if( kingToEscape->getColor() != detectedPiece->getColor() )
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

    void EscapeRouteState::returnPiece( PiecePtr pieceToReturn, int rowToReturn, int colToReturn, PiecePtr originalPiece )
    {
      // Reset the location of the pieceToReturn.
      pieceToReturn->setLocation(rowToReturn, colToReturn);

      // Update the new piece locations on the board.
      board_->setPiece(pieceToReturn, rowToReturn, colToReturn);
      board_->setPiece(originalPiece, originalPiece->getRow(), originalPiece->getCol());
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
