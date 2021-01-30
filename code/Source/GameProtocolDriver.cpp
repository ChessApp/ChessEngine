#include "GameProtocolDriver.h"

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

    init_               = std::make_shared<InitState>(gameState_);
    relevancy_          = std::make_shared<RelevancyState>(gameState_);
    moveValidity_       = std::make_shared<MoveValidityState>(gameState_);
    pathScan_           = std::make_shared<PathScanState>(gameState_);
    move_               = std::make_shared<MoveState>(gameState_);
    defensiveCheckScan_ = std::make_shared<DefensiveCheckScanState>(gameState_);
    returnPiece_        = std::make_shared<ReturnPieceState>(gameState_);
    offensiveCheckScan_ = std::make_shared<OffensiveCheckScanState>(gameState_);
    switchTurn_         = std::make_shared<SwitchTurnState>(gameState_);
    pinScan_            = std::make_shared<PinScanState>(gameState_);
    blockScan_          = std::make_shared<BlockScanState>(gameState_);
    escapeRoute_        = std::make_shared<EscapeRouteState>(gameState_);
    // checkmate_.reset(          new CheckmateState(interface_, currentTurn_) );
    finish_ = std::make_shared<FinishState>(gameState_);

    init_->setTransitionStates(               relevancy_,           finish_ );
    relevancy_->setTransitionStates(          moveValidity_,        finish_ );
    moveValidity_->setTransitionStates(       pathScan_,            finish_ );
    pathScan_->setTransitionStates(           move_,                finish_ );
    move_->setTransitionStates(               defensiveCheckScan_,  finish_ );
    defensiveCheckScan_->setTransitionStates( offensiveCheckScan_,  returnPiece_ );
    returnPiece_->setTransitionStates(        finish_,              finish_ );
    offensiveCheckScan_->setTransitionStates( pinScan_,             switchTurn_ );
    pinScan_->setTransitionStates(            blockScan_,           blockScan_ );
    blockScan_->setTransitionStates(          escapeRoute_,         switchTurn_ );
    escapeRoute_->setTransitionStates(        finish_,              switchTurn_ );
    switchTurn_->setTransitionStates(         finish_,              finish_ );
  }

  void GameProtocolDriver::runStateMachine( )
  {
    currentState_ = init_;
    try
    {
      while( currentState_ != nullptr )
        currentState_ = currentState_->execute();

      PLOG_INFO << "State machine done.";
    }
    catch( string error )
    {
      cout << "[ERROR] " << error << endl;
    }
    catch(...)
    {
      cout << "caught unknown exception" << endl;
    }
    gameState_.print();
  }

}
