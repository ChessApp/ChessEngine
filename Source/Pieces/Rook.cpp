// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.


#include "Rook.h"

namespace Chess
{

    
  Rook::Rook( const string name, Board * board )
  	: Pieces( name, "R" ),
      SingleAxisScan( board )
  {
  	
  }

  bool Rook::validDirection ( int destRow, int destCol )
  {
    if ( row == destRow || col == destCol )
    {
      return true ;
    }
    else
    {
      // throw "That move is invalid." ;
      return false ;
    }
  }

  void Rook::printLeftScan ( )
  {
    ScanResult scanResult = leftScan ( row, col ) ;
    cout << scanResult.col << endl ;
    if (scanResult.detection)
    {
      cout << scanResult.detection << endl ;
      cout << scanResult.row << endl ;
      cout << scanResult.detectedPiece->getName() << endl ;
    }
    
  }
  
}