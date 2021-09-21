#include "State/EscapeRouteState.h"

#include "Pieces/Pieces.h"
#include "Scans/Scans.h"
#include "Scans/BaseScan.h"
#include "State/Utility/TemporaryPieceMover.h"
#include "State/Utility/PathScan.h"
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
      /* Executes a scan in every direction from the location of the King
         that is attempting to escape. If another piece is detected on any
         of these scans, the piece will be checked to see if it can attack
         on the scan path, and that it is on the opposite team. This method
         returns true if the escape route cannot be attacked.
      */
      bool executeScans( ScanList& scanList, PiecePtr kingToEscape )
      {
        for( auto scan : scanList )
        {
          PiecePtr detectedPiece = scan->execute()->detectedPiece;

          // Verify that the detected piece can attack the king, and that they are on opposite
          // teams.
          if( detectedPiece->validDirection(kingToEscape) )
          {
            if( kingToEscape->getColor() != detectedPiece->getColor() )
            {
              PLOG_DEBUG << "Escape attempt soiled by: " << detectedPiece->getType() << " at [" << detectedPiece->getRow() << "," << detectedPiece->getCol() << "]" << endl;
              return false;
            }
          }
        }

        return true;
      }

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
    }

    BaseState::StatePtr EscapeRouteState::executeImpl()
    {
      PiecePtr kingToEscape = gameState_.getKingUnderAttack();
      int originalKingRow = kingToEscape->getRow();
      int originalKingCol = kingToEscape->getCol();
      
      for( int j = -1; j <= 1; j++ )
      {
        for( int i = -1; i <= 1; i++ )
        {
          try
          {
            const pair<int,int> dest = {originalKingRow + j, originalKingCol + i};
            auto pieceAtDestination = gameState_.board.getPiece(dest);
            if( kingToEscape->validDirection(pieceAtDestination) &&
                Utility::PathScan::execute(gameState_.board, kingToEscape, dest) )
            {
              Utility::TemporaryPieceMover mover(gameState_.board, kingToEscape, dest);

              // Check if there are any pieces that can still attack on this
              // attempted escape route.
              ScanList scanList;
              configureScans(scanList, gameState_.board, kingToEscape->getLocation());
              bool escapeRoutePresent = executeScans(scanList, kingToEscape);

              // Transition to the ReturnState if there is an escape route.
              // *sigh of relief*
              if(escapeRoutePresent)
                return returnState_;
            }
          }
          catch( Board::BoardException& e )
          {

          }
        }
      }     
      return nextState_;
    }

  }
}
