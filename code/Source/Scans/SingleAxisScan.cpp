#include "Scans/SingleAxisScan.h"


namespace Chess
{

  SingleAxisScan::SingleAxisScan( BoardPtr board )
    : Scanner(board)
  { }

  void SingleAxisScan::identifyScan( int sourceRow, int sourceCol, int destRow, int destCol )
  {
    int rowDiff = destRow - sourceRow;
    int colDiff = destCol - sourceCol;

    if ( rowDiff > 0 )
      scan_ = new DownScan( board_, sourceRow, sourceCol, destRow, destCol );
    else if ( rowDiff < 0 )
      scan_ = new UpScan( board_, sourceRow, sourceCol, destRow, destCol );
    else if ( colDiff > 0 )
      scan_ = new RightScan( board_, sourceRow, sourceCol, destRow, destCol );
    else if ( colDiff < 0 )
      scan_ = new LeftScan( board_, sourceRow, sourceCol, destRow, destCol );
    else
      cout << "Error: No scan identified." << endl;
  }

  Scanner::ScanResultPtr SingleAxisScan::execute( )
  {
    return scan_->execute( ) ;
  }

}
