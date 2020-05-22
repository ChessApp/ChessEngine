#include "State/MoveValidityState.h"

#include "Tools/pugixml/pugixml.hpp"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr MoveValidityState::execute( )
    {
      DEBUG_CONSOLE_1ARG("State: MOVE VALIDITY");

      nextState_->setWhiteKing(whiteKing_);
      nextState_->setBlackKing(blackKing_);

      int sourceRow = interface_->sourceRow;
      int sourceCol = interface_->sourceCol;
      int destRow   = interface_->destRow;
      int destCol   = interface_->destCol;

      PiecePtr currentPiece = board_->getPiece(sourceRow, sourceCol);
      if( currentPiece->validDirection(destRow, destCol) )
      {
      	return nextState_;
      }
      else
      {
        updateGameState();
      	return returnState_;
      }
    }

    void MoveValidityState::updateGameState()
    {
      // Setup the xml document structure and load the state initialization file
      pugi::xml_document doc;
      pugi::xml_parse_result result = doc.load_file(FilePaths::gameStateFile);

      // Grab the root node
      pugi::xml_node root = doc.child("root");

      pugi::xml_node messageNode  = root.child("Messages");
      messageNode.attribute("invalidMove").set_value("The move you entered was not valid. Please enter a valid move in the format provided.");
      doc.save_file(FilePaths::gameStateFile);
    }

  }
}
