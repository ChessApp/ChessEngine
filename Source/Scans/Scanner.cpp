#include "Scanner.h"    

namespace Chess
{

  Scanner::Scanner ( Board * board )
    : board(board)
  {

  }
}

//   bool Scanner::rightRadar(Pieces & king)
//   {
//     int row_array[7];
//     int col_array[7];
//     int array_index = 0;
//     int i;

//     if (king->col == 8)
//     {
//       return false;
//     }
//     else
//     {
//       for (i = king->col + 1; i < 9; i++)
//       {
//         pcurrent_piece = board[king->row][i];
//         if (pcurrent_piece == pnullpiece)
//         {
//           row_array[array_index] = king->row;
//           col_array[array_index] = i;
//           ++array_index;
//         }
//         else
//         {
//           if (pcurrent_piece->color == king->opponent &&
//             pcurrent_piece->type == 'R')
//           {
//             row_array[array_index] = king->row;
//             col_array[array_index] = i;
//             ++array_index;

//             for (int n = 0; n < array_index; n++)
//             {
//               rightrow_blockcheck[n] = row_array[n];
//               rightcol_blockcheck[n] = col_array[n];
//               ++right_index;
//             }
//             return true;
//           }
//           else if (pcurrent_piece->color == king->color)
//           {
//             checkPinRight(king, i, king->row);
//             return false;
//           }
//           else
//           {
//             return false;
//           }
//           break;
//         }
//       }
//       if (i == 9)
//       {
//         return false;
//       }
//     }
//   }

//   bool Scanner::leftRadar(Pieces* king)
//   {
//     int row_array[7];
//     int col_array[7];
//     int array_index = 0;
//     int i;

//     if (king->col == 1)
//     {
//       return false;
//     }
//     else
//     {
//       for (i = king->col - 1; i > 0; i--)
//       {
//         pcurrent_piece = board[king->row][i];
//         if (pcurrent_piece == pnullpiece)
//         {
//           row_array[array_index] = king->row;
//           col_array[array_index] = i;
//           ++array_index;
//         }
//         else
//         {
//           if (pcurrent_piece->color == king->opponent &&
//             pcurrent_piece->type == 'R')
//           {
//             row_array[array_index] = king->row;
//             col_array[array_index] = i;
//             ++array_index;

//             for (int n = 0; n < array_index; n++)
//             {
//               leftrow_blockcheck[n] = row_array[n];
//               leftcol_blockcheck[n] = col_array[n];
//               ++left_index;
//             }
//             return true;
//           }
//           else if (pcurrent_piece->color == king->color)
//           {
//             checkPinLeft(king, i, king->row);
//             return false;
//           }
//           else
//           {
//             return false;
//           }
//           break;
//         }
//       }
//       if (i == 0)
//       {
//         return false;
//       }
//     }
//   }

//   bool Scanner::upRadar(Pieces* king)
//   {
//     int row_array[7];
//     int col_array[7];
//     int array_index = 0;
//     int j;

//     if (king->row == 1)
//     {
//       return false;
//     }
//     else
//     {
//       for (j = king->row - 1; j > 0; j--)
//       {
//         pcurrent_piece = board[j][king->col];
//         if (pcurrent_piece == pnullpiece)
//         {
//           row_array[array_index] = j;
//           col_array[array_index] = king->col;
//           ++array_index;
//         }
//         else
//         {
//           if (pcurrent_piece->color == king->opponent &&
//             pcurrent_piece->type == 'R')
//           {
//             row_array[array_index] = j;
//             col_array[array_index] = king->col;
//             ++array_index;

//             for (int n = 0; n < array_index; n++)
//             {
//               uprow_blockcheck[n] = row_array[n];
//               upcol_blockcheck[n] = col_array[n];
//               ++up_index;
//             }
//             return true;
//           }
//           else if (pcurrent_piece->color == king->color)
//           {
//             checkPinUp(king, king->col, j);
//             return false;
//           }
//           else
//           {
//             return false;
//           }
//           break;
//         }
//       }
//       if (j == 0)
//       {
//         return false;
//       }
//     }
//   }

