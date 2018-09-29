
#include "GameProtocolDriver.h"

namespace Chess
{

  GameProtocolDriver::GameProtocolDriver ( )
    : board_( new Board( ) )
  {
    interface_ = new Interface( board_ ) ;

    pieceList.push_back( new Rook( " R ", board_ ) ) ;

    board_->init( pieceList, new NullPiece( ".. ", board_ ) ) ;

    interface_->printBoard( ) ;
    
  }

  void GameProtocolDriver::moveHandler (  
    Pieces * pieceToMove, Board * board )
  {


  }



}



