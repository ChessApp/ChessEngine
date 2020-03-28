#ifndef CHESSGAME_TESTS_MOCKS_MOCKBOARD_H_
#define CHESSGAME_TESTS_MOCKS_MOCKBOARD_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <iostream>

#include "../../Source/Board.h"


class MockBoard
  : public Chess::Board
{
public:
  MOCK_METHOD2( getPieceName, string (int, int) );
};

#endif /* CHESSGAME_TESTS_MOCKS_MOCKBOARD_H_ */
