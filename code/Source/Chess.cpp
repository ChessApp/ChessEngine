#include "Chess.h"


namespace Chess
{

  Exception::Exception( string message, string function, string state )
    : message_(message),
      function_(function),
      state_(state)
  { }

  void writeToFile( const string& filePath, string content )
  {
    ofstream outFile(filePath);
    outFile << content;
    outFile.close();
  }

  const string readFromFile( const string& filePath )
  {
    ifstream readFile(filePath);
    std::string result((std::istreambuf_iterator<char>(readFile)),
               std::istreambuf_iterator<char>());
    result = result.append("\n");
    return result;
  }

}