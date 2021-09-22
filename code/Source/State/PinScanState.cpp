#include "State/PinScanState.h"

#include "PotentialPin.h"
#include "Scans/BaseScan.h"
#include "Board.h"
#include "Pieces/Pieces.h"
#include "State/Utility/TemporaryPieceRemover.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr PinScanState::executeImpl()
    {
      typedef shared_ptr<BaseScan> BaseScanPtr;

      auto kingToScan = gameState_.getKingUnderAttack();

      for( auto potentialPin : gameState_.potentialPins )
      {
        auto pinnedPiece = potentialPin->getPiece();
        BaseScanPtr scanToExecute = potentialPin->getScanToExecute();

        // RAII-style removal of potentially-pinned piece from board.
        Utility::TemporaryPieceRemover remover(gameState_.board, pinnedPiece);

        auto detectedPiece = scanToExecute->execute()->detectedPiece;
        if( detectedPiece->validDirection(kingToScan) )
        {
          // Only pieces from the offensive team can pin a defending piece.
          if( detectedPiece->getColor() != kingToScan->getColor() )
          {
            gameState_.pinnedPieces.insert({pinnedPiece->getId(), pinnedPiece});
            pinnedPiece->setPinned();
          }
        }
      }
      return nextState_;
    }

  }
}
