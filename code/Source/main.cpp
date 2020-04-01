// This is the main file.
// It uses the other support files to actually
// execute the chess game.
#include "Chess.h"
#include "GameProtocolDriver.h"

// Uncomment the line below to run unit tests
// #define RUN_UNIT_TESTS


int main( int argc, char ** argv )
{
  #ifdef RUN_UNIT_TESTS
  ::testing::InitGoogleMock(&argc, argv);
  RUN_ALL_TESTS ( ) ;
  #endif /* RUN_UNIT_TESTS */

  cout << endl;
  cout << "Firin' up the ol' war game" << endl;
  cout << "Courtesy of Booty and Sons" << endl << endl;

  // new Chess::GameProtocolDriver();
  // for( int it = 0; it < 3; it++) {
  int v1, v2;
  cin >> v1;
  cin >> v2;
  cout << "v1: " << v1 << " v2: " << v2 << endl;
  return 0;
}
