
#ifndef MOTION_H_
#define MOTION_H_

#include <string>
#include <sstream>
#include <vector>

#include "Pieces/Pieces.h"
#include "Interface.h"
#include "Board.h"

using namespace std;

namespace Chess
{

  class Motion
  {

  protected:

    Motion ( ) = default ;

    static void moveHandler ( 
      Pieces * pieceToMove, Board * board ) ;

  };

}

#endif /* MOTION_H_ */