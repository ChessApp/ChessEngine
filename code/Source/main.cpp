#include <aws/lambda-runtime/runtime.h>
#include <plog/Init.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Formatters/TxtFormatter.h>

#include "Chess.h"
#include "GameProtocolDriver.h"


using namespace aws::lambda_runtime;


invocation_response my_handler(invocation_request const& request)
{
  Chess::FileSystem::writeToFile(Chess::FilePaths::userInputFile, request.payload);

  new Chess::GameProtocolDriver();

  return invocation_response::success(Chess::FileSystem::readFromFile(Chess::FilePaths::gameStateFile), "application/xml");
}


int main( int argc, char ** argv )
{
  // Initialize logging system
  static plog::ColorConsoleAppender<plog::TxtFormatter> colorConsoleAppender;
  plog::init(plog::info, &colorConsoleAppender);

  run_handler(my_handler);
  return 0;
}
