// This header file houses all of the data
// that composes the Queen 
// class. This class serves to characterize
// each piece with specific data, along with
// data inherited from the Pieces class, which is 
// analyzed by the Mastermind files.


#ifndef QUEEN_H_
#define QUEEN_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
// #include "Interface.h"
#include "Pieces.h"
#include "../Scans/CompoundAxisScan.h"

using namespace std;

namespace Chess
{

    class Queen 
    : public Pieces
    {
    protected:

      typedef Chess::Board Board ;
      typedef Chess::Pieces Pieces ;

    public:

      // Contructs piece objects which take the interface object,
      // a specified name, and specified initial coordinates as
      // arguments.
      Queen ( const string name, Board * board, int initRow, int initCol ) ;
      Queen ( const string name, Board * board ) ;
      bool validDirection( int destRow, int destCol ) ;

      void printUpLeftScan ( ) ;

      
    };


}




#endif /* QUEEN_H_ */
