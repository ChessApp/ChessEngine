
#include "GameProtocolDriver.h"

namespace Chess
{

  GameProtocolDriver::GameProtocolDriver ( )
    : board_( new Board( ) )
  {
    interface_ = new Interface( board_ ) ;

    createStateMachine( ) ;
    runStateMachine( ) ;
    
  }

  void GameProtocolDriver::createStateMachine ( )
  {
    init_ = new State::InitState( interface_, board_ ) ;
    input_ = new State::InputState( interface_ ) ;
    checkmate_ = new State::CheckmateState( interface_ ) ;

    init_->setTransitionStates( input_, input_ ) ;
    input_->setTransitionStates( checkmate_, checkmate_ ) ;

  }

  void GameProtocolDriver::runStateMachine ( )
  {
    state_ = init_->execute( ) ;
    while (state_ != checkmate_)
    {
      state_ = state_->execute( ) ;
    }
    state_->execute( ) ;
    std::cout << "State machine done." << std::endl ;
  }




}



