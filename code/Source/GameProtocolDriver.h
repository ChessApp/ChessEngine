
#ifndef GAMEPROTOCOLDRIVER_H_
#define GAMEPROTOCOLDRIVER_H_

#include <string>
#include <sstream>
#include <vector>

#include "State/InitState.h"
#include "State/InputState.h"
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

    State::BaseState * state_ ;
    State::BaseState * checkmate_ ;
    State::BaseState * init_ ;
    State::BaseState * input_ ;


  };

}

#endif /* GAMEPROTOCOLDRIVER_H_ */