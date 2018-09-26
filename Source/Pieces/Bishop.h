// This header file houses all of the data
// that composes the Bishop 
// class. This class serves to characterize
// each piece with specific data, along with
// data inherited from the Pieces class, which is 
// analyzed by the Mastermind files.


#ifndef BISHOP_H_
#define BISHOP_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
// #include "Interface.h"
#include "Pieces.h"
#include "../Scans/DualAxisScan.h"

using namespace std;

namespace Chess
{

    class Bishop 
    : public Pieces,
      public DualAxisScan
    {
    protected:


    public:

      // Contructs piece objects which take the interface object,
      // a specified name, and specified initial coordinates as
      // arguments.
      Bishop ( const string name, Board * board ) ;

      bool validDirection ( int destRow, int destCol ) ;

      void printUpLeftScan ( ) ;

      
    };


}




#endif /* BISHOP_H_ */