//   bool Scanner::downRadar(Pieces* king)
//   {
//     int row_array[7];
//     int col_array[7];
//     int array_index = 0;
//     int j;

//     if (king->row == 8)
//     {
//       return false;
//     }
//     else
//     {
//       for (j = king->row + 1; j < 9; j++)
//       {
//         pcurrent_piece = board[j][king->col];
//         if (pcurrent_piece == pnullpiece)
//         {
//           row_array[array_index] = j;
//           col_array[array_index] = king->col;
//           ++array_index;
//         }
//         else
//         {
//           if (pcurrent_piece->color == king->opponent &&
//             pcurrent_piece->type == 'R')
//           {
//             row_array[array_index] = j;
//             col_array[array_index] = king->col;
//             ++array_index;

//             for (int n = 0; n < array_index; n++)
//             {
//               downrow_blockcheck[n] = row_array[n];
//               downcol_blockcheck[n] = col_array[n];
//               ++down_index;
//             }
//             return true;
//           }
//           else if (pcurrent_piece->color == king->color)
//           {
//             checkPinDown(king, king->col, j);
//             return false;
//           }
//           else
//           {
//             return false;
//           }
//           break;
//         }
//       }
//       if (j == 9)
//       {
//         return false;
//       }
//     }
//   }

//   bool Scanner::upRightRadar(Pieces* king)
//   {
//     int row_array[7];
//     int col_array[7];
//     int array_index = 0;
//     int i;
//     int j;

//     if (king->row == 1 || king->col == 8)
//     {
//       return false;
//     }
//     else
//     {
//       i = king->col + 1;
//       j = king->row - 1;
//       while (i < 9 && j > 0) //checks each square in path is empty
//       {
//         pcurrent_piece = board[j][i];
//         if (pcurrent_piece == pnullpiece)
//         {
//           row_array[array_index] = j;
//           col_array[array_index] = i;
//           ++array_index;
//           ++i;
//           --j;
//         }
//         else
//         {
//           if (pcurrent_piece->color == king->opponent &&
//             (pcurrent_piece->type == 'B' ||
//             (pcurrent_piece->type == 'P' && king->opponent == 'B' && i == king->col + 1)))
//           {
//             row_array[array_index] = j;
//             col_array[array_index] = i;
//             ++array_index;

//             for (int n = 0; n < array_index; n++)
//             {
//               uprightrow_blockcheck[n] = row_array[n];
//               uprightcol_blockcheck[n] = col_array[n];
//               ++upright_index;
//             }
//             return true;
//           }
//           else if (pcurrent_piece->color == king->color)
//           {
//             checkPinUpRight(king, i, j);
//             return false;
//           }
//           else
//           {
//             return false;
//           }
//           break;
//         }
//       }
//       if (i == 9 || j == 0)
//       {
//         return false;
//       }
//     }
//   }

//   bool Scanner::upLeftRadar(Pieces* king)
//   {
//     int row_array[7];
//     int col_array[7];
//     int array_index = 0;
//     int i;
//     int j;

//     if (king->row == 1 || king->col == 1)
//     {
//       return false;
//     }
//     else
//     {
//       i = king->col - 1;
//       j = king->row - 1;
//       while (i > 0 && j > 0) //checks each square in path is empty
//       {
//         pcurrent_piece = board[j][i];
//         if (pcurrent_piece == pnullpiece)
//         {
//           row_array[array_index] = j;
//           col_array[array_index] = i;
//           ++array_index;
//           --i;
//           --j;
//         }
//         else
//         {
//           if (pcurrent_piece->color == king->opponent &&
//             (pcurrent_piece->type == 'B' ||
//             (pcurrent_piece->type == 'P' && king->opponent == 'B' && i == king->col - 1)))
//           {
//             row_array[array_index] = j;
//             col_array[array_index] = i;
//             ++array_index;

