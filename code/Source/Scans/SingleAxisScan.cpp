// #include "Scans/SingleAxisScan.h"


// namespace Chess
// {

//   SingleAxisScan::SingleAxisScan( Board& board )
//     : Scanner(board)
//   { }

//   void SingleAxisScan::identifyScan( const pair<int,int>& source, const pair<int,int>& destination )
//   {
//     int rowDiff = destination.first - source.first;
//     int colDiff = destination.second - source.second;

//     if( rowDiff > 0 )
//       scan_ = new DownScan( board_, source, destination );
//     else if( rowDiff < 0 )
//       scan_ = new UpScan( board_, source, destination );
//     else if( colDiff > 0 )
//       scan_ = new RightScan( board_, source, destination );
//     else if( colDiff < 0 )
//       scan_ = new LeftScan( board_, source, destination );
//     else
//       cout << "Error: No scan identified." << endl;
//   }

//   Scanner::ScanResultPtr SingleAxisScan::execute( )
//   {
//     return scan_->execute( ) ;
//   }

// }
