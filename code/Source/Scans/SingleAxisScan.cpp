#include "SingleAxisScan.h"

namespace Chess
{

  SingleAxisScan::SingleAxisScan ( Board * board )
    : Scanner ( board )
  {

  }

  void SingleAxisScan::executeScans ( int sourceRow, int sourceCol )
  {
    upScan( sourceRow, sourceCol ) ;
    rightScan( sourceRow, sourceCol ) ;
    leftScan( sourceRow, sourceCol ) ;
    downScan( sourceRow, sourceCol ) ;
  }

	SingleAxisScan::ScanResult SingleAxisScan::leftScan ( int sourceRow, int sourceCol )
  {
    // ScanResult scanResult ;
    int i = sourceCol - 1 ;
    while ( i >= 0 )
    {
      if ( board->getPiece( sourceRow, i ) != NULL && board->getPieceName( sourceRow, i ) != "" )
      {
        result.detection = true ;
        result.row = sourceRow ;
        result.col = i ;
        result.detectedPiece = board->getPiece( sourceRow, i ) ;
        break ;
      }
      i-- ;
    }
    return result ;
  }

  SingleAxisScan::ScanResult SingleAxisScan::rightScan ( int sourceRow, int sourceCol )
  {
    ScanResult scanResult ;
    int i = sourceCol + 1 ;
    while ( i <= 7 )
    {
      if ( board->getPiece( sourceRow, i ) != NULL && board->getPieceName( sourceRow, i ) != "" )
      {
        scanResult.detection = true ;
        scanResult.row = sourceRow ;
        scanResult.col = i ;
        scanResult.detectedPiece = board->getPiece( sourceRow, i ) ;
        break ;
      }
      i++ ;
    }
    return scanResult ;
  }

  SingleAxisScan::ScanResult SingleAxisScan::upScan ( int sourceRow, int sourceCol )
  {
    ScanResult scanResult ;
    int j = sourceRow - 1 ;
    while ( j >= 0 )
    {
      if ( board->getPiece( j, sourceCol ) != NULL && board->getPieceName( j, sourceCol ) != "" )
      {
        scanResult.detection = true ;
        scanResult.row = j ;
        scanResult.col = sourceCol ;
        scanResult.detectedPiece = board->getPiece( j, sourceCol ) ;
        break ;
      }
      j-- ;
    }
    return scanResult ;
  }

  SingleAxisScan::ScanResult SingleAxisScan::downScan ( int sourceRow, int sourceCol )
  {
    ScanResult scanResult ;
    int j = sourceRow + 1 ;
    while ( j <= 7 )
    {
      if ( board->getPiece( j, sourceCol ) != NULL && board->getPieceName( j, sourceCol ) != "" )
      {
        scanResult.detection = true ;
        scanResult.row = j ;
        scanResult.col = sourceCol ;
        scanResult.detectedPiece = board->getPiece( j, sourceCol ) ;
        break ;
      }
      j++ ;
    }
    return scanResult ;
  }

}