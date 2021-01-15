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
    if( mr.size() != 5 ) throw string("Invalid client input move string!");

    moveRequest.push_back({charToRowLocation(mr[1]), charToColLocation(mr[0])});
    moveRequest.push_back({charToRowLocation(mr[4]), charToColLocation(mr[3])});

    for( auto p : moveRequest )
    {
      if( p.first < 0  || p.first > 7 ) throw string("Invalid client input move string!");
      if( p.second < 0 || p.second > 7 ) throw string("Invalid client input move string!");
    }
  }

  void GameState::print()
  {
    PLOG_VERBOSE << endl
    << "--- GameState ---" << endl
    << "gameId: " << gameId << endl
    << "currentClientId: " << currentClientId << endl
    << "whiteClientId: " << whiteClientId << endl
    << "blackClientId: " << blackClientId << endl
    << "moveString: " << moveString << endl
    << "gameStateString: " << endl << gameStateString << endl
    << "moveRequest:" << endl;
    for( auto coordinate : moveRequest )
    {
      cout << "{" << coordinate.first << ", " << coordinate.second << "} ";
    }
    cout << endl << endl;
    cout << "activePieces..." << endl;
    for( auto piece : activePieces )
    {
      cout << "id: " << piece.first << " name: " << piece.second->getName() << " row: " << piece.second->getRow() << " col: " << piece.second->getCol() << endl;
    }
    cout << endl;
    cout << "attacker: " << attacker << endl;
    cout << "whiteKingId: " << whiteKingId << endl;
    cout << "blackKingId: " << blackKingId << endl;
    cout << "capturedPieceId: " << capturedPieceId_ << endl;
    cout << endl;
    cout << "Board: " << endl;
    for( int row = 0; row < 8; row++ )
    {
      for( int col = 0; col < 8; col++ )
      {
        cout << board.getPiece({row, col})->getName();
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
    else throw Exception("Attacker is not configured!", "GameState::setAttacker");
  }

  GameState::PiecePtr GameState::getKingOfAttacker()
  {
    if( attacker == whiteAttacker )
      return activePieces.find(whiteKingId)->second;
    else
      return activePieces.find(blackKingId)->second;
  }

  GameState::PiecePtr GameState::getKingUnderAttack()
  {
    if( attacker == whiteAttacker )
      return activePieces.find(blackKingId)->second;
    else
      return activePieces.find(whiteKingId)->second;
  }

  void GameState::setCapturedPieceId( int id )
  {
    capturedPieceId_ = id;
  }

  void GameState::clearCapturedPieceId()
  {
    capturedPieceId_ = -1;
  }

  const string GameState::serializeAttacker()
  {
    switch(attacker)
    {
      case whiteAttacker: return "W";
      case blackAttacker: return "B";

      default: throw Exception("Attacker field not set properly!", "GameState::serializeAttacker");
    }
  }
 
}
