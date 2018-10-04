// This header file houses all of the data
// that composes the NullPiece 
// class. This class serves to characterize
// each piece with specific data, along with
// data inherited from the Pieces class, which is 
// analyzed by the Mastermind files.


#ifndef NULLPIECE_H_
#define NULLPIECE_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
// #include "Interface.h"
#include "Pieces.h"

using namespace std;

namespace Chess
{

    class NullPiece 
    : public Pieces
    {
    protected:

      

    public:

      // Contructs piece objects which take the interface object,
      // a specified name, and specified initial coordinates as
      // arguments.
      NullPiece( const string name, Board * board );
      ~NullPiece( ) { }

      bool validDirection ( int destRow, int destCol ) ;
      
    };


}


#endif /* NULLPIECE_H_ */
