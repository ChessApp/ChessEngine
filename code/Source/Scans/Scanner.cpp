#include "Scans/Scanner.h"    


namespace Chess
{

  Scanner::ScanResultPtr Scanner::LeftScan::execute( )
  {
    result_->detectedPiece = board_.getPiece(source_);
    int i = source_.second - 1;

    while( i >= destination_.second )
    {
      result_->detectedPiece = board_.getPiece({source_.first, i});
      if( board_.getPiece({source_.first, i}) != NULL && board_.getPiece({source_.first, i})->getName() != ".. " )
      {
        result_->detection = true; 
        result_->row = source_.first;
        result_->col = i;
        result_->detectedPiece = board_.getPiece({source_.first, i});
        break;
      }
      else
      {
        result_->addSquare(source_.first, i);
      }
      i--;
    }
    return result_;
  }

  Scanner::ScanResultPtr Scanner::RightScan::execute( )
  {
    result_->detectedPiece = board_.getPiece(source_);
    int i = source_.second + 1;

    while( i <= destination_.second )
    {
      result_->detectedPiece = board_.getPiece({source_.first, i});
      if( board_.getPiece({source_.first, i}) != NULL && board_.getPiece({source_.first, i})->getName() != ".. " )
      {
        result_->detection = true;
        result_->row = source_.first;
        result_->col = i;
        result_->detectedPiece = board_.getPiece({source_.first, i});
        break;
      }
      else
      {
        result_->addSquare(source_.first, i);
      }
      i++;
    }
    return result_;
  }

  Scanner::ScanResultPtr Scanner::UpScan::execute ( )
  {
    result_->detectedPiece = board_.getPiece(source_);
    int j = source_.first - 1;

    while( j >= destination_.first )
    {
      result_->detectedPiece = board_.getPiece({j, source_.second});
      if( board_.getPiece({j, source_.second}) != NULL && board_.getPiece({j, source_.second})->getName() != ".. " )
      {
        result_->detection = true;
        result_->row = j;
        result_->col = source_.second;
        result_->detectedPiece = board_.getPiece({j, source_.second});
        break ;
      }
      else
      {
        result_->addSquare(j, source_.second);
      }
      j--;
    }
    return result_;
  }

  Scanner::ScanResultPtr Scanner::DownScan::execute( )
  {
    result_->detectedPiece = board_.getPiece(source_);
    int j = source_.first + 1;

    while( j <= destination_.first )
    {
      result_->detectedPiece = board_.getPiece({j, source_.second});
      if( board_.getPiece({j, source_.second}) != NULL && board_.getPiece({j, source_.second})->getName() != ".. " )
      {
        result_->detection = true;
        result_->row = j;
        result_->col = source_.second;
        result_->detectedPiece = board_.getPiece({j, source_.second});
        break ;
      }
      else
      {
        result_->addSquare( j, source_.second );
      }
      j++;
    }
    return result_;
  }

  Scanner::ScanResultPtr Scanner::UpLeftScan::execute( )
  {
    result_->detectedPiece = board_.getPiece(source_);
    int i = source_.second - 1;
    int j = source_.first - 1;

    while( i >= destination_.second && j >= destination_.first )
    {
      result_->detectedPiece = board_.getPiece({j, i});
      if( board_.getPiece({j, i}) != NULL && board_.getPiece({j, i})->getName() != ".. " )
      {
        result_->detection = true;
        result_->row = j;
        result_->col = i;
        result_->detectedPiece = board_.getPiece({j, i});
        break;
      }
      else
      {
        result_->addSquare(j, i);
      }
      i--;
      j--;
    }
    return result_;
  }

  Scanner::ScanResultPtr Scanner::UpRightScan::execute( )
  {
    result_->detectedPiece = board_.getPiece(source_);
    int i = source_.second + 1;
    int j = source_.first - 1;

    while ( i <= destination_.second && j >= destination_.first )
    {
      result_->detectedPiece = board_.getPiece({j, i});
      if( board_.getPiece({j, i}) != NULL && board_.getPiece({j, i})->getName() != ".. " )
      {
        result_->detection = true;
        result_->row = j;
        result_->col = i;
        result_->detectedPiece = board_.getPiece({j, i});
        break;
      }
      else
      {
        result_->addSquare( j, i );
      }
      i++;
      j--;
    }
    return result_;
  }

  Scanner::ScanResultPtr Scanner::DownLeftScan::execute( )
  {
    result_->detectedPiece = board_.getPiece(source_);
    int i = source_.second - 1;
    int j = source_.first + 1;

    while( i >= destination_.second && j <= destination_.first )
    {
      result_->detectedPiece = board_.getPiece({j, i});
      if( board_.getPiece({j, i}) != NULL && board_.getPiece({j, i})->getName() != ".. " )
      {
        result_->detection = true;
        result_->row = j;
        result_->col = i;
        result_->detectedPiece = board_.getPiece({j, i});
        break ;
      }
      else
      {
        result_->addSquare(j, i);
      }
      i--;
      j++;
    }
    return result_ ;
  }

  Scanner::ScanResultPtr Scanner::DownRightScan::execute( )
  {
    result_->detectedPiece = board_.getPiece(source_);
    int i = source_.second + 1;
    int j = source_.first + 1;

    while( i <= destination_.second && j <= destination_.first )
    {
      result_->detectedPiece = board_.getPiece({j, i});
      if( board_.getPiece({j, i}) != NULL && board_.getPiece({j, i})->getName() != ".. " )
      {
        result_->detection = true;
        result_->row = j;
        result_->col = i;
        result_->detectedPiece = board_.getPiece({j, i});
        break ;
      }
      else
      {
        result_->addSquare(j, i);
      }
      i++;
      j++;
    }
    return result_;
  }

}
