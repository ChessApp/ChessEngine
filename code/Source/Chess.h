#ifndef CHESS_H_
#define CHESS_H_

#include <vector>
#include <memory>
#include <string>
#include <iostream>

#include "Tools/debugging/DebugConsole.h"

using namespace std;

namespace FilePaths
{
  static const char * gameStateFile("/home/chess/dev/ChessGame/code/Source/UI/www/GameState.xml");
  static const char * userInputFile("/home/chess/dev/ChessGame/code/Source/UI/www/UserInput.txt");
  static const char * userInputList("/home/chess/dev/ChessGame/build/InputList.txt");
}

#endif /* CHESS_H_ */