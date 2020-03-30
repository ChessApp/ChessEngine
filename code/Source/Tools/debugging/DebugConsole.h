#include <string>
#include <iostream>


// Uncomment to enable debug printouts
// #define DEBUG

#ifdef DEBUG

  #define DEBUG_CONSOLE_1ARG( arg1 ) \
  { \
    std::cout << "[***DEBUG CONSOLE***] " << arg1 << endl; \
  }

  #define DEBUG_CONSOLE_2ARG( arg1, arg2 ) \
  { \
    std::cout << "[***DEBUG CONSOLE***] " << arg1 << arg2 << endl; \
  }

  #define DEBUG_CONSOLE_PRINT_BOARD( interface ) \
  { \
    interface->printBoard(); \
  }

#else

  #define DEBUG_CONSOLE_1ARG( arg1 )
  #define DEBUG_CONSOLE_2ARG( arg1, arg2 )
  #define DEBUG_CONSOLE_PRINT_BOARD( interface )

#endif
