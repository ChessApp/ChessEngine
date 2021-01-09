#include "Chess.h"


namespace Chess
{

  void writeToFile( const char * filePath, string content )
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