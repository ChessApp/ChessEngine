#ifndef SCANNER_H_
#define SCANNER_H_

#include <string>
#include <sstream>

#include "../Pieces/Pieces.h"
#include "../Board.h"
#include "../Interface.h"
#include "../Status.h"

using namespace std;

namespace Chess
{

  class Scanner
  {



  protected:

    
    

  public:

    typedef Chess::Board Board ;
    typedef Chess::Status Status ;

    Scanner ( Board * board ) ;

    virtual bool executeScans ( int sourceRow, int sourceCol ) = 0 ;

    typedef struct ScanResult
    {
      bool detection = false ;
      int row = NULL ;
      int col = NULL ;
      Pieces * detectedPiece = NULL ;
    } ;

    ScanResult result ;

    Board * board ;

    ScanResult leftScan ( int sourceRow, int sourceCol ) ;

    ScanResult rightScan ( int sourceRow, int sourceCol ) ;

    ScanResult upScan ( int sourceRow, int sourceCol ) ;

    ScanResult downScan ( int sourceRow, int sourceCol ) ;

    ScanResult upLeftScan ( int sourceRow, int sourceCol ) ;

    ScanResult upRightScan ( int sourceRow, int sourceCol ) ;

    ScanResult downLeftScan ( int sourceRow, int sourceCol ) ;

    ScanResult downRightScan ( int sourceRow, int sourceCol ) ;

    



    // bool rightRadar(Pieces & king);

    // bool leftRadar(Pieces* king);

    // bool upRadar(Pieces* king);

    // bool downRadar(Pieces* king);

    // bool upRightRadar(Pieces* king);

    // bool upLeftRadar(Pieces* king);

    // bool downRightRadar(Pieces* king);

    // bool downLeftRadar(Pieces* king);

  };

}

#endif /* SCANNER_H_ */