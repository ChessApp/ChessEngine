#include "GameState.h"


namespace Chess
{

  int charToColLocation( char c )
  {
    return c - 65;
  }

  int charToRowLocation( char c )
  {
    return -(c - 57) -1;
  }

  void GameState::setMoveRequest( string mr )
  {
    if( mr.size() != 5 ) throw "Invalid client input move string!";

    moveRequest.push_back({charToRowLocation(mr[1]), charToColLocation(mr[0])});
    moveRequest.push_back({charToRowLocation(mr[4]), charToColLocation(mr[3])});

    for( auto p : moveRequest )
    {
      if( p.first < 0  || p.first > 7 ) throw "Invalid client input move string!";
      if( p.second < 0 || p.second > 7 ) throw "Invalid client input move string!";
    }
  }

  void GameState::print()
  {
    cout << "--- GameState ---" << endl;
    cout << "gameId: " << gameId << endl;
    cout << "currentClientId: " << currentClientId << endl;
    cout << "whiteClientId: " << whiteClientId << endl;
    cout << "blackClientId: " << blackClientId << endl;
    cout << "moveString: " << moveString << endl;
    cout << "moveRequest: {" << moveRequest.front().first << ", " 
         << moveRequest.front().second << "} -> {" << moveRequest.back().first
         << ", " << moveRequest.back().second << "}" << endl;
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

    cout << "Board: " << endl;
    for( int row = 0; row < 8; row++ )
    {
      for( int col = 0; col < 7; col++ )
      {
        cout << board.getPiece(row, col)->getName();
      }
      cout << endl;
    }
    cout << endl;
    cout << "--- GameState ---" << endl;
  }

  void GameState::setAttacker( string color )
  {
    if( color == "W" ) attacker = whiteAttacker;
    else if( color == "B" ) attacker = blackAttacker;
    else cout << "Game state does not have an attacker configured!" << endl;
  }
 
}
