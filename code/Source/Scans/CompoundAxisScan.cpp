#include "CompoundAxisScan.h"

namespace Chess
{

  CompoundAxisScan::CompoundAxisScan ( Board * board )
    : Scanner (board )
  {

  }

  void CompoundAxisScan::executeScans ( int sourceRow, int sourceCol )
  {
    upLeftScan( sourceRow, sourceCol ) ;
    upRightScan( sourceRow, sourceCol ) ;
    downLeftScan( sourceRow, sourceCol ) ;
    downRightScan( sourceRow, sourceCol ) ;
    leftScan( sourceRow, sourceCol ) ;
    rightScan( sourceRow, sourceCol ) ;
    downScan( sourceRow, sourceCol ) ;
    upScan( sourceRow, sourceCol ) ;
  }

}