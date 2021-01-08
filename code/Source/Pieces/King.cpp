// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.
#include "Pieces/King.h"

#include "Scans/CompoundAxisScan.h"


namespace Chess
{

  King::King( const string name, Board& board, int initRow, int initCol )
    : Pieces(name, "K", initRow, initCol),
      scanner_(new CompoundAxisScan(board))
  {
    setKing(this);
  }

  King::King( const string name, Board& board )
    : Pieces(name, "K"),
      scanner_(new CompoundAxisScan(board))
  {
    setKing(this);
  }

  bool King::validDirection( int destRow, int destCol )
  {
    if( abs(destCol - col) <= 1 &&
        abs(destRow - row) <= 1 &&
        pieceMoved(destRow, destCol) &&
        destinationOnBoard(destRow, destCol) )
      return true;
    else
      return false;
  }

  bool King::pathScan( int destRow, int destCol )
  {
    scanner_->identifyScan(row, col, destRow, destCol);
    Scanner::ScanResultPtr scanResult = scanner_->execute();
    PiecePtr detectedPiece = scanResult->detectedPiece;
    if( detectedPiece->getColor() == getColor() )
      return false;
    else
      return true;
  }

}
