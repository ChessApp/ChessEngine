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
    typedef shared_ptr<Interface>        InterfacePtr;
    typedef shared_ptr<BaseTurn>         BaseTurnPtr;
    typedef shared_ptr<State::BaseState> StatePtr;
    typedef shared_ptr<Board>            BoardPtr;

    //-- protected methods
    void createStateMachine( );
    void runStateMachine( );

    //-- protected members
    BoardPtr     board_;
    BaseTurnPtr  currentTurn_;
    InterfacePtr interface_;
    BaseTurnPtr  whiteTurn_;
    BaseTurnPtr  blackTurn_;
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
  };

}

#endif /* CHESS_GAMEPROTOCOLDRIVER_H_ */