//             for (int n = 0; n < array_index; n++)
//             {
//               upleftrow_blockcheck[n] = row_array[n];
//               upleftcol_blockcheck[n] = col_array[n];
//               ++upleft_index;
//             }
//             return true;
//           }
//           else if (pcurrent_piece->color == king->color)
//           {
//             checkPinUpLeft(king, i, j);
//             return false;
//           }
//           else
//           {
//             return false;
//           }
//           break;
//         }
//       }
//       if (i == 0 || j == 0)
//       {
//         return false;
//       }
//     }
//   }

//   bool Scanner::downRightRadar(Pieces* king)
//   {
//     int row_array[7];
//     int col_array[7];
//     int array_index = 0;
//     int i;
//     int j;

//     if (king->row == 8 || king->col == 8)
//     {
//       return false;
//     }
//     else
//     {
//       i = king->col + 1;
//       j = king->row + 1;
//       while (i < 9 && j < 9) //checks each square in path is empty
//       {
//         pcurrent_piece = board[j][i];
//         if (pcurrent_piece == pnullpiece)
//         {
//           row_array[array_index] = j;
//           col_array[array_index] = i;
//           ++array_index;
//           ++i;
//           ++j;
//         }
//         else
//         {
//           if (pcurrent_piece->color == king->opponent &&
//             (pcurrent_piece->type == 'B' ||
//             (pcurrent_piece->type == 'P' && king->opponent == 'W' && i == king->col + 1)))
//           {
//             row_array[array_index] = j;
//             col_array[array_index] = i;
//             ++array_index;

//             for (int n = 0; n < array_index; n++)
//             {
//               downrightrow_blockcheck[n] = row_array[n];
//               downrightcol_blockcheck[n] = col_array[n];
//               ++downright_index;
//             }
//             return true;
//           }
//           else if (pcurrent_piece->color == king->color)
//           {
//             checkPinDownRight(king, i, j);
//             return false;
//           }
//           else
//           {
//             return false;
//           }
//           break;
//         }
//       }
//       if (i == 9 || j == 9)
//       {
//         return false;
//       }
//     }
//   }

//   bool Scanner::downLeftRadar(Pieces* king)
//   {
//     int row_array[7];
//     int col_array[7];
//     int array_index = 0;
//     int i;
//     int j;

//     if (king->row == 8 || king->col == 1)
//     {
//       return false;
//     }
//     else
//     {
//       i = king->col - 1;
//       j = king->row + 1;
//       while (i > 0 && j < 9) //checks each square in path is empty
//       {
//         pcurrent_piece = board[j][i];
//         if (pcurrent_piece == pnullpiece)
//         {
//           row_array[array_index] = j;
//           col_array[array_index] = i;
//           ++array_index;
//           --i;
//           ++j;
//         }
//         else
//         {
//           if (pcurrent_piece->color == king->opponent &&
//             (pcurrent_piece->type == 'B' ||
//             (pcurrent_piece->type == 'P' && king->opponent == 'W' && i == king->col - 1)))
//           {
//             row_array[array_index] = j;
//             col_array[array_index] = i;
//             ++array_index;

//             for (int n = 0; n < array_index; n++)
//             {
//               downleftrow_blockcheck[n] = row_array[n];
//               downleftcol_blockcheck[n] = col_array[n];
//               ++downleft_index;
//             }
//             return true;
//           }
//           else if (pcurrent_piece->color == king->color)
//           {
//             checkPinDownLeft(king, i, j);
//             return false;
//           }
//           else
//           {
//             return false;
//           }
//           break;
//         }
//       }
//       if (i == 0 || j == 9)
//       {
//         return false;
//       }
//     }
//   }

// }
