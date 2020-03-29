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
#include "Scans/Scanner.h"


namespace Chess
{

  class Queen 
    : public Pieces
  {
  public:
    //-- types
    typedef shared_ptr<Board> BoardPtr;

    //-- construction
    Queen( const string name, BoardPtr board, int initRow, int initCol );
    Queen( const string name, BoardPtr board );

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

#endif /* CHESS_QUEEN_H_ */
