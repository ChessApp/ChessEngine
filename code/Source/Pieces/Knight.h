// This header file houses all of the data
// that composes the Knight 
// class. This class serves to characterize
// each piece with specific data, along with
// data inherited from the Pieces class, which is 
// analyzed by the Mastermind files.
#ifndef CHESS_KNIGHT_H_
#define CHESS_KNIGHT_H_

#include "Chess.h"
#include "Pieces/Pieces.h"


namespace Chess
{

  class Knight 
    : public Pieces
  {
  public:
    //-- construction
    Knight ( const string name, int initRow, int initCol );
    Knight ( const string name );

    //-- Piece interface
    virtual bool pathScan( int destRow, int destCol );
    virtual bool validDirection( int destRow, int destCol );    
  };

}

#endif /* CHESS_KNIGHT_H_ */
