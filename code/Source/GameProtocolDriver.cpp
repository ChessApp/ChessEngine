#include "GameProtocolDriver.h"

#include <cstring>

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
#include "State/BlockScanState.h"
#include "State/EscapeRouteState.h"
#include "State/CheckmateState.h"
#include "State/FinishState.h"
#include "Interface.h"


namespace Chess
{

  GameProtocolDriver::GameProtocolDriver()
  {
    createStateMachine();
    runStateMachine();
  }

  void GameProtocolDriver::createStateMachine( )
  {
    using namespace State;

    init_      = std::make_shared<InitState>(gameState_);
    relevancy_ = std::make_shared<RelevancyState>(gameState_);
    // moveValidity_.reset(       new MoveValidityState(interface_, board_) );
    // pathscan_.reset(           new PathScanState(interface_, board_) );
    // move_.reset(               new MoveState(interface_, board_, currentTurn_) );
    // defensiveCheckScan_.reset( new DefensiveCheckScanState(board_, currentTurn_) );
    // returnPiece_.reset(        new ReturnPieceState(interface_, board_, currentTurn_) );
    // offensiveCheckScan_.reset( new OffensiveCheckScanState(board_, currentTurn_) );
    // switchTurn_.reset(         new SwitchTurnState(interface_, whiteTurn_, blackTurn_, currentTurn_) );
    // pinScan_.reset(            new PinScanState(board_, currentTurn_) );
    // blockScan_.reset(          new BlockScanState(currentTurn_, whiteTurn_, blackTurn_) );
    // escapeRoute_.reset(        new EscapeRouteState(interface_, board_, currentTurn_) );
    // checkmate_.reset(          new CheckmateState(interface_, currentTurn_) );
    finish_ = std::make_shared<FinishState>(gameState_);

    init_->setTransitionStates(               relevancy_,               finish_ );
    // input_->setTransitionStates(              relevancy_,           checkmate_ );
    relevancy_->setTransitionStates(          finish_,        finish_ );
    // moveValidity_->setTransitionStates(       pathscan_,            checkmate_ );
    // pathscan_->setTransitionStates(           move_,                checkmate_ );
    // move_->setTransitionStates(               defensiveCheckScan_,  checkmate_ );
    // defensiveCheckScan_->setTransitionStates( offensiveCheckScan_,  returnPiece_ );
    // returnPiece_->setTransitionStates(        checkmate_,           checkmate_ );
    // offensiveCheckScan_->setTransitionStates( pinScan_,             switchTurn_ );
    // pinScan_->setTransitionStates(            blockScan_,           switchTurn_ );
    // blockScan_->setTransitionStates(          escapeRoute_,         switchTurn_ );
    // escapeRoute_->setTransitionStates(        checkmate_,           switchTurn_ );
    // switchTurn_->setTransitionStates(         checkmate_,           checkmate_ );
  }

  void GameProtocolDriver::runStateMachine( )
  {
    try
    {
      currentState_ = init_;

      while( currentState_ != nullptr )
      {
        currentState_ = currentState_->execute();
        gameState_.print();
      }
      std::cout << "State machine done." << std::endl;
    }
    catch( string error )
    {
      cout << "[ERROR] " << error << endl;
    }
    catch(...)
    {
      cout << "caught unknown exception" << endl;
    }
  }

}
