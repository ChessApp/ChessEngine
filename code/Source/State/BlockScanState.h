// #ifndef CHESS_STATE_BLOCKSCANSTATE_H_
// #define CHESS_STATE_BLOCKSCANSTATE_H_

// #include "Chess.h"
// #include "State/BaseState.h"
// #include "BaseTurn.h"


// namespace Chess
// {
//   namespace State
//   {

//     class BlockScanState
//       : public BaseState
//     {
//     public:
//       //-- types
//       typedef shared_ptr<BaseTurn> BaseTurnPtr;

//       //-- construction
//       inline BlockScanState( BaseTurnPtr & currentTurn, BaseTurnPtr whiteTurn, BaseTurnPtr blackTurn ) 
//         : currentTurn_(currentTurn),
//           whiteTurn_(whiteTurn),
//           blackTurn_(blackTurn)
//       { }

//       //-- BaseState interface
//       StatePtr execute( );

//     protected:
//       //-- protected members
//       BaseTurnPtr & currentTurn_;
//       BaseTurnPtr   whiteTurn_;
//       BaseTurnPtr   blackTurn_;
//     };

//   }
// }

// #endif /* CHESS_STATE_BLOCKSCANSTATE_H_ */
