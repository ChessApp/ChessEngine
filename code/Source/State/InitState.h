#ifndef CHESS_STATE_INITSTATE_H_
#define CHESS_STATE_INITSTATE_H_

#include "Chess.h"
#include "State/BaseState.h"
#include "Board.h"
#include "Interface.h"
#include "BaseTurn.h"


namespace Chess
{
  namespace State
  {

    class InitState
      : public BaseState
    {
    public:
      //-- types
      typedef shared_ptr<Interface> InterfacePtr;
      typedef shared_ptr<Board>     BoardPtr;
      typedef shared_ptr<BaseTurn>  BaseTurnPtr;

      //-- construction
      inline InitState ( 
        const char * configFileName,
        InterfacePtr interface,
        BoardPtr board,
        BaseTurnPtr whiteTurn,
        BaseTurnPtr blackTurn,
        BaseTurnPtr & currentTurn )
        : configFileName_(configFileName), 
          interface_(interface),
          board_(board),
          whiteTurn_(whiteTurn),
          blackTurn_(blackTurn),
          currentTurn_(currentTurn)
      { }

      //-- BaseState interface
      virtual StatePtr execute( );

    protected:
      //-- protected methods
      void setPiece( PiecePtr pieceToSet, int rowToSet, int colToSet );
      void parseInitialStateFile( );
      void initializeGameStateFile();
      void resetInputListFile();

      //-- protected members
      const char *  configFileName_;
      InterfacePtr  interface_;
      BoardPtr      board_;
      BaseTurnPtr   whiteTurn_;
      BaseTurnPtr   blackTurn_;
      BaseTurnPtr & currentTurn_;
    };

  }
}

#endif /* CHESS_STATE_INITSTATE_H_ */
