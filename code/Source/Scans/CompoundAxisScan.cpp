// #include "Scans/CompoundAxisScan.h"


// namespace Chess
// {

//   CompoundAxisScan::CompoundAxisScan( Board& board )
//     : Scanner(board)
//   { }

//   void CompoundAxisScan::identifyScan( const pair<int,int>& source, const pair<int,int>& destination )
//   {
//     int rowDiff = destination.first - source.first;
//     int colDiff = destination.second - source.second;

//     if( rowDiff > 0 && colDiff == 0 )
//       scan_ = new DownScan(board_, source, destination);
//     else if( rowDiff < 0 && colDiff == 0 )
//       scan_ = new UpScan(board_, source, destination);
//     else if( colDiff > 0 && rowDiff == 0 )
//       scan_ = new RightScan(board_, source, destination);
//     else if( colDiff < 0 && rowDiff == 0 )
//       scan_ = new LeftScan(board_, source, destination);
//     else if( rowDiff > 0 && colDiff < 0 )
//       scan_ = new DownLeftScan(board_, source, destination);
//     else if( rowDiff > 0 && colDiff > 0 )
//       scan_ = new DownRightScan( board_, source, destination );
//     else if( rowDiff < 0 && colDiff > 0 )
//       scan_ = new UpRightScan( board_, source, destination );
//     else if( rowDiff < 0 && colDiff < 0 )
//       scan_ = new UpLeftScan( board_, source, destination );
//     else
//       std::cout << "Scan could not be identified because destination is invalid." << std::endl;
//   }

//   Scanner::ScanResultPtr CompoundAxisScan::execute( )
//   {
//     return scan_->execute( );
//   }

// }
