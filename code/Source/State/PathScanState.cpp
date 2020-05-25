#include "State/PathScanState.h"

#include "Tools/pugixml/pugixml.hpp"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr PathScanState::execute( )
    {
      DEBUG_CONSOLE_1ARG("State: PATH SCAN");
      
      PiecePtr currentPiece = board_->getPiece(interface_->sourceRow, interface_->sourceCol);
      if( currentPiece->pathScan(interface_->destRow, interface_->destCol) )
      {
        return nextState_;
      }
      else
      {
        updateGameState();
        return returnState_;
      }
    }

    void PathScanState::updateGameState()
    {
      // Setup the xml document structure and load the state initialization file
      pugi::xml_document doc;
      pugi::xml_parse_result result = doc.load_file(FilePaths::gameStateFile);

      // Grab the root node
      pugi::xml_node root = doc.child("root");

      pugi::xml_node messageNode  = root.child("Messages");
      messageNode.attribute("invalidMove").set_value("The move you entered was not valid - there is another piece obstructing your path. Please enter a valid move in the format provided.");
      doc.save_file(FilePaths::gameStateFile);
    }

  }
}
