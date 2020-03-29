// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.
#include "Pieces/Pieces.h"


namespace Chess
{

  Pieces::Pieces( string name, string type )
    : name(name), 
      type(type), 
      in_check(false),
      prev_in_check(false), 
      pinned(false), 
      captured(false),
      color(name[0])
  {
    if (color == 'W')
      opponent = 'B';

    if (color == 'B')
      opponent = 'W';

    row = 0;
    col = 0;
  }

  Pieces::Pieces( string name, string type, int initRow, int initCol )
    : name(name), 
      type(type), 
      in_check(false),
      prev_in_check(false), 
      pinned(false), 
      captured(false),
      color(name[0])
  {
    if (color == 'W')
      opponent = 'B';

    if (color == 'B')
      opponent = 'W';

    setLocation( initRow, initCol );
  }

  bool Pieces::pieceMoved( int destRow, int destCol )
  {
    if( (destRow != row) || (destCol != col) )
      return true;
    else
      return false;
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

  char Pieces::getColor( )
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
