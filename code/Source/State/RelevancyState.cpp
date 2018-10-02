#include "RelevancyState.h"

namespace Chess
{
  namespace State
  {

    BaseState * RelevancyState::execute ( )
    {
      std::cout << "Relevancy state" << std::endl ;

      if( !interface_->inputSize( ) )
      {
        return returnState_ ;
      }
      else
      {
        interface_->updateMoveSpecs( ) ;
      }
      
      if( interface_->inputValidityChecks( ) )
      {
        return nextState_ ;
      } 
      else
      {
        interface_->invalidMoveMessage( ) ;
        return returnState_ ;
      }
      
    }

  }
}