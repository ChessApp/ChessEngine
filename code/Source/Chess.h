#ifndef CHESS_H_
#define CHESS_H_

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

#include "Tools/debugging/DebugConsole.h"

using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::string;
using std::vector;
using std::pair;
using std::shared_ptr;
using std::ostringstream;

namespace Chess
{
  namespace FilePaths
  {
    static const char * gameStateFile("/tmp/GameState.xml");
    static const char * userInputFile("/tmp/UserInput.txt");
    static const char * userInputList("/chessengine/build/InputList.txt");
  }

  void writeToFile( const string& filePath, string content );
  const string readFromFile( const string& filePath );
}

#endif /* CHESS_H_ */