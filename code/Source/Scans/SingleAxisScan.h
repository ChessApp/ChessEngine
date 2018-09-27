
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

  protected:

    SingleAxisScan ( Board * board ) ;

    //virtual void runValidityChecks ( ) = 0 ;

    virtual ScanResult leftScan ( int sourceRow, int sourceCol ) ;

    virtual ScanResult rightScan ( int sourceRow, int sourceCol ) ;

    virtual ScanResult upScan ( int sourceRow, int sourceCol ) ;

    virtual ScanResult downScan ( int sourceRow, int sourceCol ) ;

    

  };

}

#endif /* SINGLEAXISSCAN_H_ */