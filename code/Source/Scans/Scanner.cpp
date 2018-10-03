#include "Scanner.h"    

namespace Chess
{

  Scanner::Scanner ( Board * board )
    : board(board)
  {

  }

  Pieces * Scanner::LeftScan::execute ( )
  {
    // ScanResult scanResult ;
    int i = sourceCol_ - 1 ;
    while ( i >= 0 )
    {
      if ( board->getPiece( sourceRow_, i ) != NULL && board->getPieceName( sourceRow_, i ) != ".. " )
      {
        result.detection = true ;
        result.row = sourceRow_ ;
        result.col = i ;
        result.detectedPiece = board->getPiece( sourceRow_, i ) ;
        break ;
      }
      i-- ;
    }
    return result.detectedPiece ;
  }

  Pieces * Scanner::RightScan::execute ( )
  {
    ScanResult scanResult ;
    int i = sourceCol_ + 1 ;
    while ( i <= 7 )
    {
      if ( board->getPiece( sourceRow_, i ) != NULL && board->getPieceName( sourceRow_, i ) != ".. " )
      {
        scanResult.detection = true ;
        scanResult.row = sourceRow_ ;
        scanResult.col = i ;
        scanResult.detectedPiece = board->getPiece( sourceRow_, i ) ;
        break ;
      }
      i++ ;
    }
    return scanResult.detectedPiece ;
  }

  Pieces * Scanner::UpScan::execute ( )
  {
    ScanResult scanResult ;
    int j = sourceRow_ - 1 ;
    while ( j >= 0 )
    {
      if ( board->getPiece( j, sourceCol_ ) != NULL && board->getPieceName( j, sourceCol_ ) != ".. " )
      {
        scanResult.detection = true ;
        scanResult.row = j ;
        scanResult.col = sourceCol_ ;
        scanResult.detectedPiece = board->getPiece( j, sourceCol_ ) ;
        break ;
      }
      j-- ;
    }
    return scanResult.detectedPiece ;
  }

  Pieces * Scanner::DownScan::execute ( )
  {
    ScanResult scanResult ;
    int j = sourceRow_ + 1 ;
    while ( j <= 7 )
    {
      if ( board->getPiece( j, sourceCol_ ) != NULL && board->getPieceName( j, sourceCol_ ) != ".. " )
      {
        scanResult.detection = true ;
        scanResult.row = j ;
        scanResult.col = sourceCol_ ;
        scanResult.detectedPiece = board->getPiece( j, sourceCol_ ) ;
        break ;
      }
      j++ ;
    }
    return scanResult.detectedPiece ;
  }

  Pieces * Scanner::UpLeftScan::execute ( )
  {
    ScanResult scanResult ;
    int i = sourceCol_ - 1 ;
    int j = sourceRow_ - 1 ;
    while ( i >= 0 && j >= 0)
    {
      if ( board->getPiece( j, i ) != NULL && board->getPieceName( j, i ) != ".. " )
      {
        scanResult.detection = true ;
        scanResult.row = j ;
        scanResult.col = i ;
        scanResult.detectedPiece = board->getPiece( j, i ) ;
        break ;
      }
      i-- ;
      j-- ;
    }
    return scanResult.detectedPiece ;
  }

  Pieces * Scanner::UpRightScan::execute ( )
  {
    ScanResult scanResult ;
    int i = sourceCol_ + 1 ;
    int j = sourceRow_ - 1 ;
    while ( i <= 7 && j >= 0)
    {
      if ( board->getPiece( j, i ) != NULL && board->getPieceName( j, i ) != ".. " )
      {
        scanResult.detection = true ;
        scanResult.row = j ;
        scanResult.col = i ;
        scanResult.detectedPiece = board->getPiece( j, i ) ;
        break ;
      }
      i++ ;
      j-- ;
    }
    return scanResult.detectedPiece ;
  }

  Pieces * Scanner::DownLeftScan::execute ( )
  {
    ScanResult scanResult ;
    int i = sourceCol_ - 1 ;
    int j = sourceRow_ + 1 ;
    while ( i >= 0 && j <= 7)
    {
      if ( board->getPiece( j, i ) != NULL && board->getPieceName( j, i ) != ".. " )
      {
        scanResult.detection = true ;
        scanResult.row = j ;
        scanResult.col = i ;
        scanResult.detectedPiece = board->getPiece( j, i ) ;
        break ;
      }
      i-- ;
      j++ ;
    }
    return scanResult.detectedPiece ;
  }

  Pieces * Scanner::DownRightScan::execute ( )
  {
    ScanResult scanResult ;
    int i = sourceCol_ + 1 ;
    int j = sourceRow_ + 1 ;
    while ( i <= 7 && j <= 7)
    {
      if ( board->getPiece( j, i ) != NULL && board->getPieceName( j, i ) != ".. " )
      {
        scanResult.detection = true ;
        scanResult.row = j ;
        scanResult.col = i ;
        scanResult.detectedPiece = board->getPiece( j, i ) ;
        break ;
      }
      i++ ;
      j++ ;
    }
    return scanResult.detectedPiece ;
  }

}

