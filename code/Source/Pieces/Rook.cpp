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

  bool Rook::validDirection( const pair<int,int>& destination )
  {
    pieceMoved(destination);
    if( location_.first == destination.first || location_.second == destination.second ) return true;

    throw string("Rook::validDirection -> The selected piece is not capable of moving the requested direction!");
  }

  bool Rook::pathScan ( const pair<int,int>& destination )
  {
    scanner_->identifyScan( location_, destination ) ;
    Scanner::ScanResultPtr scanResult = scanner_->execute( ) ;
    PiecePtr detectedPiece = scanResult->detectedPiece ;
    
    if ( detectedPiece->getColor( ) == getColor( ) )
    {
      return false ;
    }
    else if ( detectedPiece->getRow( ) != destination.first || 
              detectedPiece->getCol( ) != destination.second )
    {
      return false ;
    }
    else
    {
      return true ;
    }

  }

  
}