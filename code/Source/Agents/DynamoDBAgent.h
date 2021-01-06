#ifndef CHESS_AGENTS_DYNAMODBAGENT_H_
#define CHESS_AGENTS_DYNAMODBAGENT_H_

#include "Chess.h"

#include <aws/core/Aws.h>
#include <aws/core/utils/Outcome.h> 
#include <aws/dynamodb/DynamoDBClient.h>
#include <aws/dynamodb/model/AttributeDefinition.h>
#include <aws/dynamodb/model/PutItemRequest.h>
#include <aws/dynamodb/model/GetItemRequest.h>


namespace Chess
{
  namespace Agents
  {

    class DynamoDBAgent
    {
    public:
      //-- types

      //-- construction
      DynamoDBAgent( string tableName, string region, string endpoint = "" );
      ~DynamoDBAgent();

      //-- static interface
      const Aws::Map<Aws::String, Aws::DynamoDB::Model::AttributeValue> getItem( string hashKey, string hashValue );
      void putItem( const vector<pair<string, string>>& items );


    protected:
      //-- protected methods

      //-- protected members
      Aws::SDKOptions options_;
      string tableName_;
      string endpoint_;
      string region_;
    };

  }
}

#endif /* CHESS_AGENTS_DYNAMODBAGENT_H_ */
