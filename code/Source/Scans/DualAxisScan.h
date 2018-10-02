
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

    typedef Chess::Pieces Pieces ;
    typedef Chess::Board Board ;
    typedef Chess::Status Status ;  

    friend class Board ;

    DualAxisScan ( Board * board ) ;

    virtual bool executeScans ( int sourceRow, int sourceCol ) ;

  protected:    

  };

}

#endif /* DUALAXISSCAN_H_ */