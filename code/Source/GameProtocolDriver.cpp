
#include "GameProtocolDriver.h"

namespace Chess
{

  GameProtocolDriver::GameProtocolDriver ( )
    : board_( new Board( ) )
  {
    interface_ = new Interface( board_, currentTurn_ ) ;
    whiteTurn_ = new BaseTurn( 'W' ) ;
    blackTurn_ = new BaseTurn( 'B' ) ;

    createStateMachine( ) ;
    runStateMachine( ) ;
    
  }

  void GameProtocolDriver::createStateMachine ( )
  {
    init_ = new State::InitState( interface_, board_, whiteTurn_, blackTurn_, currentTurn_ ) ;
    input_ = new State::InputState( interface_ ) ;
    relevancy_ = new State::RelevancyState( interface_ ) ;
    moveValidity_ = new State::MoveValidityState( interface_, board_ ) ;
    pathscan_ = new State::PathScanState( interface_, board_ ) ;
    move_ = new State::MoveState( interface_, board_ ) ;
    defensiveCheckScan_ = new State::DefensiveCheckScanState( interface_, board_, currentTurn_ ) ;
    returnPiece_ = new State::ReturnPieceState( interface_, board_ ) ;
    offensiveCheckScan_ = new State::OffensiveCheckScanState( interface_, board_, currentTurn_ ) ;
    switchTurn_ = new State::SwitchTurnState( interface_, whiteTurn_, blackTurn_, currentTurn_ ) ;
    pinScan_ = new State::PinScanState( interface_, board_, currentTurn_ ) ;
    checkmate_ = new State::CheckmateState( interface_ ) ;

    init_->setTransitionStates( input_, input_ ) ;
    input_->setTransitionStates( relevancy_, input_ ) ;
    relevancy_->setTransitionStates( moveValidity_, input_ ) ;
    moveValidity_->setTransitionStates( pathscan_, input_ ) ;
    pathscan_->setTransitionStates( move_, input_ ) ;
    move_->setTransitionStates( defensiveCheckScan_, input_ ) ;
    defensiveCheckScan_->setTransitionStates( offensiveCheckScan_, returnPiece_ ) ;
    returnPiece_->setTransitionStates( input_, input_ ) ;
    offensiveCheckScan_->setTransitionStates( pinScan_, pinScan_ ) ;
    pinScan_->setTransitionStates( switchTurn_, switchTurn_ ) ;
    switchTurn_->setTransitionStates( input_, input_ ) ;

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



