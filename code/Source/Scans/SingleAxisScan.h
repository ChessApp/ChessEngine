
#ifndef SINGLEAXISSCAN_H_
#define SINGLEAXISSCAN_H_

#include <string>
#include <sstream>
#include <vector>

#include "Scanner.h"
#include "../Pieces/Pieces.h"


using namespace std;

namespace Chess
{

  class SingleAxisScan
    : public Scanner
  {

  public:

    friend class Board ;

    SingleAxisScan ( Board * board ) ;
    virtual void identifyScan ( int sourceRow, int sourceCol, int destRow, int destCol ) ;

    virtual Pieces * execute ( ) ;

  protected:

    

  };

}

#endif /* SINGLEAXISSCAN_H_ */