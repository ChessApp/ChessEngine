#include "SingleAxisScan.h"

namespace Chess
{

  SingleAxisScan::SingleAxisScan ( Board * board )
    : Scanner ( board )
  {

  }

  void SingleAxisScan::identifyScan ( int sourceRow, int sourceCol, int destRow, int destCol )
  {
    int rowDiff = destRow - sourceRow ;
    int colDiff = destCol - sourceCol ;
    if ( rowDiff > 0 )
    {
      scan_ = new DownScan( board, sourceRow, sourceCol ) ;
    }
  }

  Pieces * SingleAxisScan::execute ( )
  {
    return scan_->execute( ) ;
  }

}