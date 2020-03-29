#ifndef CHESS_DUALAXISSCAN_H_
#define CHESS_DUALAXISSCAN_H_

#include "Chess.h"
#include "Scans/Scanner.h"


namespace Chess
{

  class DualAxisScan
    : public Scanner
  {
  public:
    //-- construction
    DualAxisScan( BoardPtr board );

    //-- Scanner interface
    virtual void identifyScan( int sourceRow, int sourceCol, int destRow, int destCol );
    virtual ScanResultPtr execute( );
  };

}

#endif /* CHESS_DUALAXISSCAN_H_ */