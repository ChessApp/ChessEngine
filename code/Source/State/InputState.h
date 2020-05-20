#ifndef CHESS_STATE_INPUTSTATE_H_
#define CHESS_STATE_INPUTSTATE_H_

#include "Chess.h"

#include "Tools/pugixml/pugixml.hpp"

#include "State/BaseState.h"
#include "Interface.h"
#include "Board.h"
#include "BaseTurn.h"


namespace Chess
{
  namespace State
  {

    class InputState
      : public BaseState
    {
    public:
      //-- types
      typedef shared_ptr<Interface> InterfacePtr;
      typedef shared_ptr<Board>     BoardPtr;
      typedef shared_ptr<BaseTurn>  BaseTurnPtr;

      //-- construction
      inline InputState( InterfacePtr interface, BoardPtr board, BaseTurnPtr & currentTurn ) 
        : interface_(interface),
          board_(board),
          currentTurn_(currentTurn)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );
      
    protected:
      //-- protected methods
      bool freshInput( );
      void clearServerFresh( pugi::xml_node & flagsNode );
      void getInput( );
      void updateGameState( );
      void updateInputList( std::string );

      //-- protected members
      InterfacePtr  interface_;
      BoardPtr      board_;
      BaseTurnPtr & currentTurn_;
    };

  }
}

#endif /* CHESS_STATE_INPUTSTATE_H_ */
