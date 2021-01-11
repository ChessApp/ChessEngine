#include <aws/lambda-runtime/runtime.h>
#include <plog/Init.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Formatters/TxtFormatter.h>

#include "Chess.h"
#include "GameProtocolDriver.h"
#include "Agents/DynamoDBAgent.h"


using namespace aws::lambda_runtime;

const string gameState = "GameState";
const string payloadFilePath = "/tmp/DefaultInitialState.xml";


bool copyFile(const char *SRC, const char* DEST)
{
  std::ifstream src(SRC, std::ios::binary);
  std::ofstream dest(DEST, std::ios::binary);
  dest << src.rdbuf();
  return src && dest;
}

string convertToString(string xmlFile) {
  ifstream f(xmlFile); //taking file as inputstream
  string str;
  if(f) {
     ostringstream ss;
     ss << f.rdbuf(); // reading data
     str = ss.str();
  }
  return str;
}

invocation_response my_handler(invocation_request const& request)
{
  Chess::writeToFile(Chess::FilePaths::userInputFile, request.payload);

  new Chess::GameProtocolDriver();

  return invocation_response::success(Chess::readFromFile(Chess::FilePaths::gameStateFile), "application/xml");
}


int main( int argc, char ** argv )
{
  // Initialize logging system
  static plog::ColorConsoleAppender<plog::TxtFormatter> colorConsoleAppender;
  plog::init(plog::verbose, &colorConsoleAppender);

  run_handler(my_handler);
  return 0;
}
