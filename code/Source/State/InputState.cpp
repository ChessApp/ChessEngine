#include "State/InputState.h"

#include <stdio.h>

#include <chrono>
#include <thread>
#include <fstream>


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr InputState::execute( )
    {
      DEBUG_CONSOLE_1ARG("State: INPUT");
      
      updateGameState();

      interface_->printBoard();
      interface_->printGameConds();

      while( !freshInput() )
      {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }

      getInput();
      
      nextState_->setWhiteKing(whiteKing_);
      nextState_->setBlackKing(blackKing_);
      return nextState_;
    }

    bool InputState::freshInput()
    {
      ifstream in(userInputFile);

      if(in)
        return true;
      else
        return false;
    }

    void InputState::clearServerFresh( pugi::xml_node & flagsNode )
    {
      flagsNode.attribute("serverFresh").set_value(0);

      // Pretty hacky, but mark the move as invalid here, only
      // to be cleared if we get to the SwitchTurnState.
      flagsNode.attribute("invalidMove").set_value(1);
    }

    void InputState::getInput( )
    {
      ifstream in(userInputFile);

      if(!in)
        return;

      // Setup the xml document structure and load the state initialization file
      pugi::xml_document doc;
      pugi::xml_parse_result result = doc.load_file(gameStateFile);

      // Grab the root node
      pugi::xml_node root = doc.child("root");

      pugi::xml_node flagsNode = root.child("Flags");

      // Pretty hacky, but mark the move as invalid here, only
      // to be cleared if we get to the SwitchTurnState.
      flagsNode.attribute("invalidMove").set_value(1);
      doc.save_file(gameStateFile);

      char input[10];
      in.getline(input, 10);
      cout << "Input: " << input << endl;
      interface_->setInput(input);
      in.close();
      std::remove(userInputFile);
    }

    void InputState::updateGameState()
    {
      // Setup the xml document structure and load the state initialization file
      pugi::xml_document doc;
      pugi::xml_parse_result result = doc.load_file(gameStateFile);

      // Grab the root node
      pugi::xml_node root = doc.child("root");

      pugi::xml_node turnNode  = root.child("Turn");
      pugi::xml_node boardNode = root.child("Board");
      pugi::xml_node flagsNode = root.child("Flags");

      string turn( 1, currentTurn_->getTurn() );
      turnNode.attribute("color").set_value(turn.c_str());

      std::vector<PiecePtr> pieceList(64);
      for( int y = 0; y <= 7; y++ )
      {
        for( int x = 0; x <= 7; x++ )
        {
          pieceList.push_back( board_->getPiece(y, x) );
        }
      }

      // Iterate through all of the children of the root node
      for( pugi::xml_node_iterator s = boardNode.begin(); s != boardNode.end(); ++s )
      {
        PiecePtr piece = pieceList.back();
        string color( 1, piece->getColor() );
        s->attribute("row").set_value(piece->getRow());
        s->attribute("col").set_value(piece->getCol());
        s->attribute("type").set_value(piece->getType().c_str());
        s->attribute("color").set_value(color.c_str());
        pieceList.pop_back();
      }

      flagsNode.attribute("clientFresh").set_value(1);
      doc.save_file(gameStateFile);
    }

  }
}
