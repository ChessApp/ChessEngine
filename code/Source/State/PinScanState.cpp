#include "State/PinScanState.h"

#include "PotentialPin.h"
#include "Scans/BaseScan.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr PinScanState::executeImpl()
    {
      //-- local types
      typedef shared_ptr<PotentialPin>    PotentialPinPtr;
      typedef vector<PotentialPinPtr>     PotentialPinList;
      typedef vector<BaseState::PiecePtr> PieceList;
      typedef shared_ptr<BaseScan>        BaseScanPtr;

      PiecePtr kingToScan = gameState_.getKingUnderAttack();

      for( auto potentialPin : gameState_.potentialPins )
      {
        PiecePtr pinnedPiece = potentialPin->getPiece();
        BaseScanPtr scanToExecute = potentialPin->getScanToExecute();

        gameState_.board.clrPiece(pinnedPiece);
        PiecePtr detectedPiece = scanToExecute->execute()->detectedPiece;

        if( detectedPiece->validDirection(kingToScan) )
        {
          // Only pieces from the offensive team can pin a defending piece.
          if( detectedPiece->getColor() != kingToScan->getColor() )
          {
            gameState_.pinnedPieces.insert({pinnedPiece->getId(), pinnedPiece});
            pinnedPiece->setPinned();
          }
        }

        gameState_.board.setPiece(pinnedPiece, pinnedPiece->getLocation());
      }

      if( gameState_.pinnedPieces.size() > 0 )
        return nextState_;
      else
        return returnState_;
    }

  }
}
