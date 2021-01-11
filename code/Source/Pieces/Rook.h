// This header file houses all of the data
// that composes the Rook 
// class. This class serves to characterize
// each piece with specific data, along with
// data inherited from the Pieces class, which is 
// analyzed by the Mastermind files.
#ifndef CHESS_ROOK_H_
#define CHESS_ROOK_H_

#include "Chess.h"
#include "Pieces/Pieces.h"


namespace Chess
{

  class Rook 
    : public Pieces
  {
  public:
    //-- types
    
    //-- construction
    Rook( const string& name );

    //-- Piece interface
    virtual bool validDirection( const pair<int,int>& destination );
    virtual bool requiresPathScan() const override { return true; }

  protected:
    //-- protected types

    //-- protected members
  };

}

#endif /* CHESS_ROOK_H_ */
