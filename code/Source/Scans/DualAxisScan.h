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
    DualAxisScan( Board& board );

    //-- Scanner interface
    virtual void identifyScan( const pair<int,int>& source, const pair<int,int>& destination );
    virtual ScanResultPtr execute( );
  };

}

#endif /* CHESS_DUALAXISSCAN_H_ */