#ifndef CHESS_COMPOUNDAXISSCAN_H_
#define CHESS_COMPOUNDAXISSCAN_H_

#include "Chess.h"
#include "Scans/Scanner.h"
#include "Board.h"


namespace Chess
{

  class CompoundAxisScan
    : public Scanner
  {
  public:
    //-- construction
    CompoundAxisScan( Board& board );

    //-- Scanner interface
    virtual void identifyScan( const pair<int,int>& source, const pair<int,int>& destination );
    virtual ScanResultPtr execute();
  };

}

#endif /* CHESS_COMPOUNDAXISSCAN_H_ */
