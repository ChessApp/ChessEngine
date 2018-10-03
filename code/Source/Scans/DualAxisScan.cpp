#include "DualAxisScan.h"

namespace Chess
{

  DualAxisScan::DualAxisScan ( Board * board )
    : Scanner ( board )
  {

  }

  void DualAxisScan::identifyScan ( int sourceRow, int sourceCol, int destRow, int destCol )
  {
    int rowDiff = destRow - sourceRow ;
    int colDiff = destCol - sourceCol ;
    if ( rowDiff > 0 )
    {
      scan_ = new DownLeftScan( board, sourceRow, sourceCol ) ;
    }
  }

  Pieces * DualAxisScan::execute ( )
  {
    return scan_->execute( ) ;
  }

}