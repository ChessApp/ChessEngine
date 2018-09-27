
#ifndef BOARD_H_
#define BOARD_H_

#include <string>
#include <sstream>
#include <vector>

#include "Pieces/Pieces.h"
#include "Pieces/NullPiece.h"
#include "Interface.h"
#include "Motion.h"

using namespace std;

#define MIN_COLUMN = 0 
#define MAX_COLUMN = 7 
#define MIN_ROW = 0 
#define MAX_ROW = 7 


namespace Chess
{

  class Board
  {


  protected:

    Pieces * board[8][8] ;
    

  public:

    Board ( ) ;

    void setPiece ( Pieces * setPiece, int row, int col ) ;

    void clrPiece ( int row, int col ) ;

    Pieces * getPiece ( int row, int col ) ;

    virtual string getPieceName ( int row, int col ) ;

  };

}

#endif /* BOARD_H_ */