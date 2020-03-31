#ifndef CHESS_BASETURN_H_
#define CHESS_BASETURN_H_

#include "Chess.h"
#include "Pieces/Pieces.h"
#include "Scans/ScanResult.h"
#include "PotentialPin.h"


namespace Chess
{

  class BaseTurn
  {
  public:
    //-- types
    typedef shared_ptr<PotentialPin> PotentialPinPtr;
    typedef vector<PotentialPinPtr>  PotentialPinList;
    typedef shared_ptr<Pieces>       PiecePtr;
    typedef vector<PiecePtr>         PieceList;
    typedef shared_ptr<ScanResult>   ScanResultPtr;
    typedef vector<ScanResultPtr>    ScanResultList;

    //-- construction
    inline BaseTurn( char turn )
      : turn_(turn)
    { }

    //-- public methods
    PiecePtr            getDefensiveKing( ) { return defensiveKing_; } 
    PiecePtr            getOffensiveKing( ) { return offensiveKing_; } 
    void                setDefensiveKing( PiecePtr kingToSet ) { defensiveKing_ = kingToSet; } 
    void                setOffensiveKing( PiecePtr kingToSet ) { offensiveKing_ = kingToSet; }
    char                getTurn( ) { return turn_; }
    PotentialPinList &  getPotentialPinList( ) { return potentialPinList_; }
    PieceList &         getPinList( ) { return pinList_; }
    PieceList &         getCausingCheckList( ) { return causingCheckList_; }
    PieceList &         getActiveList( ) { return activeList_; }
    void                deactivatePiece( );
    PiecePtr            getActivePiece( int index ) { return activeList_.at(index); }
    PiecePtr            getCausingCheckPiece( int index ) { return causingCheckList_.at(index); }
    void                setActivePiece( PiecePtr activePiece );
    void                setPendingRemovedPiece( PiecePtr piece ) { pendingRemovedPiece_ = piece; }
    int                 getActiveListSize( ) { return activeList_.size(); }
    int                 getCausingCheckListSize( ) { return causingCheckList_.size(); }
    void                addCheckScanData( ScanResultPtr data ) { checkScanData_.push_back(data) ; }
    ScanResultList &    getCheckScanData( ) { return checkScanData_; }
    int                 getCheckScanDataSize( ) { return checkScanData_.size(); }

  protected:
    //-- protected types
    class PendingRemovedPiece
    {
    public:
      //-- construction
      inline PendingRemovedPiece( PiecePtr piece, int index )
        : piece_(piece),
          index_(index)
      { }

      //-- accessors
      PiecePtr getPiece( ) { return piece_; }
      int      getIndex( ) { return index_; }

    protected:
      //-- protected members
      PiecePtr piece_;
      int      index_;
    };

    //-- protected methods
    void updatePieceIndices( );

    //-- protected members
    PiecePtr          defensiveKing_;
    PiecePtr          offensiveKing_;
    char              turn_;
    PotentialPinList  potentialPinList_;
    PieceList         pinList_;
    PieceList         causingCheckList_;
    PieceList         activeList_;
    PiecePtr          pendingRemovedPiece_;
    ScanResultList    checkScanData_;
  };

}

#endif /* CHESS_BASETURN_H_ */
