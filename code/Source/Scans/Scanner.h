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

    typedef struct ScanResult
    {
      bool detection = false ;
      int row = NULL ;
      int col = NULL ;
      Pieces * detectedPiece = NULL ;
    } ;

    ScanResult result ;

    Board * board ;

  public:

    typedef Chess::Board Board ;
    typedef Chess::Status Status ;

    Scanner ( Board * board ) ;

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