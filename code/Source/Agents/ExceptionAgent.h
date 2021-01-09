#ifndef CHESS_EXCEPTIONAGENT_H_
#define CHESS_EXCEPTIONAGENT_H_

#include "Chess.h"
#include "GameState.h"


namespace Chess
{
  namespace ExceptionAgent
  {

    void handle( Exception& exception, GameState& gameState );

  }
}

#endif /* CHESS_EXCEPTIONAGENT_H_ */
