#include "State/BlockScanState.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr BlockScanState::execute( )
    {
      DEBUG_CONSOLE_1ARG("State: BLOCK SCAN");

      BaseTurnPtr defender;
      if( currentTurn_->getTurn() == 'W' )
        defender = blackTurn_;
      else
        defender = whiteTurn_;

      BaseTurn::ScanResultList & checkScans = currentTurn_->getCheckScanData();
      for( BaseTurn::ScanResultList::iterator s = checkScans.begin(); s != checkScans.end(); ++s )
      {
        for( int i = 0; i < currentTurn_->getCausingCheckListSize(); i++ )
        {
          PiecePtr threatPiece = currentTurn_->getCausingCheckPiece(i);
          BaseTurn::PieceList & activeList = defender->getActiveList();
          
          for( BaseTurn::PieceList::iterator defendingPiece = activeList.begin(); defendingPiece != activeList.end(); ++defendingPiece )
          {
            // A King cannot block itself. Ignore the king as a potential defending piece.
            if( (*defendingPiece)->getType() != "K" )
            {
              // Check if the defending piece can move anywhere on the attack path to block it.
              for( int it = 0; it < (*s)->getRowList().size(); it++ )
              {
                int row = (*s)->getRowList()[it];
                int col = (*s)->getColList()[it];

                // Defending piece must be able to move to the square, cannot be blocked, and also cannot be pinned.
                if( (*defendingPiece)->validDirection(row, col) && (*defendingPiece)->pathScan(row, col) && !(*defendingPiece)->getPinnedStatus() )
                {
                  cout << "Type: " << (*defendingPiece)->getType() << " Color: " << (*defendingPiece)->getColor() << " DestRow: " << row << " DestCol: " << col << endl;
                  return returnState_;
                }
              }
              // Check if the defending piece can attack the threat piece.
              if( (*defendingPiece)->validDirection(threatPiece->getRow(), threatPiece->getCol()) && (*defendingPiece)->pathScan(threatPiece->getRow(), threatPiece->getCol()) && !(*defendingPiece)->getPinnedStatus() )
              {
                cout << "Type: " << (*defendingPiece)->getType() << " Color: " << (*defendingPiece)->getColor() << " can neutralize threat from" << " Row: " << (*defendingPiece)->getRow() << " Col: " << (*defendingPiece)->getCol() << endl;
                return returnState_;
              }
            }
          }
        }
      }      

      return nextState_;
    }

  }
}
