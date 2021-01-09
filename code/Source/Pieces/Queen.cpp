// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.
#include "Pieces/Queen.h"

#include "Scans/CompoundAxisScan.h"


namespace Chess
{

  Queen::Queen( const string name, Board& board )
    : Pieces( name, "Q" ),
      scanner_(new CompoundAxisScan(board))
  { }

  bool Queen::validDirection( int destRow, int destCol )
  {
    if( pieceMoved(destRow, destCol) )
    {
      if( (row == destRow) || (col == destCol) )
        return true;
      else if( abs(row - destRow) == abs(col - destCol) )
        return true;
      else
        return false;
    }
    else
    {
      return false;
    }
    
  }

  bool Queen::pathScan( int destRow, int destCol )
  {
    scanner_->identifyScan(row, col, destRow, destCol);
    Scanner::ScanResultPtr scanResult = scanner_->execute();
    PiecePtr detectedPiece  = scanResult->detectedPiece;
    
    if( detectedPiece->getColor( ) == getColor( ) )
      return false;
    else if( detectedPiece->getRow( ) != destRow || 
             detectedPiece->getCol( ) != destCol )
      return false;
    else
      return true;
  }

}
