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
    typedef shared_ptr<Board> BoardPtr;
    
    //-- construction
    SingleAxisScan( BoardPtr board );

    //-- Scanner interface
    virtual ScanResultPtr execute( );
    virtual void identifyScan( int sourceRow, int sourceCol, int destRow, int destCol );
  };

}

#endif /* CHESS_SINGLEAXISSCAN_H_ */
