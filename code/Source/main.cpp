#include <aws/lambda-runtime/runtime.h>

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
  ofstream state(FilePaths::userInputFile);
  state << request.payload;
  state.close();

  new Chess::GameProtocolDriver();

  ifstream payloadFile("/tmp/output.txt");
  std::string result((std::istreambuf_iterator<char>(payloadFile)),
               std::istreambuf_iterator<char>());
  result = result.append("\n");
  cout << "result: " << result << endl;
  return invocation_response::success(result, "application/xml");
}


int main( int argc, char ** argv )
{
  run_handler(my_handler);
  return 0;
}
