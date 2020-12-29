#ifndef CHESS_H_
#define CHESS_H_

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>

#include "Tools/debugging/DebugConsole.h"

using namespace std;

namespace FilePaths
{
  static const char * gameStateFile("/tmp/GameState.xml");
  static const char * userInputFile("/tmp/UserInput.txt");
  static const char * userInputList("/chessengine/build/InputList.txt");
}

#endif /* CHESS_H_ */