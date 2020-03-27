#ifndef RETURNPIECESTATE_H_
#define RETURNPIECESTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "Interface.h"
#include "Board.h"
#include "Pieces/Pieces.h"
#include "Pieces/NullPiece.h"


namespace Chess
{
  namespace State
  {

    class ReturnPieceState
      : public BaseState
    {
    public:
      virtual StatePtr execute( ) ;

      inline ReturnPieceState ( Interface * interface, Board * board ) 
        : interface_(interface),
          board_(board)
      { }

      void returnPiece( Pieces * pieceToReturn, int rowToReturn, int colToReturn ) ;
    
      
    protected:
      Interface * interface_ ;
      Board *     board_ ;

    };

  }
}

#endif /* RETURNPIECESTATE_H_ */