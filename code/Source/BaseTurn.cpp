#include "BaseTurn.h"

namespace Chess
{

  void BaseTurn::deactivatePiece( ) 
  { 
    if ( pendingRemovedPiece_ ) 
    {
      int index = pendingRemovedPiece_->getActiveListIndex( ) ;
      pendingRemovedPiece_->clrActiveListIndex( ) ;
      activeList_.erase( activeList_.begin( ) + index ) ;
      pendingRemovedPiece_ = NULL ;
      updatePieceIndices( ) ;
    }
  }

  void BaseTurn::setActivePiece( Pieces * activePiece )
  {
    activePiece->setActiveListIndex( activeList_.size( ) ) ;
    activeList_.push_back( activePiece ) ;
  }

  void BaseTurn::updatePieceIndices( )
  {
    for ( int i = 0; i < activeList_.size( ); i++ )
    {
      Pieces * piece = getActivePiece( i ) ;
      piece->setActiveListIndex( i ) ;
    }
  }

}
