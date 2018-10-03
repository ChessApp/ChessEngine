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
    else if ( rowDiff < 0 )
    {
      scan_ = new UpScan( board, sourceRow, sourceCol ) ;
    }
    else if ( colDiff > 0 )
    {
      scan_ = new RightScan( board, sourceRow, sourceCol ) ;
    }
    else if ( colDiff < 0 )
    {
      scan_ = new LeftScan( board, sourceRow, sourceCol ) ;
    }
    else
    {
      cout << "Error: No scan identified." << endl ;
    }
  }

  Pieces * SingleAxisScan::execute ( )
  {
    return scan_->execute( ) ;
  }

}