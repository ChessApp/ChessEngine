#include "State/FinishState.h"

#include "Tools/pugixml/pugixml.hpp"


namespace Chess
{
  namespace State
  {

    void serializeGameStateFile( GameState& gameState )
    {
      // Setup the xml document structure and load the state initialization file
      pugi::xml_document doc;
      pugi::xml_parse_result result = doc.load_file(FilePaths::gameStateFile.c_str());

      // Grab the root node
      pugi::xml_node root = doc.child("root");
      pugi::xml_node boardNode = root.append_child("Board");
      for( auto piecePair : gameState.activePieces )
      {
        GameState::PiecePtr piece = piecePair.second;
        pugi::xml_node squareNode = boardNode.append_child("Square");
        pugi::xml_attribute typeAttr = squareNode.append_attribute("type");
        typeAttr.set_value(piece->getType().c_str());
        pugi::xml_attribute colorAttr = squareNode.append_attribute("color");
        colorAttr.set_value(piece->getColor().c_str());
        pugi::xml_attribute rowAttr = squareNode.append_attribute("row");
        rowAttr.set_value(piece->getRow());
        pugi::xml_attribute colAttr = squareNode.append_attribute("col");
        colAttr.set_value(piece->getCol());
        pugi::xml_attribute symbolAttr = squareNode.append_attribute("symbol");
        symbolAttr.set_value(piece->getName().c_str());
      }

      pugi::xml_node turnNode = root.child("Turn");
      turnNode.attribute("color").set_value(gameState.serializeAttacker().c_str());
      doc.save_file(FilePaths::gameStateFile.c_str());
    }

    BaseState::StatePtr FinishState::execute()
    {
      DEBUG_CONSOLE_1ARG("State: FINISH");
      serializeGameStateFile(gameState_);
      return nextState_;
    }

  }
}