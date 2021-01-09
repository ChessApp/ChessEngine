#ifndef CHESS_GAMEPROTOCOLDRIVER_H_
#define CHESS_GAMEPROTOCOLDRIVER_H_

#include "GameState.h"
#include "State/BaseState.h"


namespace Chess
{

  class GameProtocolDriver
  {
  public:
    //-- construction
    GameProtocolDriver();

  protected:
    //-- protected types
    typedef shared_ptr<State::BaseState> StatePtr;

    //-- protected methods
    void createStateMachine();
    void runStateMachine();

    //-- protected members
    GameState    gameState_;
    StatePtr     currentState_;
    StatePtr     checkmate_;
    StatePtr     init_;
    StatePtr     input_;
    StatePtr     relevancy_;
    StatePtr     moveValidity_;
    StatePtr     pathscan_;
    StatePtr     move_;
    StatePtr     defensiveCheckScan_;
    StatePtr     offensiveCheckScan_;
    StatePtr     returnPiece_;
    StatePtr     switchTurn_;
    StatePtr     pinScan_;
    StatePtr     blockScan_;
    StatePtr     escapeRoute_;
    StatePtr     finish_;
  };

}

#endif /* CHESS_GAMEPROTOCOLDRIVER_H_ */
