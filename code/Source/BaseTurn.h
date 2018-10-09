#ifndef BASETURN_H_
#define BASETURN_H_

#include <string>
#include <sstream>
#include <vector>

#include "Pieces/Pieces.h"

using namespace std;

namespace Chess
{

  class PotentialPin ;

  class BaseTurn
  {

  protected:

    typedef vector< PotentialPin * > PotentialPinList ;
    typedef vector< Pieces * > PinList ;

    Pieces * defensiveKing_ ;
    Pieces * offensiveKing_ ;
    char turn_ ;
    PotentialPinList potentialPinList_ ;
    PinList pinList_ ;


  public:

    inline BaseTurn ( char turn )
      : turn_(turn)
    { }

    virtual Pieces * getDefensiveKing( ) { return defensiveKing_ ; } 
    virtual Pieces * getOffensiveKing( ) { return offensiveKing_ ; } 
    virtual void setDefensiveKing( Pieces * kingToSet ) { defensiveKing_ = kingToSet ; } 
    virtual void setOffensiveKing( Pieces * kingToSet ) { offensiveKing_ = kingToSet ; }
    char getTurn( ) { return turn_ ; }
    PotentialPinList & getPotentialPinList( ) { return potentialPinList_ ; }
    PinList & getPinList( ) { return pinList_ ; }

  };

}

#endif /* BASETURN_H_ */