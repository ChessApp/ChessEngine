#include "DualAxisScan.h"

namespace Chess
{

  DualAxisScan::DualAxisScan ( Board * board )
    : Scanner ( board )
  {

  }

  void DualAxisScan::executeScans ( int sourceRow, int sourceCol )
  {
    upLeftScan( sourceRow, sourceCol ) ;
    upRightScan( sourceRow, sourceCol ) ;
    downLeftScan( sourceRow, sourceCol ) ;
    downRightScan( sourceRow, sourceCol ) ;
  }

}