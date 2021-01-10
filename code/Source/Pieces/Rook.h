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
    
    //-- construction
    Rook( const string name, Board& board );

    //-- Piece interface
    virtual bool pathScan( const pair<int,int>& destination );
    virtual bool validDirection( const pair<int,int>& destination );

  protected:
    //-- protected types
    typedef shared_ptr<Scanner> ScannerPtr;

    //-- protected members
    ScannerPtr scanner_;
  };

}

#endif /* CHESS_ROOK_H_ */
