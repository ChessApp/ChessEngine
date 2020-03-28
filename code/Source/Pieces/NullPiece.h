// This header file houses all of the data
// that composes the NullPiece 
// class. This class serves to characterize
// each piece with specific data, along with
// data inherited from the Pieces class, which is 
// analyzed by the Mastermind files.
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
