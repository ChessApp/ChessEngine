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
    typedef shared_ptr<ScanResult> ScanResultPtr;

    class LeftScan
      : public BaseScan
    {
    public:
      //-- construction
      inline LeftScan( Board * board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }

      //-- BaseScan interface
      virtual ScanResult * execute( );
    };

    class RightScan
      : public BaseScan
    {
    public:
      //-- construction
      inline RightScan( Board * board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }

      //-- BaseScan interface
      virtual ScanResult * execute( );
    };

    class UpScan
      : public BaseScan
    {
    public:
      //-- construction
      inline UpScan( Board * board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }

      //-- BaseScan interface
      virtual ScanResult * execute( );
    };

    class DownScan
      : public BaseScan
    {
    public:
      //-- construction
      inline DownScan( Board * board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }

      //-- BaseScan interface
      virtual ScanResult * execute( );
    };

    class UpLeftScan
      : public BaseScan
    {
    public:
      //-- construction
      inline UpLeftScan( Board * board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }

      //-- BaseScan interface
      virtual ScanResult * execute( );
    };

    class UpRightScan
      : public BaseScan
    {
    public:
      //-- construction
      inline UpRightScan( Board * board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }

      //-- BaseScan interface
      virtual ScanResult * execute( );
    };

    class DownLeftScan
      : public BaseScan
    {
    public:
      //-- construction
      inline DownLeftScan( Board * board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }

      //-- BaseScan interface
      virtual ScanResult * execute( );
    };

    class DownRightScan
      : public BaseScan
    {
    public:
      //-- construction
      inline DownRightScan( Board * board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }

      //-- BaseScan interface
      virtual ScanResult * execute( );
    }; 

    //-- construction
    inline Scanner ( Board * board )
      : board_(board)
    { }

    //-- interface methods
    virtual ScanResult * execute ( ) = 0;
    virtual void         identifyScan( int sourceRow, int sourceCol, int destRow, int destCol ) = 0;

  protected:
    //-- protected members
    Board *    board_ ;
    BaseScan * scan_ ;
  };

}

#endif /* CHESS_SCANNER_H_ */
