#ifndef SWITCHTURNSTATE_H_
#define SWITCHTURNSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "BaseTurn.h"
#include "Interface.h"
#include "Board.h"
#include "Pieces/Pieces.h"
#include "Pieces/NullPiece.h"


namespace Chess
{
  namespace State
  {

    class SwitchTurnState
      : public BaseState
    {
    public:
      virtual BaseState * execute( ) ;

      inline SwitchTurnState ( 
        Interface * interface,
        BaseTurn * whiteTurn,
        BaseTurn * blackTurn,
        BaseTurn *& currentTurn ) 
        : interface_(interface),
          whiteTurn_(whiteTurn),
          blackTurn_(blackTurn),
          currentTurn_(currentTurn)      
      { }
      
    protected:
      Interface * interface_ ;
      BaseTurn *& currentTurn_ ;
      BaseTurn * whiteTurn_ ;
      BaseTurn * blackTurn_ ;

    };

  }
}

#endif /* SWITCHTURNSTATE_H_ */