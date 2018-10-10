#include "SwitchTurnState.h"

namespace Chess
{
  namespace State
  {

    BaseState * SwitchTurnState::execute ( )
    {
      std::cout << "Switch turn state" << std::endl ;
      
      // switch ( currentTurn_ )
      // {
      //   case ( whiteTurn_ ):
      //     currentTurn_ = blackTurn_ ;
      //     break ;
      //   case ( blackTurn_ ):
      //     currentTurn_ = whiteTurn_ ;
      //     break ;
      //   default:
      //     std::cout << "Error assigning new turn." << std::endl ;
      //     break ;
      // }

      interface_->printPinListDiagnostics( ) ;

      if ( currentTurn_ == whiteTurn_ )
      {
        currentTurn_ = blackTurn_ ;
      }
      else if ( currentTurn_ == blackTurn_ )
      {
        currentTurn_ = whiteTurn_ ;
      }
      else
      {
        std::cout << "Error switching turns." << std::endl ;
      }

      return nextState_ ;
    }

  }
}