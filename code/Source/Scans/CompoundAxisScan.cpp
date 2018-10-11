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
    if ( rowDiff > 0 && colDiff == 0 )
    {
      scan_ = new DownLeftScan( board_, sourceRow, sourceCol, destRow, destCol ) ;
    }
    else if ( rowDiff < 0 && colDiff == 0 )
    {
      scan_ = new UpScan( board_, sourceRow, sourceCol, destRow, destCol ) ;
    }
    else if ( colDiff > 0 && rowDiff == 0 )
    {
      scan_ = new RightScan( board_, sourceRow, sourceCol, destRow, destCol ) ;
    }
    else if ( colDiff < 0 && rowDiff == 0 )
    {
      scan_ = new LeftScan( board_, sourceRow, sourceCol, destRow, destCol ) ;
    }
    else if ( rowDiff > 0 && colDiff < 0 )
    {
      scan_ = new DownLeftScan( board_, sourceRow, sourceCol, destRow, destCol ) ;
    }
    else if ( rowDiff > 0 && colDiff > 0 )
    {
      scan_ = new DownRightScan( board_, sourceRow, sourceCol, destRow, destCol ) ;
    }
    else if ( rowDiff < 0 && colDiff > 0 )
    {
      scan_ = new UpRightScan( board_, sourceRow, sourceCol, destRow, destCol ) ;
    }
    else if ( rowDiff < 0 && colDiff < 0 )
    {
      scan_ = new UpLeftScan( board_, sourceRow, sourceCol, destRow, destCol ) ;
    }
    else
    {
      std::cout << "Scan could not be identified because destination is invalid." << std::endl ;
    }
  }

  ScanResult * CompoundAxisScan::execute ( )
  {
    return scan_->execute( ) ;
  }

}