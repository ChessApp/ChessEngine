#include "SingleAxisScan.h"

namespace Chess
{

  SingleAxisScan::SingleAxisScan ( Board * board )
    : Scanner ( board )
  {

  }

  bool SingleAxisScan::executeScans ( int sourceRow, int sourceCol )
  {
    upScan( sourceRow, sourceCol ) ;
    rightScan( sourceRow, sourceCol ) ;
    leftScan( sourceRow, sourceCol ) ;
    downScan( sourceRow, sourceCol ) ;

    return true ;
  }

}