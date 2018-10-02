#include "InputState.h"

namespace Chess
{
  namespace State
  {

    BaseState * InputState::execute ( )
    {
      std::cout << "Input state" << std::endl ;
      
      interface_->printGameConds( ) ;
      interface_->getInput( ) ;
      
      return nextState_ ;
    }

  }
}