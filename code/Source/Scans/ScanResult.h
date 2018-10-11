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
    void addRow( int row ) { rowList_.push_back( row ) ; }
    void addCol( int col ) { colList_.push_back( col ) ; }
    IntList getRowList( ) { return rowList_ ; }
    IntList getColList( ) { return colList_ ; }
  protected:
    bool detection_ ;
    int row_ ;
    int col_ ;
    Pieces * detectedPiece_ ;
    IntList rowList_ ;
    IntList colList_ ;
  } ;

}

#endif /* SCANRESULT_H_ */