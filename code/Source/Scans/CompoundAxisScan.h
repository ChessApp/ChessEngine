#ifndef COMPOUNDAXISSCAN_H_
#define COMPOUNDAXISSCAN_H_

#include "Chess.h"
#include "Scans/Scanner.h"
#include "Pieces/Pieces.h"


namespace Chess
{

  class CompoundAxisScan
    : public Scanner
  {

  public:
 

    friend class Board ;

    CompoundAxisScan ( Board * board ) ;
    virtual void identifyScan ( int sourceRow, int sourceCol, int destRow, int destCol ) ;

    virtual ScanResult * execute ( ) ;

  protected:

    
   

  };

}

#endif /* COMPOUNDAXISSCAN_H_ */