// This header file houses all of the data
// that composes the King 
// class. This class serves to characterize
// each piece with specific data, along with
// data inherited from the Pieces class, which is 
// analyzed by the Mastermind files.
#ifndef CHESS_KING_H_
#define CHESS_KING_H_

#include "Chess.h"
#include "Pieces/Pieces.h"
#include "Scans/Scanner.h"


namespace Chess
{

  class King 
    : public Pieces
  {
  public:
    //-- types
    
    //-- construction
    King( const string name, Board& board, int initRow, int initCol );
    King( const string name, Board& board );

    //-- Piece interface
    virtual bool pathScan( int destRow, int destCol );
    virtual bool validDirection( int destRow, int destCol );

  protected:
    //-- protected types
    typedef shared_ptr<Scanner> ScannerPtr;

    //-- protected members
    ScannerPtr scanner_;
  };

}

#endif /* CHESS_KING_H_ */
