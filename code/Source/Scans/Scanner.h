#ifndef SCANNER_H_
#define SCANNER_H_

#include <string>
#include <sstream>

#include "../Pieces/Pieces.h"
#include "../Board.h"
#include "../Interface.h"
#include "BaseScan.h"

using namespace std;

namespace Chess
{

  class Scanner
  {
  public:

    Scanner ( Board * board ) ;

    virtual Pieces * execute ( ) = 0 ;
    virtual void identifyScan ( int sourceRow, int sourceCol, int destRow, int destCol ) { } ;

    Board * board ;
    BaseScan * scan_ ;


    class LeftScan
      : public BaseScan
    {
    public:
      // virtual ScanResult execute ( int sourceRow, int sourceCol ) ;
      virtual Pieces * execute ( ) ;

      inline LeftScan ( Board * board, int sourceRow, int sourceCol )
        : BaseScan( board ),
          sourceRow_( sourceRow ),
          sourceCol_( sourceCol )
      { }
      ~LeftScan( ) ;

    protected:
      int sourceRow_ ;
      int sourceCol_ ;

    };

    class RightScan
      : public BaseScan
    {
    public:
      // virtual ScanResult execute ( int sourceRow, int sourceCol ) ;
      virtual Pieces * execute ( ) ;

      inline RightScan ( Board * board, int sourceRow, int sourceCol )
        : BaseScan( board ),
          sourceRow_( sourceRow ),
          sourceCol_( sourceCol )
      { }
      ~RightScan( ) ;

    protected:
      int sourceRow_ ;
      int sourceCol_ ;

    };

    class UpScan
      : public BaseScan
    {
    public:
      // virtual ScanResult execute ( int sourceRow, int sourceCol ) ;
      virtual Pieces * execute ( ) ;

      inline UpScan ( Board * board, int sourceRow, int sourceCol )
        : BaseScan( board ),
          sourceRow_( sourceRow ),
          sourceCol_( sourceCol )
      { }
      ~UpScan( ) ;

    protected:
      int sourceRow_ ;
      int sourceCol_ ;

    };

    class DownScan
      : public BaseScan
    {
    public:
      // virtual ScanResult execute ( int sourceRow, int sourceCol ) ;
      virtual Pieces * execute ( ) ;

      inline DownScan ( Board * board, int sourceRow, int sourceCol )
        : BaseScan( board ),
          sourceRow_( sourceRow ),
          sourceCol_( sourceCol )
      { }
      ~DownScan( ) ;

    protected:
      int sourceRow_ ;
      int sourceCol_ ;

    };

    class UpLeftScan
      : public BaseScan
    {
    public:
      // virtual ScanResult execute ( int sourceRow, int sourceCol ) ;
      virtual Pieces * execute ( ) ;

      inline UpLeftScan ( Board * board, int sourceRow, int sourceCol )
        : BaseScan( board ),
          sourceRow_( sourceRow ),
          sourceCol_( sourceCol )
      { }
      ~UpLeftScan( ) ;

    protected:
      int sourceRow_ ;
      int sourceCol_ ;

    };

    class UpRightScan
      : public BaseScan
    {
    public:
      // virtual ScanResult execute ( int sourceRow, int sourceCol ) ;
      virtual Pieces * execute ( ) ;

      inline UpRightScan ( Board * board, int sourceRow, int sourceCol )
        : BaseScan( board ),
          sourceRow_( sourceRow ),
          sourceCol_( sourceCol )
      { }
      ~UpRightScan( ) ;

    protected:
      int sourceRow_ ;
      int sourceCol_ ;

    };

    class DownLeftScan
      : public BaseScan
    {
    public:
      // virtual ScanResult execute ( int sourceRow, int sourceCol ) ;
      virtual Pieces * execute ( ) ;

      inline DownLeftScan ( Board * board, int sourceRow, int sourceCol )
        : BaseScan( board ),
          sourceRow_( sourceRow ),
          sourceCol_( sourceCol )
      { }
      ~DownLeftScan( ) ;

    protected:
      int sourceRow_ ;
      int sourceCol_ ;

    };

    class DownRightScan
      : public BaseScan
    {
    public:
      // virtual ScanResult execute ( int sourceRow, int sourceCol ) ;
      virtual Pieces * execute ( ) ;

      inline DownRightScan ( Board * board, int sourceRow, int sourceCol )
        : BaseScan( board ),
          sourceRow_( sourceRow ),
          sourceCol_( sourceCol )
      { }
      ~DownRightScan( ) ;

    protected:
      int sourceRow_ ;
      int sourceCol_ ;

    };  


  };

}

#endif /* SCANNER_H_ */