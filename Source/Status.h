#ifndef STATUS_H_
#define STATUS_H_

#include <string>
#include <sstream>

#include "Pieces/Pieces.h"
#include "Board.h"
#include "Interface.h"

using namespace std;

namespace Chess
{

  class Status
  {

    typedef Chess::Pieces Pieces;

  protected:

    Pieces * currentPiece;
    char turn;
    int currentRow;
    int currentCol;
    int destRow;
    int destCol;

  public:

    Status ( );

    void updateCurrentPiece ( Pieces * piece );

    void updateTurn ( );

    void updateCurrentLocation ( int row, int col );

    void updateDestLocation ( int row, int col );

    Pieces * getCurrentPiece ( );

    char getTurn ( );

  };

}

#endif /* STATUS_H_ */