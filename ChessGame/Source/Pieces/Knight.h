// This header file houses all of the data
// that composes the Knight 
// class. This class serves to characterize
// each piece with specific data, along with
// data inherited from the Pieces class, which is 
// analyzed by the Mastermind files.


#ifndef KNIGHT_H_
#define KNIGHT_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
// #include "Interface.h"
#include "Pieces.h"

using namespace std;

namespace Chess
{

    class Knight 
    : public Pieces
      
    {
    protected:

      typedef Chess::Pieces Pieces ;


    public:

      // Contructs piece objects which take the interface object,
      // a specified name, and specified initial coordinates as
      // arguments.
      Knight ( const string name, Board * board ) ;
      
    };


}




#endif /* KNIGHT_H_ */
