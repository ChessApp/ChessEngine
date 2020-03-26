#ifndef BASETURN_H_
#define BASETURN_H_

#include "Chess.h"
#include "Pieces/Pieces.h"
#include "Scans/ScanResult.h"


namespace Chess
{

  class PotentialPin ;

  class BaseTurn
  {

  protected:

    typedef vector< PotentialPin * > PotentialPinList ;
    typedef vector< Pieces * > PieceList ;
    typedef vector< ScanResult * > ScanResultList ;

    class PendingRemovedPiece
    {
    public:
      inline PendingRemovedPiece( Pieces * piece, int index )
        : piece_(piece),
          index_(index)
      { }
      ~PendingRemovedPiece( ) ;
      Pieces * getPiece( ) { return piece_ ; }
      int getIndex( ) { return index_ ; }

    protected:
      Pieces * piece_ ;
      int index_ ;
    };

    Pieces * defensiveKing_ ;
    Pieces * offensiveKing_ ;
    char turn_ ;
    PotentialPinList potentialPinList_ ;
    PieceList pinList_ ;
    PieceList causingCheckList_ ;
    PieceList activeList_ ;
    Pieces * pendingRemovedPiece_ ;
    ScanResultList checkScanData_ ;

    void updatePieceIndices( ) ;

  public:

    inline BaseTurn ( char turn )
      : turn_(turn)
    { }

    virtual Pieces * getDefensiveKing( ) { return defensiveKing_ ; } 
    virtual Pieces * getOffensiveKing( ) { return offensiveKing_ ; } 
    virtual void setDefensiveKing( Pieces * kingToSet ) { defensiveKing_ = kingToSet ; } 
    virtual void setOffensiveKing( Pieces * kingToSet ) { offensiveKing_ = kingToSet ; }
    char getTurn( ) { return turn_ ; }
    PotentialPinList & getPotentialPinList( ) { return potentialPinList_ ; }
    PieceList & getPinList( ) { return pinList_ ; }
    PieceList & getCausingCheckList( ) { return causingCheckList_ ; }
    PieceList & getActiveList( ) { return activeList_ ; }
    void deactivatePiece( ) ;
    Pieces * getActivePiece( int index ) { return activeList_.at( index ) ; }
    Pieces * getCausingCheckPiece( int index ) { return causingCheckList_.at( index ) ; }
    void setActivePiece( Pieces * activePiece ) ;
    void setPendingRemovedPiece( Pieces * piece ) { pendingRemovedPiece_ = piece ; }
    int getActiveListSize( ) { return activeList_.size( ) ; }
    int getCausingCheckListSize( ) { return causingCheckList_.size( ) ; }
    void addCheckScanData( ScanResult * data ) { checkScanData_.push_back( data ) ; }
    ScanResult * getCheckScanData( ) { return checkScanData_[0] ; }
    int getCheckScanDataSize( ) { return checkScanData_.size( ) ; }

  };

}

#endif /* BASETURN_H_ */