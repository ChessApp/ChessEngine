#include "State/SwitchTurnState.h"

#include "Tools/pugixml/pugixml.hpp"

#include "Pieces/NullPiece.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr SwitchTurnState::execute( )
    {
      DEBUG_CONSOLE_1ARG("State: SWITCH TURN");

      updateGameState();
      currentTurn_->getCausingCheckList().clear();
      currentTurn_->getPotentialPinList().clear();
      currentTurn_->getPinList().clear();
      // Should not be needed, but for added protection we leave it in for now.
      // This is worthy of reassessment during the next refactor.
      whiteTurn_->setPendingRemovedPiece( PiecePtr() );
      blackTurn_->setPendingRemovedPiece( PiecePtr() );

      interface_->printPinListDiagnostics();

      if( currentTurn_ == whiteTurn_ )
        currentTurn_ = blackTurn_;
      else if( currentTurn_ == blackTurn_ )
        currentTurn_ = whiteTurn_;
      else
        std::cout << "Error switching turns." << std::endl;

      return nextState_;
    }

    void SwitchTurnState::updateGameState()
    {
      // Setup the xml document structure and load the state initialization file
      pugi::xml_document doc;
      pugi::xml_parse_result result = doc.load_file(FilePaths::gameStateFile);

      // Grab the root node
      pugi::xml_node root = doc.child("root");

      pugi::xml_node flagsNode     = root.child("Flags");
      pugi::xml_node turnNode      = root.child("Turn");
      pugi::xml_node messagesNode  = root.child("Messages");

      flagsNode.attribute("invalidMove").set_value(0);
      turnNode.attribute("checkStatus").set_value(currentTurn_->getCausingCheckList().size());
      messagesNode.attribute("invalidMove").set_value("");
      
      doc.save_file(FilePaths::gameStateFile);
    }

  }
}
