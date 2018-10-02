#include "CheckmateState.h"

namespace Chess
{
  namespace State
  {

    BaseState * CheckmateState::execute ( )
    {
      interface_->printBoard( ) ;
      std::cout << "Checkmate!" << std::endl ;

      return nextState_ ;
    }

  }
}