#include "Scanner.h"    

namespace Chess
{

  Scanner::Scanner ( Board * board )
    : board(board)
  {

  }

  Scanner::ScanResult Scanner::leftScan ( int sourceRow, int sourceCol )
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

  Scanner::ScanResult Scanner::rightScan ( int sourceRow, int sourceCol )
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

  Scanner::ScanResult Scanner::upScan ( int sourceRow, int sourceCol )
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

  Scanner::ScanResult Scanner::downScan ( int sourceRow, int sourceCol )
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

  Scanner::ScanResult Scanner::upLeftScan ( int sourceRow, int sourceCol )
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

  Scanner::ScanResult Scanner::upRightScan ( int sourceRow, int sourceCol )
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

  Scanner::ScanResult Scanner::downLeftScan ( int sourceRow, int sourceCol )
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

  Scanner::ScanResult Scanner::downRightScan ( int sourceRow, int sourceCol )
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

