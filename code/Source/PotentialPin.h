#ifndef POTENTIALPIN_H_
#define POTENTIALPIN_H_

#include "Chess.h"
#include "Pieces/Pieces.h"
#include "Scans/BaseScan.h"


namespace Chess
{

  class PotentialPin
  {

  protected:

    Pieces * potentialPin_ ;
    BaseScan * scanToExecute_ ;

  public:

    inline PotentialPin ( 
      Pieces * potentialPin,
      BaseScan * scanToExecute )
      : potentialPin_(potentialPin),
        scanToExecute_(scanToExecute)
    { }

    Pieces * getPotentialPin( ) const { return potentialPin_ ; }
    BaseScan * getScanToExecute( ) const { return scanToExecute_ ; }

  };

}

#endif /* POTENTIALPIN_H_ */