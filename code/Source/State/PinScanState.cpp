#include "State/PinScanState.h"

namespace Chess
{
  namespace State
  {

    BaseState::StatePtr PinScanState::execute ( )
    {
      std::cout << "Pin scan state" << std::endl ;

      Pieces * kingToScan = currentTurn_->getOffensiveKing( ) ;
      PotentialPinList potentialPinList = currentTurn_->getPotentialPinList( ) ;
      PieceList pinList = currentTurn_->getPinList( ) ;

      while ( potentialPinList.size( ) )
      {
        PotentialPin * potentialPin = potentialPinList.back( ) ;
        Pieces * pinnedPiece = potentialPin->getPotentialPin( ) ;
        BaseScan * scanToExecute = potentialPin->getScanToExecute( ) ;

        removePiece( pinnedPiece ) ;
        ScanResult * scanResult = scanToExecute->execute( ) ;
        Pieces * detectedPiece = scanResult->detectedPiece ;
        if ( detectedPiece->getColor( ) == kingToScan->getColor( ) )
        {      
        }
        else if ( detectedPiece->validDirection( kingToScan->getRow( ), kingToScan->getCol( ) ) )
        {        
          pinList.push_back( pinnedPiece ) ;
          pinnedPiece->setPinned( ) ; 
        }
        returnPiece( pinnedPiece ) ;
        potentialPinList.pop_back( ) ;
      }

      return nextState_ ;
    }

    void PinScanState::removePiece( Pieces * pieceToRemove )
    {
      Pieces * np = new NullPiece( ".. " ) ;
      board_->setPiece( np, pieceToRemove->getRow( ), pieceToRemove->getCol( ) ) ;
    }

    void PinScanState::returnPiece( Pieces * pieceToReturn )
    {
      board_->setPiece( pieceToReturn, pieceToReturn->getRow( ), pieceToReturn->getCol( ) ) ;
    }

  }
}