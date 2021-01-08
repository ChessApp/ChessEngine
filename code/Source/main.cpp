#include <aws/lambda-runtime/runtime.h>

#include <aws/core/Aws.h>
#include <aws/core/utils/Outcome.h> 
#include <aws/dynamodb/DynamoDBClient.h>
#include <aws/dynamodb/model/AttributeDefinition.h>
#include <aws/dynamodb/model/PutItemRequest.h>
#include <aws/dynamodb/model/DescribeTableRequest.h>
#include <iostream>

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

string convertToString(string xmlFile) {
  ifstream f(xmlFile); //taking file as inputstream
  string str;
  if(f) {
     ostringstream ss;
     ss << f.rdbuf(); // reading data
     str = ss.str();
  }
  cout << "str content: " << str << endl;
  return str;
}

invocation_response my_handler(invocation_request const& request)
{
  // copyFile("/var/task/config/GameState.xml", "/tmp/GameState.xml");
  // string xmlData = convertToString(FilePaths::gameStateFile);

  // std::ofstream out("/tmp/output.txt");
  // out << xmlData;
  // out.close();


  // Aws::SDKOptions options;
  // Aws::InitAPI(options);
  // {
  //   Aws::Client::ClientConfiguration clientConfig;
  //   clientConfig.region = "localhost";
  //   clientConfig.endpointOverride = "http://localhost:8000";
  //   Aws::DynamoDB::DynamoDBClient dynamoClient(clientConfig);

  //   Aws::DynamoDB::Model::PutItemRequest pir;
  //   pir.SetTableName("GameStates");

  //   Aws::DynamoDB::Model::AttributeValue av;
  //   av.SetS("69");
  //   pir.AddItem("id", av);

  //   Aws::DynamoDB::Model::AttributeValue val1;
  //   val1.SetS(xmlData);
  //   pir.AddItem("state", val1);

  //   const Aws::DynamoDB::Model::PutItemOutcome result = dynamoClient.PutItem(pir);
  //   if (!result.IsSuccess())
  //   {
  //       std::cout << result.GetError().GetMessage() << std::endl;
  //   }
  //   std::cout << "Done!" << std::endl;
  // }
  // Aws::ShutdownAPI(options);


  std::cout << "request.payload: " << request.payload << std::endl;
  ofstream state;
  state.open(FilePaths::userInputFile);
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
