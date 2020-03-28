#ifndef CHESS_DUALAXISSCAN_H_
#define CHESS_DUALAXISSCAN_H_

#include "Chess.h"
#include "Scans/Scanner.h"
#include "Pieces/Pieces.h"


namespace Chess
{

  class DualAxisScan
    : public Scanner
  {
  public:
    friend class Board ;

    //-- construction
    DualAxisScan( Board * board );

    //-- Scanner interface
    virtual void identifyScan( int sourceRow, int sourceCol, int destRow, int destCol );
    virtual ScanResult * execute( );
  };

}

#endif /* CHESS_DUALAXISSCAN_H_ */