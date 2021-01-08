// #ifndef CHESS_STATE_DEFENSIVECHECKSCANSTATE_H_
// #define CHESS_STATE_DEFENSIVECHECKSCANSTATE_H_

// #include "Chess.h"
// #include "State/BaseState.h"
// #include "BaseTurn.h"
// #include "Scans/BaseScan.h"
// #include "Scans/Scanner.h"
// #include "Board.h"


// namespace Chess
// {
//   namespace State
//   {

//     class DefensiveCheckScanState
//       : public BaseState
//     {
//     public:
//       //-- types
//       typedef shared_ptr<Board>     BoardPtr;
//       typedef shared_ptr<BaseTurn>  BaseTurnPtr;
//       typedef shared_ptr<BaseScan>  BaseScanPtr;

//       //-- construction
//       inline DefensiveCheckScanState( BoardPtr board, BaseTurnPtr & currentTurn ) 
//         : board_(board),
//           currentTurn_(currentTurn)
//       { }

//       //-- BaseState interface
//       virtual StatePtr execute( );
      
//     protected:
//       //-- protected methods
//       void updateGameState();
//       void configureScans( PiecePtr kingToScan );

//       //-- protected members
//       BoardPtr             board_;
//       BaseTurnPtr &        currentTurn_;
//       vector<BaseScanPtr>  scanList_;
//       bool                 status_;
//     };

//   }
// }

// #endif /* CHESS_STATE_DEFENSIVECHECKSCANSTATE_H_ */
