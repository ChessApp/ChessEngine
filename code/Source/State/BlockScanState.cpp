#include "State/BlockScanState.h"
#include "State/Utility/PathScan.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr BlockScanState::executeImpl()
    {
      for( auto s : gameState_.checkPaths )
      {
        for( auto threatPiece : gameState_.checkInducers )
        {
          for( auto defendingPiecePair : gameState_.activePieces )
          {
            int defendingPieceId = defendingPiecePair.first;
            auto defendingPiece = defendingPiecePair.second;

            // Pieces must be on the defending team to be eligible.
            if( defendingPiece->getColor() != gameState_.getKingUnderAttack()->getColor() )
              continue;

            // A King cannot block itself. Ignore the king as a potential defending piece.
            if( defendingPiece->getType() != "K" )
            {
              // Check if the defending piece can move anywhere on the attack path to block it.
              for( int it = 0; it < s->getRowList().size(); it++ )
              {
                int row = s->getRowList()[it];
                int col = s->getColList()[it];
                auto p = gameState_.board.getPiece({row, col});
                // Defending piece must be able to move to the square, cannot be blocked, and also cannot be pinned.
                if( defendingPiece->validDirection(p) &&
                    Utility::PathScan::execute(gameState_.board, defendingPiece, {row, col}) &&
                    !defendingPiece->getPinnedStatus() )
                {
                  PLOG_DEBUG << "Type: " << defendingPiece->getType()
                             << " Color: " << defendingPiece->getColor()
                             << " can neutralize threat from"
                             << " Row: " << row
                             << " Col: " << col;
                  return returnState_;
                }
              }
              // Check if the defending piece can attack the threat piece.
              if( defendingPiece->validDirection(threatPiece) &&
                  Utility::PathScan::execute(gameState_.board, defendingPiece, threatPiece->getLocation()) &&
                  !defendingPiece->getPinnedStatus() )
              {
                PLOG_DEBUG << "Type: " << defendingPiece->getType()
                           << " Color: " << defendingPiece->getColor()
                           << " can neutralize threat from"
                           << " Row: " << defendingPiece->getRow()
                           << " Col: " << defendingPiece->getCol();
                return returnState_;
              }
            }
          }
        }
      }      
      return nextState_;
    }

  }
}
