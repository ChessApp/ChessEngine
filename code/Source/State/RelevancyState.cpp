#include "State/RelevancyState.h"

#include "Tools/pugixml/pugixml.hpp"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr RelevancyState::execute( )
    {
      DEBUG_CONSOLE_1ARG("State: RELEVANCY");

      nextState_->setWhiteKing(whiteKing_);
      nextState_->setBlackKing(blackKing_);
      
      if( !interface_->inputSize() )
        return returnState_;
      else
        interface_->updateMoveSpecs();
      
      if( interface_->inputValidityChecks() )
      {
        return nextState_;
      }
      else
      {
        interface_->invalidMoveMessage();
        updateGameState();
        return returnState_;
      }
    }

    void RelevancyState::updateGameState()
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