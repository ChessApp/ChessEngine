// This header file houses all of the data
// that composes the King 
// class. This class serves to characterize
// each piece with specific data, along with
// data inherited from the Pieces class, which is 
// analyzed by the Mastermind files.


#ifndef KING_H_
#define KING_H_

#include "Chess.h"
#include "Pieces/Pieces.h"
#include "Scans/CompoundAxisScan.h"


namespace Chess
{

    class King 
    : public Pieces
    {
    protected:

    public:

      // Contructs piece objects which take the interface object,
      // a specified name, and specified initial coordinates as
      // arguments.
      King( const string name, Board * board, int initRow, int initCol ) ;
      King( const string name, Board * board ) ;
      bool validDirection( int destRow, int destCol ) ;
      virtual bool pathScan( int destRow, int destCol ) ;    
      
    };


}




#endif /* KING_H_ */
