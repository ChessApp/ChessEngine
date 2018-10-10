#include "PinScanState.h"

namespace Chess
{
  namespace State
  {

    BaseState * PinScanState::execute ( )
    {
      std::cout << "Pin scan state" << std::endl ;
      return nextState_ ;
    }

    void PinScanState::removePiece( Pieces * pieceToRemove )
    {
      Pieces * np = new NullPiece( ".. ", board_ ) ;
      board_->setPiece( np, pieceToRemove->getRow( ), pieceToRemove->getCol( ) ) ;
    }

  }
}