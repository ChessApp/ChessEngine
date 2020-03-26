#ifndef DUALAXISSCAN_H_
#define DUALAXISSCAN_H_

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

    DualAxisScan ( Board * board ) ;
    virtual void identifyScan ( int sourceRow, int sourceCol, int destRow, int destCol ) ;

    virtual ScanResult * execute ( ) ;

  protected:    

  };

}

#endif /* DUALAXISSCAN_H_ */