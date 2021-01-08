#include "GameState.h"


namespace Chess
{

  int charToColLocation( char c )
  {
    return c - 64;
  }

  int charToRowLocation( char c )
  {
    return -(c - 57);
  }

  void GameState::setMoveRequest( string mr )
  {
    if( mr.size() != 5 ) throw;

    moveRequest.front().second = charToColLocation(mr[0]) - 1;
    moveRequest.front().first  = charToRowLocation(mr[1]) - 1;
    moveRequest.back().second  = charToColLocation(mr[3]) - 1;
    moveRequest.back().first   = charToRowLocation(mr[4]) - 1;

    for( auto p : moveRequest )
    {
      if( p.first < 0  || p.first > 7 ) throw;
      if( p.second < 0 || p.second > 7 ) throw;
    }
  }

  void GameState::print()
  {
    cout << "--- GameState ---" << endl;
    cout << "activePieces..." << endl;
    for( auto piece : activePieces )
    {
      cout << "id: " << piece.first << " name: " << piece.second->getName() << " row: " << piece.second->getRow() << " col: " << piece.second->getCol() << endl;
    }
    cout << endl;
    cout << "attacker: " << attacker << endl;
    cout << "whiteKingId: " << whiteKingId << endl;
    cout << "blackKingId: " << blackKingId << endl;
    cout << "capturedPieceId: " << capturedPieceId << endl;
    cout << "--- GameState ---" << endl;
  }
 
}
