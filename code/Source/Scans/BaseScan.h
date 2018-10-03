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
      : board_(board)
    { }
    inline BaseScan ( Board * board, int sourceRow, int sourceCol,
        int destRow, int destCol )
      : board_(board),
        sourceRow_(sourceRow),
        sourceCol_(sourceCol),
        destRow_(destRow),
        destCol_(destCol)
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

  protected:

    ScanResult result ;

    Board * board_ ;
    int sourceRow_ ;
    int sourceCol_ ;
    int destRow_ ;
    int destCol_ ;

  };

}

#endif /* BASESCAN_H_ */