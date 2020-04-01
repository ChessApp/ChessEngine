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
          
          for( BaseTurn::PieceList::iterator p = activeList.begin(); p != activeList.end(); ++p )
          {
            if( (*p)->getType() != "K" )
            {
              for( int it = 0; it < (*s)->getRowList().size(); it++ )
              {
                int row = (*s)->getRowList()[it];
                int col = (*s)->getColList()[it];

                if( (*p)->validDirection(row, col) && (*p)->pathScan(row, col) && !(*p)->getPinnedStatus() )
                {
                  cout << "Type: " << (*p)->getType() << " Color: " << (*p)->getColor() << " DestRow: " << row << " DestCol: " << col << endl;
                  return returnState_;
                }
              }
              if( (*p)->validDirection(threatPiece->getRow(), threatPiece->getCol()) && (*p)->pathScan(threatPiece->getRow(), threatPiece->getCol()) && !(*p)->getPinnedStatus() )
              {
                cout << "Type: " << (*p)->getType() << " Color: " << (*p)->getColor() << " can neutralize threat from" << " Row: " << (*p)->getRow() << " Col: " << (*p)->getCol() << endl;
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
