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
        // cout << "size: " << (*s)->getRowList().size() << endl;
        // cout << "threatPiece rows:" << endl;
        // for( vector<int>::iterator r = (*s)->getRowList().begin(); r != (*s)->getRowList().end(); ++r )
        //   cout << *r << endl;

        // cout << "threatPiece cols:" << endl;
        // for( vector<int>::iterator c = (*s)->getColList().begin(); c != (*s)->getColList().end(); ++c )
        //   cout << *c << endl;

        // cout << "size: " << (*s)->getRowList().size() << endl;

        // cout << "scan" << endl;
        for( int i = 0; i < currentTurn_->getCausingCheckListSize(); i++ )
        {
          // cout << "size: " << (*s)->getRowList().size() << endl;
          // cout << "threat" << endl;
          PiecePtr threatPiece = currentTurn_->getCausingCheckPiece(i);
          BaseTurn::PieceList & activeList = defender->getActiveList();
          for( BaseTurn::PieceList::iterator p = activeList.begin(); p != activeList.end(); ++p )
          {
            if( (*p)->getType() != "K" )
            {
              for( int it = 0; it < (*s)->getRowList().size(); it++ )
              {
                // cout << "squares" << endl;
                int row = (*s)->getRowList()[it];
                int col = (*s)->getColList()[it];
                // cout << "row: " << row << " col: " << col << endl;
                if( (*p)->validDirection(row, col) && (*p)->pathScan(row, col) && !(*p)->getPinnedStatus() )
                {
                  cout << "Type: " << (*p)->getType() << " Color: " << (*p)->getColor() << " DestRow: " << row << " DestCol: " << col << endl;
                  // return returnState_;
                }
              }
              if( (*p)->validDirection(threatPiece->getRow(), threatPiece->getCol()) && (*p)->pathScan(threatPiece->getRow(), threatPiece->getCol()) && !(*p)->getPinnedStatus() )
              {
                cout << "Type: " << (*p)->getType() << " Color: " << (*p)->getColor() << " can neutralize threat from" << " Row: " << (*p)->getRow() << " Col: " << (*p)->getCol() << endl;
                // return returnState_;
              }
            }
          }
        }
      }      

      return nextState_;
    }

  }
}
