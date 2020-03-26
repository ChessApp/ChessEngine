#include "State/RelevancyState.h"

namespace Chess
{
  namespace State
  {

    BaseState * RelevancyState::execute ( )
    {
      std::cout << "Relevancy state" << std::endl ;

      nextState_->setWhiteKing( whiteKing_ ) ;
      nextState_->setBlackKing( blackKing_ ) ;
      
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