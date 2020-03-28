#include "State/SwitchTurnState.h"

#include "Pieces/Pieces.h"
#include "Pieces/NullPiece.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr SwitchTurnState::execute( )
    {
      std::cout << "Switch turn state" << std::endl;

      interface_->printPinListDiagnostics();

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
