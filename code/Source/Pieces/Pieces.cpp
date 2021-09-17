#include "Pieces/Pieces.h"
#include "GameState.h"


namespace Chess
{

  Pieces::Pieces( const string& name, string type, const pair<int,int>& location )
    : name_(name),
      type_(type),
      in_check_(false),
      prev_in_check_(false), 
      pinned_(false), 
      captured_(false),
      color_(name.substr(0,1) == "." ? "" : name.substr(0, 1)), // short-term hack to set nullpiece color as empty string
      location_(location),
      id_(-1)
  { }

  bool Pieces::pieceMoved( const pair<int,int>& destination )
  {
    if( location_ == destination )
      return false;
    else
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
