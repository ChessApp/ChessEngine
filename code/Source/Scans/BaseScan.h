#ifndef BASESCAN_H_
#define BASESCAN_H_

#include "Chess.h"
#include "Pieces/Pieces.h"
#include "Board.h"
#include "Scans/ScanResult.h"


namespace Chess
{

  class BaseScan
  {

  public:

    inline BaseScan ( Board * board )
      : board_(board),
        result_( new ScanResult( ) )
    { }
    inline BaseScan ( Board * board, int sourceRow, int sourceCol,
        int destRow, int destCol )
      : board_(board),
        sourceRow_(sourceRow),
        sourceCol_(sourceCol),
        destRow_(destRow),
        destCol_(destCol),
        result_( new ScanResult( ) )
    { }
    // virtual ScanResult execute ( int sourceRow, int sourceCol ) = 0 ;
    virtual ScanResult * execute ( ) = 0 ;

  protected:

    ScanResult * result_ ;

    Board * board_ ;
    int sourceRow_ ;
    int sourceCol_ ;
    int destRow_ ;
    int destCol_ ;

  };

}

#endif /* BASESCAN_H_ */