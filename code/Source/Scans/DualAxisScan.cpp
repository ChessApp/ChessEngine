#include "Scans/DualAxisScan.h"


namespace Chess
{

  DualAxisScan::DualAxisScan( Board * board )
    : Scanner(board)
  { }

  void DualAxisScan::identifyScan( int sourceRow, int sourceCol, int destRow, int destCol )
  {
    int rowDiff = destRow - sourceRow;
    int colDiff = destCol - sourceCol;

    if( rowDiff > 0 && colDiff < 0 )
      scan_ = new DownLeftScan( board_, sourceRow, sourceCol, destRow, destCol );
    else if( rowDiff > 0 && colDiff > 0 )
      scan_ = new DownRightScan( board_, sourceRow, sourceCol, destRow, destCol );
    else if( rowDiff < 0 && colDiff > 0 )
      scan_ = new UpRightScan( board_, sourceRow, sourceCol, destRow, destCol );
    else if( rowDiff < 0 && colDiff < 0 )
      scan_ = new UpLeftScan( board_, sourceRow, sourceCol, destRow, destCol );
    else
      std::cout << "Scan could not be identified because destination is invalid." << std::endl;
  }

  ScanResult * DualAxisScan::execute( )
  {
    return scan_->execute();
  }

}
