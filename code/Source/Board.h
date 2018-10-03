
#ifndef BOARD_H_
#define BOARD_H_

#include <string>
#include <sstream>
#include <vector>

// #include "Pieces/Pieces.h"

#include "Interface.h"

using namespace std;

#define MIN_COLUMN 0 
#define MAX_COLUMN 7 
#define MIN_ROW 0 
#define MAX_ROW 7 


namespace Chess
{

  class Pieces ;
  //class Rook ;
  class NullPiece ;

  class Board
  {


  protected:

    Pieces * board[8][8] ;
    Pieces * nullpiece_ ;


  public:

    Board ( ) ;

    void init ( vector< Pieces * > & nullPieceList ) ;

    void setPiece ( Pieces * setPiece, int row, int col ) ;

    void clrPiece ( int row, int col ) ;

    Pieces * getPiece ( int row, int col ) ;

    virtual string getPieceName ( int row, int col ) ;

    

  };

}

#endif /* BOARD_H_ */