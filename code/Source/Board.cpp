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

  void Board::setPiece( PiecePtr piece, const pair<int,int>& destination )
  {
    board_.insert({locationToHash(destination), piece});
  }

  void Board::clrPiece( const pair<int,int>& location )
  {
    board_.erase(locationToHash(location));
  }

  Board::PiecePtr Board::getPiece( const pair<int,int>& location )
  {
    
    auto square = board_.find(locationToHash(location));
    if( square != board_.end() ) return square->second;
    else return std::make_shared<NullPiece>(".. ");
  }
 
}
