#ifndef CHESS_GAMESTATE_H_
#define CHESS_GAMESTATE_H_

#include "Chess.h"
#include "Board.h"
#include "PotentialPin.h"
#include "Pieces/Pieces.h"
#include "Scans/ScanResult.h"


namespace Chess
{

  class GameState
  {
  public:
    //-- types
    enum class Attacker
    {
      white,
      black,
      error
    };

    typedef Pieces::PiecePtr         PiecePtr;
    typedef pair<int,int>            Coordinates;
    typedef vector<Coordinates>      MoveRequest;
    typedef shared_ptr<PotentialPin> PotentialPinPtr;
    typedef shared_ptr<ScanResult>   ScanResultPtr;

    //-- construction

    //-- public methods
    void setMoveRequest( string mr );
    void setAttacker( string color );
    PiecePtr getKingOfAttacker();
    PiecePtr getKingUnderAttack();
    inline int getCapturedPieceId() const { return capturedPieceId_; }
    void setCapturedPieceId( int id );
    void clearCapturedPieceId();
    const string serializeAttacker();
    void print();

    //-- public members
    std::unordered_map<int, PiecePtr> activePieces;
    vector<PotentialPinPtr>           potentialPins;
    std::unordered_map<int, PiecePtr> pinnedPieces;
    vector<PiecePtr>                  checkInducers;
    vector<ScanResultPtr>             checkPaths;
    Attacker                          attacker;
    string                            gameId;
    string                            currentClientId;
    string                            whiteClientId;
    string                            blackClientId;
    int                               whiteKingId;
    int                               blackKingId;
    MoveRequest                       moveRequest;
    Board                             board;
    string                            moveString;
    string                            gameStateString;
    string                            errorMessage;
    bool                              checkmate = false;

  protected:
    //-- protected members
    int capturedPieceId_ = -1;
  };

}

#endif /* CHESS_GAMESTATE_H_ */
