#include "Agents/ValidationAgent.h"


namespace Chess
{
  namespace ValidationAgent
  {

    static const string wrongTeamMessage = "That piece cannot be moved because it does not pledge allegiance to the attacking team!";

    void differentSquare( const GameState::MoveRequest& moveRequest )
    {
      if( moveRequest.front() == moveRequest.back() )
        throw Exception("Piece cannot be moved to the square it is already on!", "ValidationAgent::differentSquare");
    }

    void destinationSquareAvailable( const GameState::MoveRequest& moveRequest, Board& board )
    {
      GameState::PiecePtr currentPiece = board.getPiece(moveRequest.front());
      GameState::PiecePtr destPiece = board.getPiece(moveRequest.back());

      if( currentPiece->getColor() == destPiece->getColor() )
        throw Exception("Destination square already occupied by the same team!", "ValidationAgent::destinationSquareAvailable");
    }

    void pieceOwner( GameState& gameState )
    {
      switch(gameState.attacker)
      {
        case GameState::Attacker::white:
          if( gameState.board.getPiece(gameState.moveRequest.front())->getColor() != "W" )
            throw Exception(wrongTeamMessage, "ValidationAgent::pieceOwner");
          break;

        case GameState::Attacker::black:
          if( gameState.board.getPiece(gameState.moveRequest.front())->getColor() != "B" )
            throw Exception(wrongTeamMessage, "ValidationAgent::pieceOwner");
          break;

        default:
          throw Exception("Attacker not properly set in GameState!", "ValidationAgent::pieceOwner");
      }
    }

    void isClientTurn( const GameState& gameState )
    {
      if( !(gameState.currentClientId == "1" || gameState.currentClientId == "2") )
        throw Exception("Invalid client id!", "ValidationAgent::isClientTurn");
      if( gameState.currentClientId == "1" && gameState.attacker != GameState::Attacker::white )
        throw Exception("It is not the turn of the client that issued the current request!", "ValidationAgent::isClientTurn");
      if( gameState.currentClientId == "2" && gameState.attacker != GameState::Attacker::black )
        throw Exception("It is not the turn of the client that issued the current request!", "ValidationAgent::isClientTurn");
    }

  }
}