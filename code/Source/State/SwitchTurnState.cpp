#include "State/SwitchTurnState.h"

#include "Pieces/NullPiece.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr SwitchTurnState::execute( )
    {
      DEBUG_CONSOLE_1ARG("State: SWITCH TURN");

      interface_->printPinListDiagnostics();
      interface_->printBoard();

      if( currentTurn_ == whiteTurn_ )
        currentTurn_ = blackTurn_;
      else if( currentTurn_ == blackTurn_ )
        currentTurn_ = whiteTurn_;
      else
        std::cout << "Error switching turns." << std::endl;

      return nextState_;
    }

  }
}
