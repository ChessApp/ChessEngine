import boto3
from pprint import pprint


def putitem(gameStateXml, dynamodb=None):
  if not dynamodb:
    dynamodb = boto3.resource('dynamodb', endpoint_url="http://localhost:8000")

  table = dynamodb.Table('GameStates')
  response = table.put_item(
    Item=
    {
      'gameId': "69",
      'whiteId': "1",
      'blackId': "2",
      'state': gameStateXml,
    }
  )
  return response

gameStateFile = open("scripts/inputs/putitem-payload.xml")
gameStateXml = gameStateFile.read()
gameStateFile.close()

result = putitem(gameStateXml)
print("Putitem succeeded:")
pprint(result, sort_dicts=False)