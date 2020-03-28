#ifndef CHESS_STATUS_H_
#define CHESS_STATUS_H_

#include "Chess.h"
#include "Pieces/Pieces.h"


namespace Chess
{

  class Status
  {
  public:
    //-- types
    typedef Pieces * PiecePtr;

    //-- construction
    Status( );

    //-- public methods
    void     updateCurrentPiece( Pieces * piece );
    void     updateTurn( );
    void     updateCurrentLocation( int row, int col );
    void     updateDestLocation( int row, int col );
    PiecePtr getCurrentPiece( );
    char     getTurn( );

  protected:
    //-- protected members
    PiecePtr currentPiece_;
    char     turn_;
    int      currentRow_;
    int      currentCol_;
    int      destRow_;
    int      destCol_;
  };

}

#endif /* CHESS_STATUS_H_ */
