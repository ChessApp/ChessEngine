#ifndef SINGLEAXISSCAN_H_
#define SINGLEAXISSCAN_H_

#include "Chess.h"
#include "Scans/Scanner.h"
#include "Pieces/Pieces.h"


namespace Chess
{

  class SingleAxisScan
    : public Scanner
  {

  public:

    friend class Board ;

    SingleAxisScan ( Board * board ) ;
    virtual void identifyScan ( int sourceRow, int sourceCol, int destRow, int destCol ) ;

    virtual ScanResult * execute ( ) ;

  protected:

    

  };

}

#endif /* SINGLEAXISSCAN_H_ */