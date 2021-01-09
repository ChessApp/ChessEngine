// This header file houses all of the data
// that composes the Pawn 
// class. This class serves to characterize
// each piece with specific data, along with
// data inherited from the Pieces class, which is 
// analyzed by the Mastermind files.
#ifndef CHESS_BLACKPAWN_H_
#define CHESS_BLACKPAWN_H_

#include "Chess.h"
#include "Pieces/Pieces.h"


namespace Chess
{

  class BlackPawn 
    : public Pieces
  {
  public:
    //-- construction
    BlackPawn( const string name );

    //-- Piece interface
    virtual bool pathScan( int destRow, int destCol );  
    virtual bool validDirection( int destRow, int destCol );   
  };

}

#endif /* CHESS_BLACKPAWN_H_ */
