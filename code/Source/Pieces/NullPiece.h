#ifndef CHESS_NULLPIECE_H_
#define CHESS_NULLPIECE_H_

#include "Chess.h"
#include "Pieces/Pieces.h"


namespace Chess
{

  class NullPiece 
    : public Pieces
  {
  public:
    //-- construction
    NullPiece( const string name );

    //-- Piece interface
    virtual bool validDirection( int destRow, int destCol );
  };

}

#endif /* CHESS_NULLPIECE_H_ */
