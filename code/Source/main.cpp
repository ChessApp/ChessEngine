#include <aws/lambda-runtime/runtime.h>
#include <bits/stdc++.h>

#include "Chess.h"
#include "GameProtocolDriver.h"

// Uncomment the line below to run unit tests
// #define RUN_UNIT_TESTS

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

invocation_response my_handler(invocation_request const& request)
{
  std::cout << "request.payload: " << request.payload << std::endl;
  copyFile("/var/task/config/DefaultInitialState.xml", "/tmp/DefaultInitialState.xml");
  ifstream payloadFile(payloadFilePath);
  std::string result((std::istreambuf_iterator<char>(payloadFile)),
               std::istreambuf_iterator<char>());
  result = result.append("\n");
  cout << "result: " << result << endl;
  return invocation_response::success(result, "application/xml");
}


int main( int argc, char ** argv )
{
  // #ifdef RUN_UNIT_TESTS
  // ::testing::InitGoogleMock(&argc, argv);
  // RUN_ALL_TESTS ( ) ;
  // #endif /* RUN_UNIT_TESTS */

  // cout << endl;
  // cout << "Firin' up the ol' war game" << endl;
  // cout << "Courtesy of Booty and Sons" << endl << endl;

  // if( argc == 2 )
  //   new Chess::GameProtocolDriver(argv[1]);
  // else
  //   new Chess::GameProtocolDriver();
  run_handler(my_handler);
  return 0;
}
