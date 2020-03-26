// This header file houses all of the data
// that composes the Rook 
// class. This class serves to characterize
// each piece with specific data, along with
// data inherited from the Pieces class, which is 
// analyzed by the Mastermind files.


#ifndef ROOK_H_
#define ROOK_H_

#include "Chess.h"
#include "Pieces/Pieces.h"
#include "Scans/SingleAxisScan.h"


namespace Chess
{

    class Rook 
    : public Pieces
    {
    protected:


    public:

      // Contructs piece objects which take the interface object,
      // a specified name, and specified initial coordinates as
      // arguments.
      Rook( const string name, Board * board, int initRow, int initCol );
      Rook( const string name, Board * board );

      bool validDirection ( int destRow, int destCol ) ;

      void printLeftScan ( ) ;

      virtual bool pathScan ( int destRow, int destCol ) ;

      //virtual bool checkValidity ( ) ;

      
    };


}




#endif /* ROOK_H_ */
