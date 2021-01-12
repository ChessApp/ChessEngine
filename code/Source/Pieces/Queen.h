// This header file houses all of the data
// that composes the Queen 
// class. This class serves to characterize
// each piece with specific data, along with
// data inherited from the Pieces class, which is 
// analyzed by the Mastermind files.
#ifndef CHESS_QUEEN_H_
#define CHESS_QUEEN_H_

#include "Chess.h"
#include "Pieces/Pieces.h"


namespace Chess
{

  class Queen 
    : public Pieces
  {
  public:
    //-- types

    //-- construction
    Queen( const string& name );

    //-- Piece interface
    virtual bool validDirection( PiecePtr& );
    virtual bool requiresPathScan() const override { return true; }

  protected:
    //-- protected types

    //-- protected members
  };

}

#endif /* CHESS_QUEEN_H_ */
