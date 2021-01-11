#ifndef CHESS_SCANS_H_
#define CHESS_SCANS_H_

#include "Chess.h"
#include "Board.h"
#include "Scans/BaseScan.h"
#include "Scans/ScanResult.h"


namespace Chess
{
  namespace Scans
  {

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
      virtual ScanResultPtr execute();
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

  }
}

#endif /* CHESS_SCANS_H_ */
