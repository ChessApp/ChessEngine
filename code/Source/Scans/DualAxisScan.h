
#ifndef DUALAXISSCAN_H_
#define DUALAXISSCAN_H_

#include <string>
#include <sstream>
#include <vector>

#include "Scanner.h"
#include "../Pieces/Pieces.h"


using namespace std;

namespace Chess
{

  class DualAxisScan
    : public Scanner
  {

  public:

    typedef Chess::Pieces Pieces ;
    typedef Chess::Board Board ;
    typedef Chess::Status Status ;  

    friend class Board ;

    DualAxisScan ( Board * board ) ;

  protected:

    virtual void executeScans ( int sourceRow, int sourceCol ) ;

    virtual ScanResult upLeftScan ( int sourceRow, int sourceCol ) ;

    virtual ScanResult upRightScan ( int sourceRow, int sourceCol ) ;

    virtual ScanResult downLeftScan ( int sourceRow, int sourceCol ) ;

    virtual ScanResult downRightScan ( int sourceRow, int sourceCol ) ;

    

  };

}

#endif /* DUALAXISSCAN_H_ */