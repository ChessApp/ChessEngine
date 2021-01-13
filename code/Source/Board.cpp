#include "Board.h"

#include <memory>

#include "Pieces/NullPiece.h"


namespace Chess
{

  namespace
  {
    static const int min = 0;
    static const int max = 7;

    string locationToHash( const pair<int,int>& location )
    {
      if( location.first < min || location.first > max )
        throw Exception("Location is out of bounds!", "Board::locationToHash");
      if( location.second < min || location.second > max )
        throw Exception("Location is out of bounds!", "Board::locationToHash");

      return std::to_string(location.first) + std::to_string(location.second);
    }
  }

  Board::Board()
  {

  }

  void Board::movePiece( PiecePtr piece, const pair<int,int>& destination )
  {
    // First wipe the old key/value pair in the map - the piece will no longer exist at that key.
    clrPiece(piece);
    setPiece(piece, destination);
  }

  void Board::setPiece( PiecePtr piece, const pair<int,int>& destination )
  {
    piece->setLocation(destination);
    auto destinationSquare = board_.find(locationToHash(destination));
    if( destinationSquare == board_.end() )
      board_.insert({locationToHash(destination), piece});
    else
      destinationSquare->second = piece;
  }

  void Board::clrPiece( PiecePtr piece )
  {
    auto square = board_.find(locationToHash(piece->getLocation()));
    if( square == board_.end() ) return;
    board_.erase(square);
  }

  Board::PiecePtr Board::getPiece( const pair<int,int>& location )
  {
    auto square = board_.find(locationToHash(location));
    if( square != board_.end() )
      return square->second;
    else
      return std::make_shared<NullPiece>(".. ", location);
  }
 
}
