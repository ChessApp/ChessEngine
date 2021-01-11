#ifndef CHESS_BASESCAN_H_
#define CHESS_BASESCAN_H_

#include "Chess.h"
#include "Board.h"
#include "Scans/ScanResult.h"
#include "Board.h"


namespace Chess
{

  class BaseScan
  {
  public:
    //-- types
    typedef shared_ptr<ScanResult> ScanResultPtr;

    //-- construction
    inline BaseScan( Board& board )
      : board_(board),
        result_(new ScanResult())
    { }

    inline BaseScan( Board& board, const pair<int,int>& source, const pair<int,int>& destination )
      : board_(board),
        source_(source),
        destination_(destination),
        result_(new ScanResult())
    { }

    //-- interface methods
    virtual ScanResultPtr execute() = 0;

  protected:
    //-- protected members
    ScanResultPtr result_;
    Board&        board_;
    pair<int,int> source_;
    pair<int,int> destination_;
  };

}

#endif /* CHESS_BASESCAN_H_ */
