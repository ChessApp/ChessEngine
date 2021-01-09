// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.
#include "Pieces/Pieces.h"
#include <string>


namespace Chess
{

  Pieces::Pieces( string name, string type )
    : name(name), 
      type(type), 
      in_check(false),
      prev_in_check(false), 
      pinned(false), 
      captured(false),
      color(name.substr(0, 1)),
      row(0),
      col(0)
  { }

  bool Pieces::pieceMoved( int destRow, int destCol )
  {
    if( (destRow == row) && (destCol == col) )
      throw Exception("Piece cannot be moved to the square it is already on!", "Pieces::pieceMoved");
    
    return true;
  }

  bool Pieces::destinationOnBoard( int destRow, int destCol )
  {
    if( destRow < 0 || destRow > 7 ||
        destCol < 0 || destCol > 7 )
      return false;
    else
      return true;
  }

  string Pieces::getType( )
  {
    return type;
  }

  string Pieces::getColor( )
  {
    return color;
  }

  string Pieces::getName( )
  {
    return name;
  }

  void Pieces::setLocation( int rowToSet, int colToSet )
  {
    row = rowToSet;
    col = colToSet;
  }

  void Pieces::clrLocation( )
  {
    row = 0;
    col = 0;
  }

}
