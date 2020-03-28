#ifndef CHESS_GAMEPROTOCOLDRIVER_H_
#define CHESS_GAMEPROTOCOLDRIVER_H_

#include "BaseTurn.h"
#include "Board.h"
#include "Interface.h"
#include "State/BaseState.h"


namespace Chess
{

  class GameProtocolDriver
  {
  public:
    //-- construction
    GameProtocolDriver( );

  protected:
    //-- protected types
    typedef BaseTurn *                   BaseTurnPtr;
    typedef shared_ptr<State::BaseState> StatePtr;
    typedef Board *                      BoardPtr;

    //-- protected methods
    void createStateMachine( );
    void runStateMachine( );

    //-- protected members
    Interface * interface_;
    BoardPtr    board_;
    BaseTurnPtr whiteTurn_;
    BaseTurnPtr blackTurn_;
    BaseTurnPtr currentTurn_;
    StatePtr    currentState_;
    StatePtr    checkmate_;
    StatePtr    init_;
    StatePtr    input_;
    StatePtr    relevancy_;
    StatePtr    moveValidity_;
    StatePtr    pathscan_;
    StatePtr    move_;
    StatePtr    defensiveCheckScan_;
    StatePtr    offensiveCheckScan_;
    StatePtr    returnPiece_;
    StatePtr    switchTurn_;
    StatePtr    pinScan_;
    StatePtr    escapeRoute_;
  };

}

#endif /* CHESS_GAMEPROTOCOLDRIVER_H_ */
