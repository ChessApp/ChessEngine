#ifndef BASESCAN_H_
#define BASESCAN_H_

#include <string>
#include <sstream>

#include "../Pieces/Pieces.h"
#include "../Board.h"

using namespace std;

namespace Chess
{

  class BaseScan
  {

  public:

    inline BaseScan ( Board * board )
      : board(board)
    { }

    // virtual ScanResult execute ( int sourceRow, int sourceCol ) = 0 ;
    virtual Pieces * execute ( ) = 0 ;

    typedef struct ScanResult
    {
      bool detection = false ;
      int row = NULL ;
      int col = NULL ;
      Pieces * detectedPiece = NULL ;
    } ;

    ScanResult result ;

    Board * board ;

  };

}

#endif /* BASESCAN_H_ */