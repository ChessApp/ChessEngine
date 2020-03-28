#ifndef CHESS_BASESCAN_H_
#define CHESS_BASESCAN_H_

#include "Chess.h"
#include "Board.h"
#include "Scans/ScanResult.h"


namespace Chess
{

  class BaseScan
  {
  public:
    //-- types
    typedef shared_ptr<ScanResult> ScanResultPtr;

    //-- construction
    inline BaseScan( Board * board )
      : board_(board),
        result_(new ScanResult())
    { }

    inline BaseScan( Board * board, int sourceRow, int sourceCol, int destRow, int destCol )
      : board_(board),
        sourceRow_(sourceRow),
        sourceCol_(sourceCol),
        destRow_(destRow),
        destCol_(destCol),
        result_(new ScanResult())
    { }

    //-- interface methods
    virtual ScanResult * execute( ) = 0;

  protected:
    //-- protected members
    ScanResult * result_;
    Board * board_;
    int sourceRow_;
    int sourceCol_;
    int destRow_;
    int destCol_;
  };

}

#endif /* CHESS_BASESCAN_H_ */
