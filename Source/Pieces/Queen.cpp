// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.


#include "Queen.h"

namespace Chess
{
  
    
  Queen::Queen( const string name, Board * board )
    : Pieces( name, "Q" ),
      SingleAxisScan( board ),
      DualAxisScan( board )
  {
    
  }

  void Queen::printUpLeftScan ( )
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