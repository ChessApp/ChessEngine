// This header file houses all of the data
// that composes the Pawn 
// class. This class serves to characterize
// each piece with specific data, along with
// data inherited from the Pieces class, which is 
// analyzed by the Mastermind files.
#ifndef CHESS_WHITEPAWN_H_
#define CHESS_WHITEPAWN_H_

#include "Chess.h"
#include "Pieces/Pieces.h"


namespace Chess
{

  class WhitePawn 
    : public Pieces
  {
  public:
    //-- construction
    WhitePawn( const string& name );

    //-- Pieces interface
    virtual bool validDirection( PiecePtr& );
    virtual bool requiresPathScan() const override { return true; }
  };

}

#endif /* CHESS_WHITEPAWN_H_ */
