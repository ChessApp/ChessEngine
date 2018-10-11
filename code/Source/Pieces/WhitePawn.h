// This header file houses all of the data
// that composes the Pawn 
// class. This class serves to characterize
// each piece with specific data, along with
// data inherited from the Pieces class, which is 
// analyzed by the Mastermind files.


#ifndef WHITEPAWN_H_
#define WHITEPAWN_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
// #include "Interface.h"
#include "Pieces.h"

using namespace std;

namespace Chess
{

    class WhitePawn 
    : public Pieces
    {
    protected:

    public:

      // Contructs piece objects which take the interface object,
      // a specified name, and specified initial coordinates as
      // arguments.
      WhitePawn( const string name, Board * board, int initRow, int initCol );
      WhitePawn( const string name, Board * board );
      bool validDirection( int destRow, int destCol ) ;
      virtual bool pathScan( int destRow, int destCol ) ; 
      
    };


}




#endif /* WHITEPAWN_H_ */
