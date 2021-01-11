#ifndef CHESS_GAMESTATE_H_
#define CHESS_GAMESTATE_H_

#include "Chess.h"
#include "Board.h"
#include "Pieces/Pieces.h"


namespace Chess
{

  class GameState
  {
  public:
    //-- types
    enum Attacker
    {
      whiteAttacker,
      blackAttacker,
      errorAttacker
    };

    typedef Pieces::PiecePtr      PiecePtr;
    typedef vector<pair<int,int>> MoveRequest;

    //-- construction

    //-- public methods
    void setMoveRequest( string mr );
    void setAttacker( string color );
    const string serializeAttacker(); 

    //-- public members
    std::unordered_map<int, PiecePtr> activePieces;
    Attacker                          attacker;
    string                            gameId;
    string                            currentClientId;
    string                            whiteClientId;
    string                            blackClientId;
    int                               whiteKingId;
    int                               blackKingId;
    int                               capturedPieceId = -1;
    MoveRequest                       moveRequest;
    Board                             board;
    string                            moveString;
    string                            gameStateString;
    string                            errorMessage;

    void print();

  protected:
    //-- protected members
  };

}

#endif /* CHESS_GAMESTATE_H_ */
