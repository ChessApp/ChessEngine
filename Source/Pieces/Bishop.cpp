// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.


#include "Bishop.h"

namespace Chess
{
  
    
  Bishop::Bishop( const string name, Board * board )
    : Pieces( name, "B" ),
      DualAxisScan( board )
  {
    
  }

  bool Bishop::validDirection ( int destRow, int destCol )
  {
    if ( abs(row - destRow) == abs(col - destCol) )
    {
      return true ;
    }
    else
    {
      return false ;
    }
  }

  void Bishop::printUpLeftScan ( )
  {
    ScanResult scanResult = upLeftScan ( row, col ) ;
    cout << scanResult.detection << endl ;
    if (scanResult.detection)
    {
      cout << scanResult.row << endl ;
      cout << scanResult.col << endl ;
      cout << scanResult.detectedPiece->getName() << endl ;
    }
    
  }

}