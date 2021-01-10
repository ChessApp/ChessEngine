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
      inline LeftScan( Board& board, const pair<int,int>& source, const pair<int,int>& destination )
        : BaseScan( board, source, destination )
      { }

      //-- BaseScan interface
      virtual ScanResultPtr execute( );
    };

    class RightScan
      : public BaseScan
    {
    public:
      //-- construction
      inline RightScan( Board& board, const pair<int,int>& source, const pair<int,int>& destination )
        : BaseScan( board, source, destination )
      { }

      //-- BaseScan interface
      virtual ScanResultPtr execute( );
    };

    class UpScan
      : public BaseScan
    {
    public:
      //-- construction
      inline UpScan( Board& board, const pair<int,int>& source, const pair<int,int>& destination )
        : BaseScan( board, source, destination )
      { }

      //-- BaseScan interface
      virtual ScanResultPtr execute( );
    };

    class DownScan
      : public BaseScan
    {
    public:
      //-- construction
      inline DownScan( Board& board, const pair<int,int>& source, const pair<int,int>& destination )
        : BaseScan( board, source, destination )
      { }

      //-- BaseScan interface
      virtual ScanResultPtr execute( );
    };

    class UpLeftScan
      : public BaseScan
    {
    public:
      //-- construction
      inline UpLeftScan( Board& board, const pair<int,int>& source, const pair<int,int>& destination )
        : BaseScan( board, source, destination )
      { }

      //-- BaseScan interface
      virtual ScanResultPtr execute( );
    };

    class UpRightScan
      : public BaseScan
    {
    public:
      //-- construction
      inline UpRightScan( Board& board, const pair<int,int>& source, const pair<int,int>& destination )
        : BaseScan( board, source, destination )
      { }

      //-- BaseScan interface
      virtual ScanResultPtr execute( );
    };

    class DownLeftScan
      : public BaseScan
    {
    public:
      //-- construction
      inline DownLeftScan( Board& board, const pair<int,int>& source, const pair<int,int>& destination )
        : BaseScan( board, source, destination )
      { }

      //-- BaseScan interface
      virtual ScanResultPtr execute( );
    };

    class DownRightScan
      : public BaseScan
    {
    public:
      //-- construction
      inline DownRightScan( Board& board, const pair<int,int>& source, const pair<int,int>& destination )
        : BaseScan( board, source, destination )
      { }

      //-- BaseScan interface
      virtual ScanResultPtr execute( );
    }; 

    //-- construction
    inline Scanner( Board& board )
      : board_(board)
    { }

    //-- interface methods
    virtual ScanResultPtr execute( ) = 0;
    virtual void          identifyScan( const pair<int,int>& source, const pair<int,int>& destination ) = 0;

  protected:
    //-- protected members
    Board&      board_ ;
    BaseScan * scan_ ;
  };

}

#endif /* CHESS_SCANNER_H_ */
