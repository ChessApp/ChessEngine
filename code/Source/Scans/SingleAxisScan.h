
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

    typedef Chess::Pieces Pieces ;
    typedef Chess::Board Board ;
    typedef Chess::Status Status ; 

    friend class Board ;

    SingleAxisScan ( Board * board ) ;

    virtual bool executeScans ( int sourceRow, int sourceCol ) ;

  protected:

    

  };

}

#endif /* SINGLEAXISSCAN_H_ */