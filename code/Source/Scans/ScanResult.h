#ifndef CHESS_SCANRESULT_H_
#define CHESS_SCANRESULT_H_

#include "Chess.h"
#include "Pieces/Pieces.h"


namespace Chess
{

  class ScanResult
  {
  public:
    //-- types
    typedef vector<int> IntList;

    //-- construction
    inline ScanResult( ) { }

    //-- methods
    inline void    addSquare( int row, int col ) { rowList_.push_back( row ); colList_.push_back( col ); }
    inline IntList getRowList( ) { return rowList_; }
    inline IntList getColList( ) { return colList_; }

    //-- public members
    bool     detection;
    int      row;
    int      col;
    Pieces * detectedPiece;

  protected:
    //-- protected members
    IntList rowList_ ;
    IntList colList_ ;
  };

}

#endif /* CHESS_SCANRESULT_H_ */
