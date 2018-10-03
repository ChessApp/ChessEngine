
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
 

    friend class Board ;

    CompoundAxisScan ( Board * board ) ;
    virtual void identifyScan ( int sourceRow, int sourceCol, int destRow, int destCol ) ;

    virtual Pieces * execute ( ) ;

  protected:

    
   

  };

}

#endif /* COMPOUNDAXISSCAN_H_ */