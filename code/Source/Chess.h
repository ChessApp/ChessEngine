#ifndef CHESS_H_
#define CHESS_H_

#include <bits/stdc++.h>
#include <plog/Log.h>

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
    static const string gameStateFile("/tmp/GameState.xml");
    static const string userInputFile("/tmp/UserInput.txt");
    static const string userInputList("/chessengine/build/InputList.txt");
  }

  class Exception
  {
  public:
    Exception( string message, string function = "", string state = "" );

    const string getState()    { return state_; }
    const string getFunction() { return function_; }
    const string getMessage()  { return message_; }

    void setState( string state )       { state_ = state; }
    void setFunction( string function ) { function_ = function; }

  private:
    string state_;
    string function_;
    string message_;
  };

  namespace FileSystem
  {
    void writeToFile( const string& filePath, string content );
    const string readFromFile( const string& filePath );
  }

}

#endif /* CHESS_H_ */