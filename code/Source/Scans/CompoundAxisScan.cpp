#include "CompoundAxisScan.h"

namespace Chess
{

  CompoundAxisScan::CompoundAxisScan ( Board * board )
    : Scanner (board )
  {

  }

  void CompoundAxisScan::identifyScan ( int sourceRow, int sourceCol, int destRow, int destCol )
  {
    int rowDiff = destRow - sourceRow ;
    int colDiff = destCol - sourceCol ;
    if ( rowDiff > 0 )
    {
      scan_ = new DownLeftScan( board_, sourceRow, sourceCol, destRow, destCol ) ;
    }
  }

  Pieces * CompoundAxisScan::execute ( )
  {
    return scan_->execute( ) ;
  }

}