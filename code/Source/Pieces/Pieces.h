// This header file houses all of the data
// that composes the Pieces 
// class. This class serves to characterize
// each piece with specific data, which is 
// analyzed by the Mastermind files.
#ifndef CHESS_PIECES_H_
#define CHESS_PIECES_H_

#include "Chess.h"


namespace Chess
{

  class Pieces
  {
  public:
    //-- types
    typedef shared_ptr<Pieces> PiecePtr;
    
    //-- construction
    Pieces( const string name, string type );

    //-- interface methods
    virtual bool pathScan( const pair<int,int>& destination )       { return false; }
    virtual bool validDirection( const pair<int,int>& destination ) { return false; }

    //-- accessors
    string   getType( );
    string   getColor( );
    string   getName( );
    void     setLocation( const pair<int,int>& location );
    int      getCol( )    { return location_.second; }
    int      getRow( )    { return location_.first; }
    void     setPinned( ) { pinned_ = true; }
    void     clrPinned( ) { pinned_ = false; }
    bool     getPinnedStatus( ) { return pinned_; }
    void     setId( int id ) { id_ = id; }
    int      getId() const { return id_; }

    //-- miscellaneous public methods
    bool pieceMoved( const pair<int,int>& destination );

  protected:
    //-- protected methods
    void clrLocation( );

    //-- protected members
    bool          in_check_;
    bool          prev_in_check_;
    bool          pinned_;
    bool          captured_;
    string        color_;
    pair<int,int> location_;
    string        name_;
    string        type_;
    int           id_;
  };

}

#endif /* CHESS_PIECES_H_ */
