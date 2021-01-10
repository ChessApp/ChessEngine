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

  bool Queen::validDirection( const pair<int,int>& destination )
  {
    if( pieceMoved(destination) )
    {
      if( (location_.first == destination.first) || (location_.second == destination.second) )
        return true;
      else if( abs(location_.first - destination.first) == abs(location_.second - destination.second) )
        return true;
      else
        return false;
    }
    else
    {
      return false;
    }
    
  }

  bool Queen::pathScan( const pair<int,int>& destination )
  {
    scanner_->identifyScan(location_, destination);
    Scanner::ScanResultPtr scanResult = scanner_->execute();
    PiecePtr detectedPiece  = scanResult->detectedPiece;
    
    if( detectedPiece->getColor( ) == getColor( ) )
      return false;
    else if( detectedPiece->getRow( ) != destination.first || 
             detectedPiece->getCol( ) != destination.second )
      return false;
    else
      return true;
  }

}
