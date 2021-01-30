#ifndef CHESS_STATE_UTILITY_TEMPORARYPIECEMOVER_H_
#define CHESS_STATE_UTILITY_TEMPORARYPIECEMOVER_H_

#include "Chess.h"
#include "State/BaseState.h"


namespace Chess
{
  namespace State
  {
    namespace Utility
    {

      // RAII-style class for removing a piece from the board and
      // then returning it when the object goes out of scope.
      class TemporaryPieceMover
      {
      public:
        typedef shared_ptr<Pieces> PiecePtr;

        TemporaryPieceMover( Board& board, PiecePtr& sourcePiece, const pair<int,int>& destination )
          : board(board),
            sourcePiece(sourcePiece),
            destinationPiece(board.getPiece(destination)),
            sourceLocation(sourcePiece->getLocation()),
            destinationLocation(destination)
        {
          this->board.movePiece(this->sourcePiece, this->destinationLocation);
        }

        ~TemporaryPieceMover()
        {
          this->board.setPiece(this->sourcePiece, this->sourceLocation);
          this->board.setPiece(this->destinationPiece, this->destinationLocation);
        }

      private:
        Board&               board;
        PiecePtr             sourcePiece;
        PiecePtr             destinationPiece;
        const pair<int,int>& sourceLocation;
        const pair<int,int>& destinationLocation;
      };

    }
  }
}

#endif /* CHESS_STATE_UTILITY_TEMPORARYPIECEMOVER_H_ */
