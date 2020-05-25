#include "State/CheckmateState.h"

#include "Tools/pugixml/pugixml.hpp"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr CheckmateState::execute( )
    {
      std::cout << "Checkmate!" << std::endl;

      updateGameState();

      interface_->printPinListDiagnostics();
      interface_->printBoard();
      return nextState_;
    }

    void CheckmateState::updateGameState( )
    {
      // Setup the xml document structure and load the state initialization file
      pugi::xml_document doc;
      pugi::xml_parse_result result = doc.load_file(FilePaths::gameStateFile);

      // Grab the root node
      pugi::xml_node root = doc.child("root");

      pugi::xml_node winnerNode  = root.child("Winner");
      winnerNode.attribute("status").set_value(1);
      string winner( 1, currentTurn_->getTurn() );
      winnerNode.attribute("color").set_value(winner.c_str());
      doc.save_file(FilePaths::gameStateFile);
    }

  }
}