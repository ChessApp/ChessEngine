#include "Scanner.h"    

namespace Chess
{

  ScanResult * Scanner::LeftScan::execute ( )
  {
    result_->detectedPiece = board_->getPiece( sourceRow_, sourceCol_ ) ;
    int i = sourceCol_ - 1 ;
    while ( i >= destCol_ )
    {
      result_->detectedPiece = board_->getPiece( sourceRow_, i ) ;
      if ( board_->getPiece( sourceRow_, i ) != NULL && board_->getPieceName( sourceRow_, i ) != ".. " )
      {
        result_->detection = true ;
        result_->row = sourceRow_ ;
        result_->col = i ;
        result_->detectedPiece = board_->getPiece( sourceRow_, i ) ;
        break ;
      }
      else
      {
        result_->addSquare( sourceRow_, i ) ;
      }
      i-- ;
    }
    return result_ ;
  }

  ScanResult * Scanner::RightScan::execute ( )
  {
    result_->detectedPiece = board_->getPiece( sourceRow_, sourceCol_ ) ;
    int i = sourceCol_ + 1 ;
    while ( i <= destCol_ )
    {
      result_->detectedPiece = board_->getPiece( sourceRow_, i ) ;
      if ( board_->getPiece( sourceRow_, i ) != NULL && board_->getPieceName( sourceRow_, i ) != ".. " )
      {
        result_->detection = true ;
        result_->row = sourceRow_ ;
        result_->col = i ;
        result_->detectedPiece = board_->getPiece( sourceRow_, i ) ;
        break ;
      }
      else
      {
        result_->addSquare( sourceRow_, i ) ;
      }
      i++ ;
    }
    return result_ ;
  }

  ScanResult * Scanner::UpScan::execute ( )
  {
    result_->detectedPiece = board_->getPiece( sourceRow_, sourceCol_ ) ;
    int j = sourceRow_ - 1 ;
    while ( j >= destRow_ )
    {
      result_->detectedPiece = board_->getPiece( j, sourceCol_ ) ;
      if ( board_->getPiece( j, sourceCol_ ) != NULL && board_->getPieceName( j, sourceCol_ ) != ".. " )
      {
        result_->detection = true ;
        result_->row = j ;
        result_->col = sourceCol_ ;
        result_->detectedPiece = board_->getPiece( j, sourceCol_ ) ;
        break ;
      }
      else
      {
        result_->addSquare( j, sourceCol_ ) ;
      }
      j-- ;
    }
    return result_ ;
  }

  ScanResult * Scanner::DownScan::execute ( )
  {
    result_->detectedPiece = board_->getPiece( sourceRow_, sourceCol_ ) ;
    int j = sourceRow_ + 1 ;
    while ( j <= destRow_ )
    {
      result_->detectedPiece = board_->getPiece( j, sourceCol_ ) ;
      if ( board_->getPiece( j, sourceCol_ ) != NULL && board_->getPieceName( j, sourceCol_ ) != ".. " )
      {
        result_->detection = true ;
        result_->row = j ;
        result_->col = sourceCol_ ;
        result_->detectedPiece = board_->getPiece( j, sourceCol_ ) ;
        break ;
      }
      else
      {
        result_->addSquare( j, sourceCol_ ) ;
      }
      j++ ;
    }
    return result_ ;
  }

  ScanResult * Scanner::UpLeftScan::execute ( )
  {
    result_->detectedPiece = board_->getPiece( sourceRow_, sourceCol_ ) ;
    int i = sourceCol_ - 1 ;
    int j = sourceRow_ - 1 ;
    while ( i >= destCol_ && j >= destRow_ )
    {
      result_->detectedPiece = board_->getPiece( j, i ) ;
      if ( board_->getPiece( j, i ) != NULL && board_->getPieceName( j, i ) != ".. " )
      {
        result_->detection = true ;
        result_->row = j ;
        result_->col = i ;
        result_->detectedPiece = board_->getPiece( j, i ) ;
        break ;
      }
      else
      {
        result_->addSquare( j, i ) ;
      }
      i-- ;
      j-- ;
    }
    return result_ ;
  }

  ScanResult * Scanner::UpRightScan::execute ( )
  {
    result_->detectedPiece = board_->getPiece( sourceRow_, sourceCol_ ) ;
    int i = sourceCol_ + 1 ;
    int j = sourceRow_ - 1 ;
    while ( i <= destCol_ && j >= destRow_ )
    {
      result_->detectedPiece = board_->getPiece( j, i ) ;
      if ( board_->getPiece( j, i ) != NULL && board_->getPieceName( j, i ) != ".. " )
      {
        result_->detection = true ;
        result_->row = j ;
        result_->col = i ;
        result_->detectedPiece = board_->getPiece( j, i ) ;
        break ;
      }
      else
      {
        result_->addSquare( j, i ) ;
      }
      i++ ;
      j-- ;
    }
    return result_ ;
  }

  ScanResult * Scanner::DownLeftScan::execute ( )
  {
    result_->detectedPiece = board_->getPiece( sourceRow_, sourceCol_ ) ;
    int i = sourceCol_ - 1 ;
    int j = sourceRow_ + 1 ;
    while ( i >= destCol_ && j <= destRow_ )
    {
      result_->detectedPiece = board_->getPiece( j, i ) ;
      if ( board_->getPiece( j, i ) != NULL && board_->getPieceName( j, i ) != ".. " )
      {
        result_->detection = true ;
        result_->row = j ;
        result_->col = i ;
        result_->detectedPiece = board_->getPiece( j, i ) ;
        break ;
      }
      else
      {
        result_->addSquare( j, i ) ;
      }
      i-- ;
      j++ ;
    }
    return result_ ;
  }

  ScanResult * Scanner::DownRightScan::execute ( )
  {
    result_->detectedPiece = board_->getPiece( sourceRow_, sourceCol_ ) ;
    int i = sourceCol_ + 1 ;
    int j = sourceRow_ + 1 ;
    while ( i <= destCol_ && j <= destRow_ )
    {
      result_->detectedPiece = board_->getPiece( j, i ) ;
      if ( board_->getPiece( j, i ) != NULL && board_->getPieceName( j, i ) != ".. " )
      {
        result_->detection = true ;
        result_->row = j ;
        result_->col = i ;
        result_->detectedPiece = board_->getPiece( j, i ) ;
        break ;
      }
      else
      {
        result_->addSquare( j, i ) ;
      }
      i++ ;
      j++ ;
    }
    return result_ ;
  }

}

