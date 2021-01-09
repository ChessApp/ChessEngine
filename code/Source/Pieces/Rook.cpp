// This source file houses the Pieces constructor, 
// which instantiates all of the piece objects and
// sets their initial data for the beginning of 
// the game.
#include "Pieces/Rook.h"

#include "Scans/SingleAxisScan.h"

namespace Chess
{

  Rook::Rook( const string name, Board& board )
    : Pieces(name, "R"),
      scanner_(new SingleAxisScan(board))
  { }

  bool Rook::validDirection( int destRow, int destCol )
  {
    pieceMoved(destRow, destCol);
    if( row == destRow || col == destCol ) return true;

    throw string("Rook::validDirection -> The selected piece is not capable of moving the requested direction!");
  }

  bool Rook::pathScan ( int destRow, int destCol )
  {
    scanner_->identifyScan( row, col, destRow, destCol ) ;
    Scanner::ScanResultPtr scanResult = scanner_->execute( ) ;
    PiecePtr detectedPiece = scanResult->detectedPiece ;
    
    if ( detectedPiece->getColor( ) == getColor( ) )
    {
      return false ;
    }
    else if ( detectedPiece->getRow( ) != destRow || 
              detectedPiece->getCol( ) != destCol )
    {
      return false ;
    }
    else
    {
      return true ;
    }

  }

  
}