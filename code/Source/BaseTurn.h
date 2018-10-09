#ifndef BASETURN_H_
#define BASETURN_H_

#include <string>
#include <sstream>

#include "Pieces/Pieces.h"

using namespace std;

namespace Chess
{

  class BaseTurn
  {

    typedef Chess::Pieces Pieces;

  protected:

    Pieces * defensiveKing_ ;
    Pieces * offensiveKing_ ;
    char turn_ ;

  public:

    inline BaseTurn ( char turn )
      : turn_(turn)
    { }

    virtual Pieces * getDefensiveKing( ) { return defensiveKing_ ; } 
    virtual Pieces * getOffensiveKing( ) { return offensiveKing_ ; } 
    virtual void setDefensiveKing( Pieces * kingToSet ) { defensiveKing_ = kingToSet ; } 
    virtual void setOffensiveKing( Pieces * kingToSet ) { offensiveKing_ = kingToSet ; }
    char getTurn( ) { return turn_ ; }

  };

}

#endif /* BASETURN_H_ */