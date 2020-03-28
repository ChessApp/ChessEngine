#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <iostream>

#include "../Source/Pieces/Rook.h"
#include "Mocks/MockBoard.h"


class RookTests
  : public ::testing::Test 
{
public:
  inline RookTests( )
  {
    tr_ = new Chess::Rook("testRook", & mb_, NULL, NULL);
  }

protected:
  Chess::Rook * tr_;
  MockBoard     mb_;
  bool          result_;
};

TEST_F( RookTests, validDirectionTest )
{
  tr_->setLocation(1, 1);

  result_ = tr_->validDirection(1, 2);

  EXPECT_EQ( result_, false );
}
