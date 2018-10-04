#ifndef SCANNER_H_
#define SCANNER_H_

#include <string>
#include <sstream>

#include "../Pieces/Pieces.h"
#include "../Pieces/NullPiece.h"
#include "../Board.h"
#include "../Interface.h"
#include "BaseScan.h"

using namespace std;

namespace Chess
{

  class Scanner
  {
  public:

    inline Scanner ( Board * board )
      : board_(board)
    { }

    virtual Pieces * execute ( ) = 0 ;
    virtual void identifyScan ( int sourceRow, int sourceCol, int destRow, int destCol ) { } ;

    Board * board_ ;
    BaseScan * scan_ ;
    

    class LeftScan
      : public BaseScan
    {
    public:
      // virtual ScanResult execute ( int sourceRow, int sourceCol ) ;
      virtual Pieces * execute ( ) ;

      inline LeftScan ( Board * board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }
      ~LeftScan( ) ;

    };

    class RightScan
      : public BaseScan
    {
    public:
      // virtual ScanResult execute ( int sourceRow, int sourceCol ) ;
      virtual Pieces * execute ( ) ;

      inline RightScan ( Board * board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }
      ~RightScan( ) ;

    };

    class UpScan
      : public BaseScan
    {
    public:
      // virtual ScanResult execute ( int sourceRow, int sourceCol ) ;
      virtual Pieces * execute ( ) ;

      inline UpScan ( Board * board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }
      ~UpScan( ) ;

    };

    class DownScan
      : public BaseScan
    {
    public:
      // virtual ScanResult execute ( int sourceRow, int sourceCol ) ;
      virtual Pieces * execute ( ) ;

      inline DownScan ( Board * board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }
      ~DownScan( ) ;

    };

    class UpLeftScan
      : public BaseScan
    {
    public:
      // virtual ScanResult execute ( int sourceRow, int sourceCol ) ;
      virtual Pieces * execute ( ) ;

      inline UpLeftScan ( Board * board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }
      ~UpLeftScan( ) ;

    };

    class UpRightScan
      : public BaseScan
    {
    public:
      // virtual ScanResult execute ( int sourceRow, int sourceCol ) ;
      virtual Pieces * execute ( ) ;

      inline UpRightScan ( Board * board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }
      ~UpRightScan( ) ;

    };

    class DownLeftScan
      : public BaseScan
    {
    public:
      // virtual ScanResult execute ( int sourceRow, int sourceCol ) ;
      virtual Pieces * execute ( ) ;

      inline DownLeftScan ( Board * board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }
      ~DownLeftScan( ) ;

    };

    class DownRightScan
      : public BaseScan
    {
    public:
      // virtual ScanResult execute ( int sourceRow, int sourceCol ) ;
      virtual Pieces * execute ( ) ;

      inline DownRightScan ( Board * board, int sourceRow, int sourceCol, int destRow, int destCol )
        : BaseScan( board, sourceRow, sourceCol, destRow, destCol )
      { }
      ~DownRightScan( ) ;

    };  


  };

}

#endif /* SCANNER_H_ */