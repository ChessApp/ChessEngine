
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
    relevancy_ = new State::RelevancyState( interface_ ) ;
    moveValidity_ = new State::MoveValidityState( interface_, board_ ) ;
    pathscan_ = new State::PathScanState( interface_, board_ ) ;
    checkmate_ = new State::CheckmateState( interface_ ) ;

    init_->setTransitionStates( input_, input_ ) ;
    input_->setTransitionStates( relevancy_, input_ ) ;
    relevancy_->setTransitionStates( moveValidity_, input_ ) ;
    moveValidity_->setTransitionStates( pathscan_, input_ ) ;
    pathscan_->setTransitionStates( checkmate_, input_ ) ;

  }

  void GameProtocolDriver::runStateMachine ( )
  {
    currentState_ = init_->execute( ) ;
    while (currentState_ != checkmate_)
    {
      currentState_ = currentState_->execute( ) ;
    }
    currentState_->execute( ) ;
    std::cout << "State machine done." << std::endl ;
  }




}



