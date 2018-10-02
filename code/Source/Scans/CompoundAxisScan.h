
#ifndef COMPOUNDAXISSCAN_H_
#define COMPOUNDAXISSCAN_H_

#include <string>
#include <sstream>
#include <vector>

#include "Scanner.h"
#include "../Pieces/Pieces.h"


using namespace std;

namespace Chess
{

  class CompoundAxisScan
    : public Scanner
  {

  public:

    typedef Chess::Pieces Pieces ;
    typedef Chess::Board Board ;
    typedef Chess::Status Status ;  

    friend class Board ;

    CompoundAxisScan ( Board * board ) ;

    virtual bool executeScans ( int sourceRow, int sourceCol ) ;

  protected:

    
   

  };

}

#endif /* COMPOUNDAXISSCAN_H_ */