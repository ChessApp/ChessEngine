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
    NullPiece( const string& name, const pair<int,int>& location = {0,0} );

    //-- Piece interface
    virtual bool validDirection( PiecePtr& );
    virtual bool requiresPathScan() const override { return false; }
  };

}

#endif /* CHESS_NULLPIECE_H_ */
