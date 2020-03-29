#ifndef CHESS_POTENTIALPIN_H_
#define CHESS_POTENTIALPIN_H_

#include "Chess.h"
#include "Pieces/Pieces.h"
#include "Scans/BaseScan.h"


namespace Chess
{

  class PotentialPin
  {
  public:
    //-- types
    typedef shared_ptr<Pieces>   PiecePtr;
    typedef shared_ptr<BaseScan> BaseScanPtr;
    
    //-- construction
    inline PotentialPin( PiecePtr potentialPin, BaseScanPtr scanToExecute )
      : potentialPin_(potentialPin),
        scanToExecute_(scanToExecute)
    { }

    //-- public methods
    PiecePtr    getPotentialPin( )  const { return potentialPin_; }
    BaseScanPtr getScanToExecute( ) const { return scanToExecute_; }

  protected:
    //-- protected members
    PiecePtr    potentialPin_;
    BaseScanPtr scanToExecute_;
  };

}

#endif /* CHESS_POTENTIALPIN_H_ */
