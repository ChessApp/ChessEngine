// This header file houses all of the data
// that composes the Pawn 
// class. This class serves to characterize
// each piece with specific data, along with
// data inherited from the Pieces class, which is 
// analyzed by the Mastermind files.


#ifndef PAWN_H_
#define PAWN_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
// #include "Interface.h"
#include "Pieces.h"

using namespace std;

namespace Chess
{

    class Pawn 
    : public Pieces
    {
    protected:

    public:

      // Contructs piece objects which take the interface object,
      // a specified name, and specified initial coordinates as
      // arguments.
      Pawn( const string name, Board * board );
      
    };


}




#endif /* PAWN_H_ */
