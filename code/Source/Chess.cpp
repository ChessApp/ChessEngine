#include "Chess.h"


namespace Chess
{

  void writeToFile( const char * filePath, string content )
  {
    ofstream outFile(filePath);
    outFile << content;
    outFile.close();
  }

}