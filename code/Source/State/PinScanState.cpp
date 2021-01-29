#include "State/PinScanState.h"

#include "PotentialPin.h"
#include "Scans/BaseScan.h"
#include "Board.h"
#include "Pieces/Pieces.h"


namespace Chess
{
  namespace State
  {

    namespace
    {
      // RAII-style class for removing a piece from the board and
      // then returning it when the object goes out of scope.
      class TemporaryPieceRemover
      {
      public:
        typedef shared_ptr<Pieces> PiecePtr;

        TemporaryPieceRemover( Board& board, PiecePtr& piece )
          : board(board),
            piece(piece)
        {
          this->board.clrPiece(this->piece);
        }

        ~TemporaryPieceRemover()
        {
          this->board.setPiece(this->piece, this->piece->getLocation());
        }

      private:
        Board&    board;
        PiecePtr& piece;
      };
    }

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

        // RAII-style removal of potentially-pinned piece from board.
        TemporaryPieceRemover remover(gameState_.board, pinnedPiece);

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
      }

      if( gameState_.pinnedPieces.size() > 0 )
        return nextState_;
      else
        return returnState_;
    }

  }
}
