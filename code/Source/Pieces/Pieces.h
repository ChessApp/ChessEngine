// This header file houses all of the data
// that composes the Pieces 
// class. This class serves to characterize
// each piece with specific data, which is 
// analyzed by the Mastermind files.


#ifndef PIECES_H_
#define PIECES_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

namespace Chess
{

    class Scanner ;

    class Pieces
    {

      friend class Board ;
      friend class Motion ;
      

    protected:

      bool in_check;
      bool prev_in_check;
      bool pinned;
      bool captured;
      char color;
      char opponent;
      int col;
      int row;
      string name;
      string type;
      Pieces * prevPiecePointer;
      Scanner * scanner_ ;
      Pieces * king_ ;
      

      void clrLocation ( ) ;


    public:

      // Contructs piece objects which take the interface object,
      // a specified name, and specified initial coordinates as
      // arguments.
      Pieces( const string name, string type );

      Pieces( const string name, string type, int initRow, int initCol );

      Pieces() = default;

      void setLocation ( int row, int col ) ;

      int getCol ( ) { return col ; }
      int getRow ( ) { return row ; }

      virtual string getType ( ) ;

      char getColor ( ) ;

      Pieces * getPrevPiecePointer ( ) ;

      string getPrevPiecePointerName ( ) ;

      string getName ( ) ;

      virtual bool pathScan ( int destRow, int destCol ) { return true ; }

      virtual bool validDirection( int destRow, int destCol ) { return false ; }

      virtual void setKing( Pieces * king ) { king_ = king ; }
      virtual Pieces * getKing( ) { return king_ ; }
      ~Pieces( ) { }


      //virtual bool validDirection ( int destRow, int destCol ) ;

      

    };
  
  
}




#endif /* PIECES_H_ */
