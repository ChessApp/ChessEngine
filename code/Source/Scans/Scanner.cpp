#include "Scanner.h"    

namespace Chess
{

  Pieces * Scanner::LeftScan::execute ( )
  {
    result.detectedPiece = board_->getPiece( sourceRow_, sourceCol_ ) ;
    int i = sourceCol_ - 1 ;
    while ( i >= destCol_ )
    {
      result.detectedPiece = board_->getPiece( sourceRow_, i ) ;
      if ( board_->getPiece( sourceRow_, i ) != NULL && board_->getPieceName( sourceRow_, i ) != ".. " )
      {
        result.detection = true ;
        result.row = sourceRow_ ;
        result.col = i ;
        break ;
      }
      i-- ;
    }
    return result.detectedPiece ;
  }

  Pieces * Scanner::RightScan::execute ( )
  {
    result.detectedPiece = board_->getPiece( sourceRow_, sourceCol_ ) ;
    int i = sourceCol_ + 1 ;
    while ( i <= destCol_ )
    {
      result.detectedPiece = board_->getPiece( sourceRow_, i ) ;
      if ( board_->getPiece( sourceRow_, i ) != NULL && board_->getPieceName( sourceRow_, i ) != ".. " )
      {
        result.detection = true ;
        result.row = sourceRow_ ;
        result.col = i ;
        result.detectedPiece = board_->getPiece( sourceRow_, i ) ;
        break ;
      }
      i++ ;
    }
    return result.detectedPiece ;
  }

  Pieces * Scanner::UpScan::execute ( )
  {
    result.detectedPiece = board_->getPiece( sourceRow_, sourceCol_ ) ;
    int j = sourceRow_ - 1 ;
    while ( j >= destRow_ )
    {
      result.detectedPiece = board_->getPiece( j, sourceCol_ ) ;
      if ( board_->getPiece( j, sourceCol_ ) != NULL && board_->getPieceName( j, sourceCol_ ) != ".. " )
      {
        result.detection = true ;
        result.row = j ;
        result.col = sourceCol_ ;
        result.detectedPiece = board_->getPiece( j, sourceCol_ ) ;
        break ;
      }
      j-- ;
    }
    return result.detectedPiece ;
  }

  Pieces * Scanner::DownScan::execute ( )
  {
    result.detectedPiece = board_->getPiece( sourceRow_, sourceCol_ ) ;
    int j = sourceRow_ + 1 ;
    while ( j <= destRow_ )
    {
      result.detectedPiece = board_->getPiece( j, sourceCol_ ) ;
      if ( board_->getPiece( j, sourceCol_ ) != NULL && board_->getPieceName( j, sourceCol_ ) != ".. " )
      {
        result.detection = true ;
        result.row = j ;
        result.col = sourceCol_ ;
        result.detectedPiece = board_->getPiece( j, sourceCol_ ) ;
        break ;
      }
      j++ ;
    }
    return result.detectedPiece ;
  }

  Pieces * Scanner::UpLeftScan::execute ( )
  {
    result.detectedPiece = board_->getPiece( sourceRow_, sourceCol_ ) ;
    int i = sourceCol_ - 1 ;
    int j = sourceRow_ - 1 ;
    while ( i >= destCol_ && j >= destRow_ )
    {
      result.detectedPiece = board_->getPiece( j, i ) ;
      if ( board_->getPiece( j, i ) != NULL && board_->getPieceName( j, i ) != ".. " )
      {
        result.detection = true ;
        result.row = j ;
        result.col = i ;
        result.detectedPiece = board_->getPiece( j, i ) ;
        break ;
      }
      i-- ;
      j-- ;
    }
    return result.detectedPiece ;
  }

  Pieces * Scanner::UpRightScan::execute ( )
  {
    result.detectedPiece = board_->getPiece( sourceRow_, sourceCol_ ) ;
    int i = sourceCol_ + 1 ;
    int j = sourceRow_ - 1 ;
    while ( i <= destCol_ && j >= destRow_ )
    {
      result.detectedPiece = board_->getPiece( j, i ) ;
      if ( board_->getPiece( j, i ) != NULL && board_->getPieceName( j, i ) != ".. " )
      {
        result.detection = true ;
        result.row = j ;
        result.col = i ;
        result.detectedPiece = board_->getPiece( j, i ) ;
        break ;
      }
      i++ ;
      j-- ;
    }
    return result.detectedPiece ;
  }

  Pieces * Scanner::DownLeftScan::execute ( )
  {
    result.detectedPiece = board_->getPiece( sourceRow_, sourceCol_ ) ;
    int i = sourceCol_ - 1 ;
    int j = sourceRow_ + 1 ;
    while ( i >= destCol_ && j <= destRow_ )
    {
      result.detectedPiece = board_->getPiece( j, i ) ;
      if ( board_->getPiece( j, i ) != NULL && board_->getPieceName( j, i ) != ".. " )
      {
        result.detection = true ;
        result.row = j ;
        result.col = i ;
        result.detectedPiece = board_->getPiece( j, i ) ;
        break ;
      }
      i-- ;
      j++ ;
    }
    return result.detectedPiece ;
  }

  Pieces * Scanner::DownRightScan::execute ( )
  {
    result.detectedPiece = board_->getPiece( sourceRow_, sourceCol_ ) ;
    int i = sourceCol_ + 1 ;
    int j = sourceRow_ + 1 ;
    while ( i <= destCol_ && j <= destRow_ )
    {
      result.detectedPiece = board_->getPiece( j, i ) ;
      if ( board_->getPiece( j, i ) != NULL && board_->getPieceName( j, i ) != ".. " )
      {
        result.detection = true ;
        result.row = j ;
        result.col = i ;
        result.detectedPiece = board_->getPiece( j, i ) ;
        break ;
      }
      i++ ;
      j++ ;
    }
    return result.detectedPiece ;
  }

}

