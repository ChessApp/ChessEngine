// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.
#include "Pieces/Pieces.h"
#include "GameState.h"


namespace Chess
{

  const string Pieces::invalidDirectionMessage_ = "The selected piece is not capable of moving the requested direction!";

  Pieces::Pieces( const string& name, string type )
    : name_(name),
      type_(type),
      in_check_(false),
      prev_in_check_(false), 
      pinned_(false), 
      captured_(false),
      color_(name.substr(0, 1)),
      location_({0,0}),
      id_(-1)
  { }

  bool Pieces::pieceMoved( const pair<int,int>& destination )
  {
    if( location_ == destination )
      throw Exception("Piece cannot be moved to the square it is already on!", "Pieces::pieceMoved");
    
    return true;
  }

  string Pieces::getType( )
  {
    return type_;
  }

  string Pieces::getColor( )
  {
    return color_;
  }

  string Pieces::getName( )
  {
    return name_;
  }

  void Pieces::setLocation( const pair<int,int>& location )
  {
    location_ = location;
  }

  void Pieces::clrLocation( )
  {
    location_ = {0,0};
  }

}
