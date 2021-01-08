#include "Agents/DynamoDBAgent.h"

#include <memory>
#include <exception>


namespace Chess
{
  namespace Agents
  {

    DynamoDBAgent::DynamoDBAgent( string tableName, string region, string endpoint )
      : tableName_(tableName),
        region_(region),
        endpoint_(endpoint)
    {
      Aws::InitAPI(options_);
    }

    DynamoDBAgent::~DynamoDBAgent()
    {
      Aws::ShutdownAPI(options_);
    }

    const Aws::Map<Aws::String, Aws::DynamoDB::Model::AttributeValue> DynamoDBAgent::getItem( string hashKey, string hashValue )
    {
      Aws::Client::ClientConfiguration clientConfig;
      clientConfig.region = region_;
      clientConfig.endpointOverride = endpoint_;
      Aws::DynamoDB::DynamoDBClient dynamoClient(clientConfig);

      Aws::DynamoDB::Model::GetItemRequest req;
      Aws::DynamoDB::Model::AttributeValue attr;
      attr.SetS(hashValue);
      req.AddKey(hashKey, attr);
      req.SetTableName(tableName_);

      // Retrieve the item's fields and values
      const Aws::DynamoDB::Model::GetItemOutcome& result = dynamoClient.GetItem(req);
      if( result.IsSuccess() )
      {
        // Reference the retrieved fields/values
        const Aws::Map<Aws::String, Aws::DynamoDB::Model::AttributeValue>& item = result.GetResult().GetItem();
        return item;
      }
      else
      {
        std::cout << result.GetError().GetMessage() << std::endl;
        throw result.GetError().GetMessage();
      }
    }

    void DynamoDBAgent::putItem( const vector<pair<string, string>>& items )
    {
      Aws::Client::ClientConfiguration clientConfig;
      clientConfig.region = region_;
      clientConfig.endpointOverride = endpoint_;
      Aws::DynamoDB::DynamoDBClient dynamoClient(clientConfig);

      Aws::DynamoDB::Model::PutItemRequest req;
      req.SetTableName(tableName_);

      for( auto item : items )
      {
        auto hashKey = item.first;
        auto hashValue = item.second;
        Aws::DynamoDB::Model::AttributeValue attr;
        attr.SetS(hashValue);
        req.AddItem(hashKey, attr);
      }

      const Aws::DynamoDB::Model::PutItemOutcome result = dynamoClient.PutItem(req);
      if( !result.IsSuccess() )
      {
        throw;
      }
    }

  }
}