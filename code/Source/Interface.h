// This header file houses all of the data
// and functions that compose the Interface 
// class. The main service of this class is
// to drive the user interface.
#ifndef CHESS_INTERFACE_H_
#define CHESS_INTERFACE_H_

#include "Chess.h"
#include "Board.h"
#include "BaseTurn.h"
#include "Pieces/Pieces.h"


namespace Chess
{

  class Interface
  {
  public:
    //-- types    
    typedef shared_ptr<BaseTurn> BaseTurnPtr;
    typedef shared_ptr<Board>    BoardPtr;

  	//-- construction
  	Interface( BoardPtr board, BaseTurnPtr & currentTurn );

    //-- public methods
    void printPinListDiagnostics( );
    void updateUserBoard( ); 
    bool inputContent( );
    bool inputSize( );
    bool inputDiffSqr( );
    bool inputSqrAvailable( );
    bool inputPieceOwner( );
    bool inputValidityChecks( );
  	void printBoard( );
  	void printGameConds( );
  	void getInput( );
  	void updateMoveSpecs( );
  	void invalidMoveMessage( );
  	void inCheckMessage( );
  	void checkmateStatus( );
    int  colLocation( char user_col );
    int  rowLocation( char user_row );

    //-- public members
    int sourceCol;
    int sourceRow;
    int destCol;
    int destRow;

  protected:
    //-- protected types
    typedef shared_ptr<Pieces> PiecePtr;

    //-- protected members
    BoardPtr      board_;
    PiecePtr      currentPiece_;
    PiecePtr      destPiece_;
    string        userBoard_[11][11];
    string        userInput_;
    char          checkStatus_;
    char          turn_;
    BaseTurnPtr & currentTurn_;
  };

}

#endif /* CHESS_INTERFACE_H_ */
