#ifndef CHESS_STATE_UTILITY_TEMPORARYPIECEREMOVER_H_
#define CHESS_STATE_UTILITY_TEMPORARYPIECEREMOVER_H_

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
  }
}

#endif /* CHESS_STATE_UTILITY_TEMPORARYPIECEREMOVER_H_ */
