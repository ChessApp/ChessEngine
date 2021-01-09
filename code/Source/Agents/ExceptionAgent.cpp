#include "Agents/ExceptionAgent.h"

namespace Chess
{
  namespace ExceptionAgent
  {

    void handle( Exception& exception, GameState& gameState )
    {
      cout << "---- ERROR ----" << endl
           << " State: "    << exception.getState() << endl
           << " Function: " << exception.getFunction() << endl
           << " Message: "  << exception.getMessage()  << endl;

      gameState.errorMessage = exception.getMessage();
    }

  }
}