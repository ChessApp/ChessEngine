
#ifndef DUALAXISSCAN_H_
#define DUALAXISSCAN_H_

#include <string>
#include <sstream>
#include <vector>

#include "Scanner.h"
#include "../Pieces/Pieces.h"


using namespace std;

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