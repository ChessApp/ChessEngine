#ifndef CHESS_STATE_UTILITY_PATHSCAN_H_
#define CHESS_STATE_UTILITY_PATHSCAN_H_

#include "Chess.h"
#include "GameState.h"
#include "Pieces/Pieces.h"


namespace Chess
{
  namespace State
  {
    namespace Utility
    {
      namespace PathScan
      {

        bool execute( Board& board, Pieces::PiecePtr& sourcePiece, const pair<int,int>& destination );

      }
    }
  }
}

#endif /* CHESS_STATE_UTILITY_PATHSCAN_H_ */
