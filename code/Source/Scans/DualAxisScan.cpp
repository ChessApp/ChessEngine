#include "DualAxisScan.h"

namespace Chess
{

  DualAxisScan::DualAxisScan ( Board * board )
    : Scanner ( board )
  {

  }

  void DualAxisScan::executeScans ( int sourceRow, int sourceCol )
  {
    upLeftScan( sourceRow, sourceCol ) ;
    upRightScan( sourceRow, sourceCol ) ;
    downLeftScan( sourceRow, sourceCol ) ;
    downRightScan( sourceRow, sourceCol ) ;
  }

  DualAxisScan::ScanResult DualAxisScan::upLeftScan ( int sourceRow, int sourceCol )
  {
    ScanResult scanResult ;
    int i = sourceCol - 1 ;
    int j = sourceRow - 1 ;
    while ( i >= 0 && j >= 0)
    {
      if ( board->getPiece( j, i ) != NULL && board->getPieceName( j, i ) != "" )
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
    return scanResult ;
  }

  DualAxisScan::ScanResult DualAxisScan::upRightScan ( int sourceRow, int sourceCol )
  {
    ScanResult scanResult ;
    int i = sourceCol + 1 ;
    int j = sourceRow - 1 ;
    while ( i <= 7 && j >= 0)
    {
      if ( board->getPiece( j, i ) != NULL && board->getPieceName( j, i ) != "" )
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
    return scanResult ;
  }

  DualAxisScan::ScanResult DualAxisScan::downLeftScan ( int sourceRow, int sourceCol )
  {
    ScanResult scanResult ;
    int i = sourceCol - 1 ;
    int j = sourceRow + 1 ;
    while ( i >= 0 && j <= 7)
    {
      if ( board->getPiece( j, i ) != NULL && board->getPieceName( j, i ) != "" )
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
    return scanResult ;
  }

  DualAxisScan::ScanResult DualAxisScan::downRightScan ( int sourceRow, int sourceCol )
  {
    ScanResult scanResult ;
    int i = sourceCol + 1 ;
    int j = sourceRow + 1 ;
    while ( i <= 7 && j <= 7)
    {
      if ( board->getPiece( j, i ) != NULL && board->getPieceName( j, i ) != "" )
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
    return scanResult ;
  }

}