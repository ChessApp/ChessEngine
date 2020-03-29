#ifndef CHESS_SCANNER_H_
#define CHESS_SCANNER_H_

#include "Chess.h"
#include "Pieces/Pieces.h"
#include "Pieces/NullPiece.h"
#include "Board.h"
#include "Interface.h"
#include "Scans/BaseScan.h"
#include "Scans/ScanResult.h"


namespace Chess
{

  class Scanner
  {
  public:
    //-- types
    typedef shared_ptr<Board>      BoardPtr;
    typedef shared_ptr<ScanResult> ScanResultPtr;

    class LeftScan
      : public BaseScan
    {
    public:
      //-- construction
      inline LeftScan( BoardPtr board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }

      //-- BaseScan interface
      virtual ScanResultPtr execute( );
    };

    class RightScan
      : public BaseScan
    {
    public:
      //-- construction
      inline RightScan( BoardPtr board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }

      //-- BaseScan interface
      virtual ScanResultPtr execute( );
    };

    class UpScan
      : public BaseScan
    {
    public:
      //-- construction
      inline UpScan( BoardPtr board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }

      //-- BaseScan interface
      virtual ScanResultPtr execute( );
    };

    class DownScan
      : public BaseScan
    {
    public:
      //-- construction
      inline DownScan( BoardPtr board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }

      //-- BaseScan interface
      virtual ScanResultPtr execute( );
    };

    class UpLeftScan
      : public BaseScan
    {
    public:
      //-- construction
      inline UpLeftScan( BoardPtr board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }

      //-- BaseScan interface
      virtual ScanResultPtr execute( );
    };

    class UpRightScan
      : public BaseScan
    {
    public:
      //-- construction
      inline UpRightScan( BoardPtr board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }

      //-- BaseScan interface
      virtual ScanResultPtr execute( );
    };

    class DownLeftScan
      : public BaseScan
    {
    public:
      //-- construction
      inline DownLeftScan( BoardPtr board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }

      //-- BaseScan interface
      virtual ScanResultPtr execute( );
    };

    class DownRightScan
      : public BaseScan
    {
    public:
      //-- construction
      inline DownRightScan( BoardPtr board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }

      //-- BaseScan interface
      virtual ScanResultPtr execute( );
    }; 

    //-- construction
    inline Scanner( BoardPtr board )
      : board_(board)
    { }

    //-- interface methods
    virtual ScanResultPtr execute( ) = 0;
    virtual void          identifyScan( int sourceRow, int sourceCol, int destRow, int destCol ) = 0;

  protected:
    //-- protected members
    BoardPtr   board_ ;
    BaseScan * scan_ ;
  };

}

#endif /* CHESS_SCANNER_H_ */
