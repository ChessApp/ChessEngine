// This header file houses all of the data
// that composes the Queen 
// class. This class serves to characterize
// each piece with specific data, along with
// data inherited from the Pieces class, which is 
// analyzed by the Mastermind files.


#ifndef QUEEN_H_
#define QUEEN_H_

#include "Chess.h"
#include "Pieces/Pieces.h"
#include "Scans/CompoundAxisScan.h"


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
      virtual bool pathScan( int destRow, int destCol ) ; 
      
    };


}




#endif /* QUEEN_H_ */
