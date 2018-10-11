#ifndef SCANRESULT_H_
#define SCANRESULT_H_

#include <string>
#include <sstream>
#include <vector>

#include "../Pieces/Pieces.h"
#include "../Board.h"

using namespace std;

namespace Chess
{

  class ScanResult
  {
  public:
    typedef vector< int > IntList ;
    inline ScanResult( ) { }
    ~ScanResult( ) ;
    void addSquare( int row, int col ) { rowList_.push_back( row ) ; colList_.push_back( col ) ; }
    IntList getRowList( ) { return rowList_ ; }
    IntList getColList( ) { return colList_ ; }

    bool detection ;
    int row ;
    int col ;
    Pieces * detectedPiece ;

  protected:
    
    IntList rowList_ ;
    IntList colList_ ;
  } ;

}

#endif /* SCANRESULT_H_ */