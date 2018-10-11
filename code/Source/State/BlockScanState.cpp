#include "BlockScanState.h"

namespace Chess
{
  namespace State
  {

    BaseState * BlockScanState::execute ( )
    {
      std::cout << "Block scan state" << std::endl ;


      for ( int i = 0; i < currentTurn_->getCausingCheckListSize( ); i++ )
      {
        Pieces * piece = currentTurn_->getCausingCheckPiece( i ) ;

      }

      return nextState_ ;

    }

  }
}