
#ifndef GAMEPROTOCOLDRIVER_H_
#define GAMEPROTOCOLDRIVER_H_

#include <string>
#include <sstream>
#include <vector>

#include "State/InitState.h"
#include "State/InputState.h"
#include "State/RelevancyState.h"
#include "State/MoveValidityState.h"
#include "State/PathScanState.h"
#include "State/MoveState.h"
#include "State/DefensiveCheckScanState.h"
#include "State/ReturnPieceState.h"
#include "State/CheckmateState.h"


using namespace std;

namespace Chess
{

  class GameProtocolDriver
  {

  public:

   GameProtocolDriver ( ) ;
   // ~GameProtocolDriver( ) ;

   void createStateMachine ( ) ;

   void runStateMachine ( ) ;

   static void moveHandler ( 
     Pieces * pieceToMove, Board * board ) ;

  protected:
    Interface * interface_ ;
    Board * board_ ;

    State::BaseState * currentState_ ;
    State::BaseState * checkmate_ ;
    State::BaseState * init_ ;
    State::BaseState * input_ ;
    State::BaseState * relevancy_ ;
    State::BaseState * moveValidity_ ;
    State::BaseState * pathscan_ ;
    State::BaseState * move_ ;
    State::BaseState * defensiveCheckScan_ ;
    State::BaseState * returnPiece_ ;


  };

}

#endif /* GAMEPROTOCOLDRIVER_H_ */