#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../Source/Scans/SingleAxisScan.h"
#include "Mocks/MockBoard.h"

using ::testing::Return ;
using ::testing::_ ;

class SingleAxisScanTests
  : public ::testing::Test 
{
public:

  class TransparentSingleAxisScan
    : public Chess::SingleAxisScan
  {
  public:
    inline TransparentSingleAxisScan ( Board * mb )
      : SingleAxisScan( mb )
    {}

    using Chess::Scanner::result ;
    using Chess::SingleAxisScan::leftScan ;
  };

  inline SingleAxisScanTests ( )
  {
    sas_ = new TransparentSingleAxisScan ( & mb_ ) ;
  }

protected:
  TransparentSingleAxisScan * sas_ ;
  MockBoard mb_ ;
  bool result_ ;
};

TEST_F ( SingleAxisScanTests, leftScanTest )
{

  EXPECT_CALL ( mb_, getPieceName(_,_) )
    .WillOnce ( Return ( "Piece" ) ) ;

  sas_->leftScan( 0, 7 ) ;

  EXPECT_EQ ( sas_->result.detection, true ) ;

}

