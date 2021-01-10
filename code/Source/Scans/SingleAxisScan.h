#ifndef CHESS_SINGLEAXISSCAN_H_
#define CHESS_SINGLEAXISSCAN_H_

#include "Chess.h"
#include "Scans/Scanner.h"


namespace Chess
{

  class SingleAxisScan
    : public Scanner
  {
  public:
    //-- types
    
    //-- construction
    SingleAxisScan( Board& board );

    //-- Scanner interface
    virtual ScanResultPtr execute( );
    virtual void identifyScan( const pair<int,int>& source, const pair<int,int>& destination );
  };

}

#endif /* CHESS_SINGLEAXISSCAN_H_ */
