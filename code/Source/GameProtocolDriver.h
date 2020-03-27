#ifndef GAMEPROTOCOLDRIVER_H_
#define GAMEPROTOCOLDRIVER_H_

#include "BaseTurn.h"

#include "State/BaseState.h"
#include "State/InitState.h"
#include "State/InputState.h"
#include "State/RelevancyState.h"
#include "State/MoveValidityState.h"
#include "State/PathScanState.h"
#include "State/MoveState.h"
#include "State/DefensiveCheckScanState.h"
#include "State/ReturnPieceState.h"
#include "State/OffensiveCheckScanState.h"
#include "State/SwitchTurnState.h"
#include "State/PinScanState.h"
#include "State/EscapeRouteState.h"
#include "State/CheckmateState.h"


namespace Chess
{

  class GameProtocolDriver
  {

  public:
    typedef State::BaseState::StatePtr StatePtr;
   GameProtocolDriver ( ) ;
   // ~GameProtocolDriver( ) ;

   void createStateMachine ( ) ;

   void runStateMachine ( ) ;

   static void moveHandler ( 
     Pieces * pieceToMove, Board * board ) ;

  protected:
    Interface * interface_ ;
    Board * board_ ;
    BaseTurn * whiteTurn_ ;
    BaseTurn * blackTurn_ ;
    BaseTurn * currentTurn_ ;

    StatePtr currentState_ ;
    StatePtr checkmate_ ;
    StatePtr init_ ;
    StatePtr input_ ;
    StatePtr relevancy_ ;
    StatePtr moveValidity_ ;
    StatePtr pathscan_ ;
    StatePtr move_ ;
    StatePtr defensiveCheckScan_ ;
    StatePtr offensiveCheckScan_ ;
    StatePtr returnPiece_ ;
    StatePtr switchTurn_ ;
    StatePtr pinScan_ ;
    StatePtr escapeRoute_ ;


  };

}

#endif /* GAMEPROTOCOLDRIVER_H_ */