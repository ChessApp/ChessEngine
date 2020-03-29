#ifndef CHESS_COMPOUNDAXISSCAN_H_
#define CHESS_COMPOUNDAXISSCAN_H_

#include "Chess.h"
#include "Scans/Scanner.h"


namespace Chess
{

  class CompoundAxisScan
    : public Scanner
  {
  public:
    //-- construction
    CompoundAxisScan( BoardPtr board );

    //-- Scanner interface
    virtual void identifyScan( int sourceRow, int sourceCol, int destRow, int destCol );
    virtual ScanResultPtr execute( );
  };

}

#endif /* CHESS_COMPOUNDAXISSCAN_H_ */
