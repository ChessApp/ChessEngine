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
    PLOG_DEBUG << endl
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
      PLOG_DEBUG << "{" << coordinate.first << ", " << coordinate.second << "} ";
    }
    PLOG_DEBUG << "activePieces..." << endl;
    for( auto piece : activePieces )
    {
      PLOG_DEBUG << "id: " << piece.first << " name: " << piece.second->getName() << " row: " << piece.second->getRow() << " col: " << piece.second->getCol() << endl;
    }
    PLOG_DEBUG << "attacker: " << static_cast<int>(attacker) << endl;
    PLOG_DEBUG << "whiteKingId: " << whiteKingId << endl;
    PLOG_DEBUG << "blackKingId: " << blackKingId << endl;
    PLOG_DEBUG << "capturedPieceId: " << capturedPieceId_ << endl;
    PLOG_DEBUG << "potentialPins:" << endl;
    for( auto p : potentialPins )
    {
      PLOG_DEBUG << "name: " << p->getPiece()->getName() << " loc: {" << p->getPiece()->getRow() << "," << p->getPiece()->getCol() << "}" << endl;
    }
    PLOG_DEBUG << "checkmate: " << checkmate << endl;
    PLOG_DEBUG << "pinnedPieces:" << endl;
    for( auto p : pinnedPieces )
    {
      PLOG_DEBUG << "name: " << p.second->getName() << " loc: {" << p.second->getRow() << "," << p.second->getCol() << "}" << endl;
    }
    cout << endl;
    PLOG_DEBUG << "Board: " << endl;
    for( int row = 0; row < 8; row++ )
    {
      for( int col = 0; col < 8; col++ )
      {
        cout << board.getPiece({row, col})->getName();
      }
      cout << endl;
    }
    cout << endl;
    PLOG_DEBUG << "--- GameState ---" << endl;
  }

  void GameState::setAttacker( string color )
  {
    if( color == "W" ) attacker = Attacker::white;
    else if( color == "B" ) attacker = Attacker::black;
    else throw Exception("Attacker is not configured!", "GameState::setAttacker");
  }

  GameState::PiecePtr GameState::getKingOfAttacker()
  {
    if( attacker == Attacker::white )
      return activePieces.find(whiteKingId)->second;
    else
      return activePieces.find(blackKingId)->second;
  }

  GameState::PiecePtr GameState::getKingUnderAttack()
  {
    if( attacker == Attacker::white )
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
      case Attacker::white: return "W";
      case Attacker::black: return "B";

      default: throw Exception("Attacker field not set properly!", "GameState::serializeAttacker");
    }
  }
 
}
