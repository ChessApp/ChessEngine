// #include "State/PinScanState.h"

// #include "PotentialPin.h"
// #include "Pieces/NullPiece.h"
// #include "Scans/BaseScan.h"
// #include "Scans/Scanner.h"


// namespace Chess
// {
//   namespace State
//   {

//     BaseState::StatePtr PinScanState::execute( )
//     {
//       //-- local types
//       typedef shared_ptr<PotentialPin>    PotentialPinPtr;
//       typedef vector<PotentialPinPtr>     PotentialPinList;
//       typedef vector<BaseState::PiecePtr> PieceList;
//       typedef shared_ptr<BaseScan>        BaseScanPtr;

//       DEBUG_CONSOLE_1ARG("State: PIN SCAN");

//       PiecePtr kingToScan = currentTurn_->getOffensiveKing();
//       PotentialPinList & potentialPinList = currentTurn_->getPotentialPinList();
//       PieceList & pinList = currentTurn_->getPinList();

//       while( potentialPinList.size() )
//       {
//         PotentialPinPtr potentialPin = potentialPinList.back();
//         PiecePtr pinnedPiece = potentialPin->getPotentialPin();
//         BaseScanPtr scanToExecute = potentialPin->getScanToExecute();

//         removePiece(pinnedPiece);
//         Scanner::ScanResultPtr scanResult = scanToExecute->execute();
//         PiecePtr detectedPiece = scanResult->detectedPiece;

//         if( detectedPiece->validDirection(kingToScan->getRow(), kingToScan->getCol()) )
//         {
//           // Only pieces from the offensive team can pin a defending piece.
//           if( detectedPiece->getColor() != kingToScan->getColor() )
//           {
//             pinList.push_back(pinnedPiece);
//             pinnedPiece->setPinned();
//           }
//         }

//         returnPiece(pinnedPiece);
//         potentialPinList.pop_back();
//       }

//       return nextState_;
//     }

//     void PinScanState::removePiece( PiecePtr pieceToRemove )
//     {
//       PiecePtr np( new NullPiece(".. ") );
//       board_->setPiece(np, pieceToRemove->getRow(), pieceToRemove->getCol());
//     }

//     void PinScanState::returnPiece( PiecePtr pieceToReturn )
//     {
//       board_->setPiece(pieceToReturn, pieceToReturn->getRow(), pieceToReturn->getCol());
//     }

//   }
// }
