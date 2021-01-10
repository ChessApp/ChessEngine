// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.
#include "Pieces/King.h"

#include "Scans/CompoundAxisScan.h"


namespace Chess
{

  King::King( const string name, Board& board )
    : Pieces(name, "K"),
      scanner_(new CompoundAxisScan(board))
  { }

  bool King::validDirection( const pair<int,int>& destination )
  {
    if( abs(destination.second - location_.second) <= 1 &&
        abs(destination.first - location_.first) <= 1 &&
        pieceMoved(destination) )
      return true;
    else
      return false;
  }

  bool King::pathScan( const pair<int,int>& destination )
  {
    scanner_->identifyScan(location_, destination);
    Scanner::ScanResultPtr scanResult = scanner_->execute();
    PiecePtr detectedPiece = scanResult->detectedPiece;
    if( detectedPiece->getColor() == getColor() )
      return false;
    else
      return true;
  }

}
