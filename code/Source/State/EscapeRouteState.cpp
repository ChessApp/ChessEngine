// #include "State/EscapeRouteState.h"

// #include "Pieces/Pieces.h"
// #include "Pieces/NullPiece.h"


// namespace Chess
// {
//   namespace State
//   {

//     BaseState::StatePtr EscapeRouteState::execute( )
//     {
//       DEBUG_CONSOLE_1ARG("State: ESCAPE ROUTE");

//       PiecePtr kingToEscape = currentTurn_->getOffensiveKing();
//       int originalKingRow = kingToEscape->getRow();
//       int originalKingCol = kingToEscape->getCol();
      
//       for( int j = -1; j <= 1; j++ )
//       {
//         for( int i = -1; i <= 1; i++ )
//         {
//           int destRow = originalKingRow + j;
//           int destCol = originalKingCol + i;
//           if( kingToEscape->validDirection(destRow, destCol) && kingToEscape->pathScan(destRow, destCol) )
//           {
//             // Stash the original piece at the destination location
//             // so we can return it after scan.
//             PiecePtr originalPiece = board_->getPiece(destRow, destCol);

//             setPiece(kingToEscape, destRow, destCol);

//             DEBUG_CONSOLE_1ARG("Theoretical escape route:");
//             DEBUG_CONSOLE_PRINT_BOARD(interface_);

//             configureScans(kingToEscape);

//             // Check if there are any pieces that can still attack on this
//             // attempted escape route.
//             bool escapeRoute = executeScans(kingToEscape);
//             // Perform clean-up, regardless of the result.
//             returnPiece(kingToEscape, originalKingRow, originalKingCol, originalPiece);

//             // Transition to the ReturnState if there is an escape route.
//             // *sigh of relief*
//             if(escapeRoute)
//               return returnState_;
//           }
//         }
//       }     

//       return nextState_;
//     }

//     /* Executes a scan in every direction from the location of the King
//        that is attempting to escape. If another piece is detected on any
//        of these scans, the piece will be checked to see if it can attack
//        on the scan path, and that it is on the opposite team. This method
//        returns true if the escape route cannot be attacked.
//      */
//     bool EscapeRouteState::executeScans( PiecePtr kingToEscape )
//     {
//       while( scanList_.size() )
//       {
//         BaseScanPtr currentScan = scanList_.back();
//         scanList_.pop_back();
//         Scanner::ScanResultPtr scanResult = currentScan->execute();
//         PiecePtr detectedPiece = scanResult->detectedPiece;

//         // Verify that the detected piece can attack the king, and that they are on opposite
//         // teams.
//         if( ( detectedPiece->validDirection(kingToEscape->getRow(), kingToEscape->getCol()) ) )
//         {
//           if( kingToEscape->getColor() != detectedPiece->getColor() )
//           {
// #ifdef DEBUG
//             cout << "[***DEBUG CONSOLE***] " << "Escape attempt soiled by: " << detectedPiece->getType() << " at [" << detectedPiece->getRow() << "," << detectedPiece->getCol() << "]" << endl;
// #endif
//             return false;
//           }
//         }
//       }

//       return true;
//     }

//     void EscapeRouteState::setPiece( PiecePtr pieceToSet, int rowToSet, int colToSet )
//     {
//       // Create a NullPiece and set its location as the original location
//       // of the pieceToSet, before that piece gets its location updated.
//       PiecePtr np( new NullPiece(".. ") );
//       np->setLocation(pieceToSet->getRow(), pieceToSet->getCol());

//       pieceToSet->setLocation(rowToSet, colToSet);
//       // Update the board with the new locations of the 2 affected pieces.
//       board_->setPiece(pieceToSet, rowToSet, colToSet);
//       board_->setPiece(np, np->getRow(), np->getCol());
//     }

//     void EscapeRouteState::returnPiece( PiecePtr pieceToReturn, int rowToReturn, int colToReturn, PiecePtr originalPiece )
//     {
//       // Reset the location of the pieceToReturn.
//       pieceToReturn->setLocation(rowToReturn, colToReturn);

//       // Update the new piece locations on the board.
//       board_->setPiece(pieceToReturn, rowToReturn, colToReturn);
//       board_->setPiece(originalPiece, originalPiece->getRow(), originalPiece->getCol());
//     }

//     void EscapeRouteState::configureScans( PiecePtr kingToScan )
//     {
//       scanList_.push_back( BaseScanPtr( new Scanner::LeftScan(      board_, kingToScan->getRow( ), kingToScan->getCol( ), kingToScan->getRow( ), 0 ) ) );
//       scanList_.push_back( BaseScanPtr( new Scanner::RightScan(     board_, kingToScan->getRow( ), kingToScan->getCol( ), kingToScan->getRow( ), 7 ) ) );
//       scanList_.push_back( BaseScanPtr( new Scanner::UpScan(        board_, kingToScan->getRow( ), kingToScan->getCol( ), 0, kingToScan->getCol( ) ) ) );
//       scanList_.push_back( BaseScanPtr( new Scanner::DownScan(      board_, kingToScan->getRow( ), kingToScan->getCol( ), 7, kingToScan->getCol( ) ) ) );
//       scanList_.push_back( BaseScanPtr( new Scanner::UpLeftScan(    board_, kingToScan->getRow( ), kingToScan->getCol( ), 0, 0 ) ) );
//       scanList_.push_back( BaseScanPtr( new Scanner::DownLeftScan(  board_, kingToScan->getRow( ), kingToScan->getCol( ), 7, 0 ) ) );
//       scanList_.push_back( BaseScanPtr( new Scanner::UpRightScan(   board_, kingToScan->getRow( ), kingToScan->getCol( ), 0, 7 ) ) );
//       scanList_.push_back( BaseScanPtr( new Scanner::DownRightScan( board_, kingToScan->getRow( ), kingToScan->getCol( ), 7, 7 ) ) );
//     }

//   }
// }
