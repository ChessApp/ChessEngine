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
#include "Scans/Scanner.h"


namespace Chess
{

  class Rook 
    : public Pieces
  {
  public:
    //-- types
    typedef shared_ptr<Board> BoardPtr;
    
    //-- construction
    Rook( const string name, BoardPtr board, int initRow, int initCol );
    Rook( const string name, BoardPtr board );

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

#endif /* CHESS_ROOK_H_ */
