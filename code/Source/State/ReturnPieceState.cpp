// #include "State/ReturnPieceState.h"

// #include "Pieces/NullPiece.h"


// namespace Chess
// {
//   namespace State
//   {

//     BaseState::StatePtr ReturnPieceState::execute( )
//     {
//       DEBUG_CONSOLE_1ARG("State: RETURN PIECE");
      
//       PiecePtr pieceToReturn = board_->getPiece(interface_->destRow, interface_->destCol);
//       returnPiece(pieceToReturn, interface_->sourceRow, interface_->sourceCol);
//       // Clear the pending removal piece after returning it to its original location - 
//       // it is no longer pending removal.
//       currentTurn_->setPendingRemovedPiece( PiecePtr() );

//       return nextState_;
//     }

//     void ReturnPieceState::returnPiece( PiecePtr pieceToReturn, int rowToReturn, int colToReturn )
//     {
//       pieceToReturn->setLocation(rowToReturn, colToReturn);
//       board_->setPiece(pieceToReturn, rowToReturn, colToReturn);
//       // Restore the original piece back to its square on the board (stored
//       // in the currentTurn_ since the MoveState).
//       PiecePtr originalPiece = currentTurn_->getPendingRemovedPiece();
//       if( !originalPiece )
//       {
//         // This should never happen. If it does, we have a DEBUG
//         // printout to let us know something went wrong. We will slap
//         // a NullPiece down as a band-aid, but if this ever happens,
//         // we need to track down the bug.
//         DEBUG_CONSOLE_1ARG("Pending removal piece was NULL !!!");
//         originalPiece.reset( new NullPiece(".. ") );
//         originalPiece->setLocation(interface_->destRow, interface_->destCol);
//       }
//       board_->setPiece(originalPiece, originalPiece->getRow(), originalPiece->getCol());
//     }

//   }
// }
