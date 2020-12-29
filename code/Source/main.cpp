#include <aws/lambda-runtime/runtime.h>
#include <boost/filesystem.hpp>

#include "Chess.h"
#include "GameProtocolDriver.h"

// Uncomment the line below to run unit tests
// #define RUN_UNIT_TESTS

using namespace aws::lambda_runtime;

const string gameState = "GameState";

invocation_response my_handler(invocation_request const& request)
{
  std::cout << "Current path is " << boost::filesystem::current_path() << '\n';
  {
    ofstream payloadFile;
    payloadFile.open("/var/task/payloadFile.json", fstream::out);
    cout << payloadFile.good() << endl;
    payloadFile << request.payload << "\n";
    payloadFile.close();
    ifstream in("/var/task/payloadFile.json");
    cout << in.good() << endl;
  }
  {
    ifstream payloadFile("/var/task/payloadFile.json");
    cout << "good: " << payloadFile.good() << endl;
    char payload[5];
    payloadFile.getline(payload, 5);
    if(!payloadFile) cout << ":(\n" << endl;
    payloadFile.close();
    std::cout << "payload: " << payload << endl;
  }
  std::cout << "request.payload: " << request.payload << std::endl;
  return invocation_response::success(gameState, "application/json");
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
