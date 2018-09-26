// This source file houses all of the associated
// logic that composes the functions within the 
// Mastermind class, which is described in the 
// accompanying header file.


#include "Mastermind.h"

Mastermind::Mastermind(Interface &interface, Pieces* nullpiece, Pieces* wr1, Pieces* wr2, Pieces* wb1, Pieces* wb2, Pieces* wk1,
	Pieces* wp1, Pieces* wp2, Pieces* wp3, Pieces* wp4, Pieces* wp5, Pieces* wp6, Pieces* wp7, Pieces* wp8,
	Pieces* br1, Pieces* br2, Pieces* bb1, Pieces* bb2, Pieces* bk1,
	Pieces* bp1, Pieces* bp2, Pieces* bp3, Pieces* bp4, Pieces* bp5, Pieces* bp6, Pieces* bp7, Pieces* bp8)
	:interface(interface)
{
	psource_col = &(interface.source_col);
	psource_row = &(interface.source_row);
	pdest_col = &(interface.dest_col);
	pdest_row = &(interface.dest_row);

	pin_index = 0;
	up_index = 0;
	down_index = 0;
	right_index = 0;
	left_index = 0;
	upright_index = 0;
	upleft_index = 0;
	downright_index = 0;
	downleft_index = 0;

	turn = 'W';
	check_status = 'N';


	/*********************************************
	Point at Piece Objects
	********************************************/
	pnullpiece = nullpiece;
	pwr1 = wr1;
	pwr2 = wr2;
	pwb1 = wb1;
	pwb2 = wb2;
	pwk1 = wk1;
	pwp1 = wp1;
	pwp2 = wp2;
	pwp3 = wp3;
	pwp4 = wp4;
	pwp5 = wp5;
	pwp6 = wp6;
	pwp7 = wp7;
	pwp8 = wp8;
	pbr1 = br1;
	pbr2 = br2;
	pbb1 = bb1;
	pbb2 = bb2;
	pbk1 = bk1;
	pbp1 = bp1;
	pbp2 = bp2;
	pbp3 = bp3;
	pbp4 = bp4;
	pbp5 = bp5;
	pbp6 = bp6;
	pbp7 = bp7;
	pbp8 = bp8;

	board[1][1] = br1;
	board[1][2] = nullpiece;
	board[1][3] = bb1;
	board[1][4] = nullpiece;
	board[1][5] = bk1;
	board[1][6] = bb2;
	board[1][7] = nullpiece;
	board[1][8] = br2;
	board[2][1] = bp1;
	board[2][2] = bp2;
	board[2][3] = bp3;
	board[2][4] = bp4;
	board[2][5] = bp5;
	board[2][6] = bp6;
	board[2][7] = bp7;
	board[2][8] = bp8;

	board[8][1] = wr1;
	board[8][2] = nullpiece;
	board[8][3] = wb1;
	board[8][4] = nullpiece;
	board[8][5] = wk1;
	board[8][6] = wb2;
	board[8][7] = nullpiece;
	board[8][8] = wr2;
	board[7][1] = wp1;
	board[7][2] = wp2;
	board[7][3] = wp3;
	board[7][4] = wp4;
	board[7][5] = wp5;
	board[7][6] = wp6;
	board[7][7] = wp7;
	board[7][8] = wp8;

	//add middle of board pointers
	for (int x = 1; x<9; ++x)
	{
		for (int y = 3; y<7; ++y)
		{
			board[y][x] = nullpiece;
		}
	}
	for (int x = 0; x <= 9; ++x)
	{
		board[0][x] = nullpiece;
	}
	for (int x = 0; x <= 9; ++x)
	{
		board[9][x] = nullpiece;
	}
	for (int y = 0; y <= 9; ++y)
	{
		board[y][0] = nullpiece;
	}
	for (int y = 0; y <= 9; ++y)
	{
		board[y][9] = nullpiece;
	}
}

bool Mastermind::inputContent(void)
{
	if (
		(interface.user_input[0] == 'A' || interface.user_input[0] == 'B' || interface.user_input[0] == 'C' || interface.user_input[0] == 'D' ||
			interface.user_input[0] == 'E' || interface.user_input[0] == 'F' || interface.user_input[0] == 'G' || interface.user_input[0] == 'H')
		&&
		(interface.user_input[1] == '1' || interface.user_input[1] == '2' || interface.user_input[1] == '3' || interface.user_input[1] == '4' ||
			interface.user_input[1] == '5' || interface.user_input[1] == '6' || interface.user_input[1] == '7' || interface.user_input[1] == '8')
		&&
		interface.user_input[2] == ','
		&&
		(interface.user_input[3] == 'A' || interface.user_input[3] == 'B' || interface.user_input[3] == 'C' || interface.user_input[3] == 'D' ||
			interface.user_input[3] == 'E' || interface.user_input[3] == 'F' || interface.user_input[3] == 'G' || interface.user_input[3] == 'H')
		&&
		(interface.user_input[4] == '1' || interface.user_input[4] == '2' || interface.user_input[4] == '3' || interface.user_input[4] == '4' ||
			interface.user_input[4] == '5' || interface.user_input[4] == '6' || interface.user_input[4] == '7' || interface.user_input[4] == '8')
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Mastermind::inputSize(void)
{
	if (interface.user_input.size() == 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Mastermind::inputDiffSqr(void)
{
	if (interface.user_input[0] != interface.user_input[3] || interface.user_input[1] != interface.user_input[4])
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Mastermind::updateMoveSpecs(void)
{
	interface.updateMoveSpecs();
	psource_piece = board[*psource_row][*psource_col];
	pdest_piece = board[*pdest_row][*pdest_col];
}

bool Mastermind::inputSqrAvailable(void)
{
	if (pdest_piece->color != psource_piece->color)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Mastermind::inputPieceOwner(void)
{
	if (turn == psource_piece->color)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Mastermind::inputValidityChecks(void)
{
	if (inputContent() &&
		inputSize() &&
		inputDiffSqr() &&
		inputSqrAvailable() &&
		inputPieceOwner())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Pieces::moveLeftValidity(void)
{
  if (*pdest_col - pcurrent_piece->col == -1)
  {
    return true;
  }
  else
  {
    int i = pcurrent_piece->col - 1;
    while (*pdest_col - i < 0) //checks each square on path is empty
    {
      if (board[*pdest_row][i] == pnullpiece)
      {
        if (*pdest_col - i == -1)
        {
          return true;
        }
        --i;
      }
      else
      {
        return false;
        break;
      }
    }
  }
}

bool Pieces::moveRightValidity(void)
{
  if (*pdest_col - pcurrent_piece->col == 1)
  {
    return true;
  }
  else
  {
    int i = pcurrent_piece->col + 1;
    while (*pdest_col - i > 0) //checks each square on path is empty
    {
      if (board[*pdest_row][i] == pnullpiece)
      {
        if (*pdest_col - i == 1)
        {
          return true;
        }
        ++i;
      }
      else
      {
        return false;
        break;
      }
    }
  }
}

bool Pieces::moveUpValidity(void)
{
  if (*pdest_row - pcurrent_piece->row == -1)
  {
    return true;
  }
  else
  {
    int j = pcurrent_piece->row - 1;
    while (*pdest_row - j < 0) //checks each square on path is empty
    {
      if (board[j][*pdest_col] == pnullpiece)
      {
        if (*pdest_row - j == -1)
        {
          return true;
        }
        --j;
      }
      else
      {
        return false;
        break;
      }
    }
  }
}

bool Pieces::moveDownValidity(void)
{
  if (*pdest_row - pcurrent_piece->row == 1)
  {
    return true;
  }
  else
  {
    int j = pcurrent_piece->row + 1;
    while (*pdest_col - j > 0) //checks each square on path is empty
    {
      if (board[j][*pdest_col] == pnullpiece)
      {
        if (*pdest_row - j == 1)
        {
          return true;
        }
        ++j;
      }
      else
      {
        return false;
        break;
      }
    }
  }
}

bool Pieces::moveUpLeftValidity(void)
{
  if (*pdest_col - pcurrent_piece->col == -1)
  {
    return true;
  }
  else
  {
    int i = pcurrent_piece->col - 1;
    int j = pcurrent_piece->row - 1;
    while (*pdest_col - i < 0) //checks each square in path is empty
    {
      if (board[j][i] == pnullpiece)
      {
        if (*pdest_col - i == -1)
        {
          return true;
        }
        --i;
        --j;
      }
      else
      {
        return false;
        break;
      }
    }
  }
}

bool Pieces::moveUpRightValidity(void)
{
  if (*pdest_col - pcurrent_piece->col == 1)
  {
    return true;
  }
  else
  {
    int i = pcurrent_piece->col + 1;
    int j = pcurrent_piece->row - 1;
    while (*pdest_col - i > 0) //checks each square in path is empty
    {
      if (board[j][i] == pnullpiece)
      {
        if (*pdest_col - i == 1)
        {
          return true;
        }
        ++i;
        --j;
      }
      else
      {
        return false;
        break;
      }
    }
  }
}

bool Pieces::moveDownLeftValidity(void)
{
  if (*pdest_col - pcurrent_piece->col == -1)
  {
    return true;
  }
  else
  {
    int i = pcurrent_piece->col - 1;
    int j = pcurrent_piece->row + 1;
    while (*pdest_col - i < 0) //checks each square in path is empty
    {
      if (board[j][i] == pnullpiece)
      {
        if (*pdest_col - i == -1)
        {
          return true;
        }
        --i;
        ++j;
      }
      else
      {
        return false;
        break;
      }
    }
  }
}

bool Pieces::moveDownRightValidity(void)
{
  if (*pdest_col - pcurrent_piece->col == 1)
  {
    return true;
  }
  else
  {
    int i = pcurrent_piece->col + 1;
    int j = pcurrent_piece->row + 1;
    while (*pdest_col - i > 0) //checks each square in path is empty
    {
      if (board[j][i] == pnullpiece)
      {
        if (*pdest_col - i == 1)
        {
          return true;
        }
        ++i;
        ++j;
      }
      else
      {
        return false;
        break;
      }
    }
  }
}

bool Mastermind::rRunChecks(void)
{
	if (rValidPath())
	{
		if (*pdest_col < pcurrent_piece->col && *pdest_row == pcurrent_piece->row)
		{
			return moveLeftValidity();
		}
		if (*pdest_col > pcurrent_piece->col && *pdest_row == pcurrent_piece->row)
		{
			return moveRightValidity();
		}
		if (*pdest_row < pcurrent_piece->row && *pdest_col == pcurrent_piece->col)
		{
			return moveUpValidity();
		}
		if (*pdest_row > pcurrent_piece->row && *pdest_col == pcurrent_piece->col)
		{
			return moveDownValidity();
		}
	}
	else
	{
		return false;
	}
}

bool Mastermind::bRunChecks(void)
{
	if (bValidPath())
	{
		if (*pdest_col - pcurrent_piece->col < 0 && *pdest_row - pcurrent_piece->row < 0)
		{
			return moveUpLeftValidity();
		}
		if (*pdest_col - pcurrent_piece->col > 0 && *pdest_row - pcurrent_piece->row < 0)
		{
			return moveUpRightValidity();
		}
		if (*pdest_col - pcurrent_piece->col < 0 && *pdest_row - pcurrent_piece->row > 0)
		{
			return moveDownLeftValidity();
		}
		if (*pdest_col - pcurrent_piece->col > 0 && *pdest_row - pcurrent_piece->row > 0)
		{
			return moveDownRightValidity();
		}
	}
	else
	{
		return false;
	}
}

bool Mastermind::bValidPath(void)
{
	if (abs(*pdest_col - pcurrent_piece->col) == abs(*pdest_row - pcurrent_piece->row))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Mastermind::rValidPath(void)
{
	if (*pdest_col - pcurrent_piece->col == 0 || *pdest_row - pcurrent_piece->row == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Mastermind::kMoveValidity(void)
{
	if (abs(*pdest_col - pcurrent_piece->col) <= 1 &&
		abs(*pdest_row - pcurrent_piece->row) <= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Mastermind::pMoveWhiteValidity(void)
{
	if (*pdest_col == *psource_col && *pdest_row == *psource_row - 2 && *psource_row == 7
		&& pdest_piece == pnullpiece && board[*psource_row - 1][*psource_col] == pnullpiece)
	{
		return true;
	}
	//move forward one square if that square is empty.
	else if (*pdest_col == *psource_col && *pdest_row == *psource_row - 1 && pdest_piece == pnullpiece)
	{
		return true;
	}
	//move diagonally as long as there is an opposing piece to capture
	else if ((*pdest_col == *psource_col + 1 || *pdest_col == *psource_col - 1) &&
		*pdest_row == *psource_row - 1 && pdest_piece->color == 'B')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Mastermind::pMoveBlackValidity(void)
{
	if (*pdest_col == *psource_col && *pdest_row == *psource_row + 2 && *psource_row == 2
		&& pdest_piece == pnullpiece && board[*psource_row + 1][*psource_col] == pnullpiece)
	{
		return true;
	}
	//move forward one square if that square is empty.
	else if (*pdest_col == *psource_col && *pdest_row == *psource_row + 1 && pdest_piece == pnullpiece)
	{
		return true;
	}
	//move diagonally as long as there is an opposing piece to capture
	else if ((*pdest_col == *psource_col + 1 || *pdest_col == *psource_col - 1) &&
		*pdest_row == *psource_row + 1 && pdest_piece->color == 'W')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Mastermind::checkPinRight(Pieces* king, int i, int row)
{
	Pieces* potential_pin = board[row][i];

	for (i + 1; i <= 8; i++)
	{
		pcurrent_piece = board[row][i];
		if (addToPinList(king, 'R', potential_pin))
		{
			break;
		}
	}
}

void Mastermind::checkPinLeft(Pieces* king, int i, int row)
{
	Pieces* potential_pin = board[row][i];

	for (i - 1; i >= 1; i--)
	{
		pcurrent_piece = board[row][i];
		if (addToPinList(king, 'R', potential_pin))
		{
			break;
		}
	}
}

void Mastermind::checkPinUp(Pieces* king, int col, int j)
{
	Pieces* potential_pin = board[j][col];

	for (j - 1; j >= 1; j--)
	{
		pcurrent_piece = board[j][col];
		if (addToPinList(king, 'R', potential_pin))
		{
			break;
		}
	}
}

void Mastermind::checkPinDown(Pieces* king, int col, int j)
{
	Pieces* potential_pin = board[j][col];

	for (j + 1; j <= 8; j++)
	{
		pcurrent_piece = board[j][col];
		if (addToPinList(king, 'R', potential_pin))
		{
			break;
		}
	}
}

void Mastermind::checkPinUpRight(Pieces* king, int i, int j)
{
	Pieces* potential_pin = board[j][i];

	while (i < 9 && j > 0)
	{
		++i;
		--j;
		pcurrent_piece = board[j][i];
		if (addToPinList(king, 'B', potential_pin))
		{
			break;
		}
	}
}

void Mastermind::checkPinUpLeft(Pieces* king, int i, int j)
{
	Pieces* potential_pin = board[j][i];

	while (i > 0 && j > 0)
	{
		--i;
		--j;
		pcurrent_piece = board[j][i];
		if (addToPinList(king, 'B', potential_pin))
		{
			break;
		}
	}
}

void Mastermind::checkPinDownRight(Pieces* king, int i, int j)
{
	Pieces* potential_pin = board[j][i];

	while (i < 9 && j < 9)
	{
		++i;
		++j;
		pcurrent_piece = board[j][i];
		if (addToPinList(king, 'B', potential_pin))
		{
			break;
		}
	}
}

void Mastermind::checkPinDownLeft(Pieces* king, int i, int j)
{
	Pieces* potential_pin = board[j][i];

	while (i > 0 && j < 9)
	{
		--i;
		++j;
		pcurrent_piece = board[j][i];
		if (addToPinList(king, 'B', potential_pin))
		{
			break;
		}
	}
}

bool Mastermind::addToPinList(Pieces* king, char attacker, Pieces* potential_pin)
{
	if (pcurrent_piece == pnullpiece)
	{
		return false;
	}
	else
	{
		if (pcurrent_piece->color == king->opponent &&
			pcurrent_piece->type == attacker)
		{
			potential_pin->pinned = true;
		}
		else
		{
		}
		return true;
	}
}

bool Mastermind::runRadar(Pieces* king)
{
	in_check = 0;

	if (upRadar(king))
	{
		++in_check;
	}
	if (downRadar(king))
	{
		++in_check;
	}
	if (rightRadar(king))
	{
		++in_check;
	}
	if (leftRadar(king))
	{
		++in_check;
	}
	if (upRightRadar(king))
	{
		++in_check;
	}
	if (upLeftRadar(king))
	{
		++in_check;
	}
	if (downRightRadar(king))
	{
		++in_check;
	}
	if (downLeftRadar(king))
	{
		++in_check;
	}

	if (in_check)
	{
		king->in_check = true;
		return true;
	}
	else
	{
		king->in_check = false;
		return false;
	}
}

bool Mastermind::escapeRoutes(Pieces* king)
{
	bool escapable = false;
	int original_row = king->row;
	int original_col = king->col;
	Pieces* hypothetical_king_loc;
	for (int y = original_row - 1; y <= original_row + 1; y++)
	{
		for (int x = original_col - 1; x <= original_col + 1; x++)
		{
			if ((x >= 1 && y >= 1) && (x <= 8 && y <= 8))
			{
				hypothetical_king_loc = board[y][x];
				if (hypothetical_king_loc->color != king->color)
				{
					board[original_row][original_col] = pnullpiece;
					king->row = y;
					king->col = x;
					board[y][x] = king;

					if (!runRadar(king))
					{
						escapable = true;
					}
					king->in_check = true;
					board[y][x] = hypothetical_king_loc;
					king->row = original_row;
					king->col = original_col;
					board[original_row][original_col] = king;
					if (escapable)
					{
						break;
					}
				}

			}
		}
		if (escapable)
		{
			break;
		}
	}

	if (escapable)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void Mastermind::pointToBlockableSqrs(void)
{
	if (up_index)
	{
		for (int n = up_index - 1; n >= 0; n--)
		{
			pcol_array[n] = &(upcol_blockcheck[n]);
			prow_array[n] = &(uprow_blockcheck[n]);
		}
		pindex = &up_index;
	}
	if (down_index)
	{
		for (int n = down_index - 1; n >= 0; n--)
		{
			pcol_array[n] = &(downcol_blockcheck[n]);
			prow_array[n] = &(downrow_blockcheck[n]);
		}
		pindex = &down_index;
	}
	if (right_index)
	{
		for (int n = right_index - 1; n >= 0; n--)
		{
			pcol_array[n] = &(rightcol_blockcheck[n]);
			prow_array[n] = &(rightrow_blockcheck[n]);
		}
		pindex = &right_index;
	}
	if (left_index)
	{
		for (int n = left_index - 1; n >= 0; n--)
		{
			pcol_array[n] = &(leftcol_blockcheck[n]);
			prow_array[n] = &(leftrow_blockcheck[n]);
		}
		pindex = &left_index;
	}
	if (upright_index)
	{
		for (int n = upright_index - 1; n >= 0; n--)
		{
			pcol_array[n] = &(uprightcol_blockcheck[n]);
			prow_array[n] = &(uprightrow_blockcheck[n]);
		}
		pindex = &upright_index;
	}
	if (upleft_index)
	{
		for (int n = upleft_index - 1; n >= 0; n--)
		{
			pcol_array[n] = &(upleftcol_blockcheck[n]);
			prow_array[n] = &(upleftrow_blockcheck[n]);
		}
		pindex = &upleft_index;
	}
	if (downright_index)
	{
		for (int n = downright_index - 1; n >= 0; n--)
		{
			pcol_array[n] = &(downrightcol_blockcheck[n]);
			prow_array[n] = &(downrightrow_blockcheck[n]);
		}
		pindex = &downright_index;
	}
	if (downleft_index)
	{
		for (int n = downleft_index - 1; n >= 0; n--)
		{
			pcol_array[n] = &(downleftcol_blockcheck[n]);
			prow_array[n] = &(downleftrow_blockcheck[n]);
		}
		pindex = &downleft_index;
	}
}

bool Mastermind::checkBlock(void)
{
	int* poriginal_dest_col = pdest_col;
	int* poriginal_dest_row = pdest_row;
	bool blockable = false;

	if (!(pcurrent_piece->captured) && !(pcurrent_piece->pinned))
	{
		if (*pindex)
		{
			for (int n = 0; n < *pindex; n++)
			{
				pdest_col = pcol_array[n];
				pdest_row = prow_array[n];

				if (pcurrent_piece->type == 'R' && rRunChecks())
				{
					*pindex = 0;
					blockable = true;
					break;
				}
				if (pcurrent_piece->type == 'B' && bRunChecks())
				{
					*pindex = 0;
					blockable = true;
					break;
				}
				if (pcurrent_piece->type == 'P' && pcurrent_piece->color == 'B' && pMoveBlackValidity())
				{
					*pindex = 0;
					blockable = true;
					break;
				}
				if (pcurrent_piece->type == 'P' && pcurrent_piece->color == 'W' && pMoveWhiteValidity())
				{
					*pindex = 0;
					blockable = true;
					break;
				}
			}
		}
	}
	pdest_col = poriginal_dest_col;
	pdest_row = poriginal_dest_row;

	if (blockable)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Mastermind::runBlockChecks(void)
{
	bool break_function = false;
	pointToBlockableSqrs();

	for (int x = 1; x <= 8; x++)
	{
		for (int y = 1; y <= 8; y++)
		{
			pcurrent_piece = board[y][x];

			if (pcurrent_piece->color == check_status &&
				pcurrent_piece->type != 'K')
			{
				if (checkBlock())
				{
					break_function = true;
					break;
				}
			}

		}
		if (break_function)
		{
			break;
		}
	}
	if (break_function)
	{
		return true;
	}
	else
	{
		return false;
	}
	*pindex = 0;
}

void Mastermind::movePiece(void)
{
	prev_check_status = check_status;
	psource_piece->prev_col = psource_piece->col;
	psource_piece->prev_row = psource_piece->row;
	psource_piece->col = *pdest_col;
	psource_piece->row = *pdest_row;
	board[*pdest_row][*pdest_col] = psource_piece;
	board[*psource_row][*psource_col] = pnullpiece;
}

void Mastermind::returnPiece(void)
{
	check_status = prev_check_status;
	board[*psource_row][*psource_col] = psource_piece;
	board[*pdest_row][*pdest_col] = pdest_piece;
	psource_piece->col = psource_piece->prev_col;
	psource_piece->row = psource_piece->prev_row;
}

void Mastermind::updatePinStatus(void)
{
	pwr1->pinned = false;
	pwr2->pinned = false;
	pwb1->pinned = false;
	pwb2->pinned = false;
	pwp1->pinned = false;
	pwp2->pinned = false;
	pwp3->pinned = false;
	pwp4->pinned = false;
	pwp5->pinned = false;
	pwp6->pinned = false;
	pwp7->pinned = false;
	pwp8->pinned = false;

	pbr1->pinned = false;
	pbr2->pinned = false;
	pbb1->pinned = false;
	pbb2->pinned = false;
	pbp1->pinned = false;
	pbp2->pinned = false;
	pbp3->pinned = false;
	pbp4->pinned = false;
	pbp5->pinned = false;
	pbp6->pinned = false;
	pbp7->pinned = false;
	pbp8->pinned = false;
}

void Mastermind::switchTurn(void)
{
	if (turn == 'W')
	{
		turn = 'B';
		interface.turn = turn;
	}
	else
	{
		turn = 'W';
		interface.turn = turn;
	}
}

void Mastermind::updateInterfaceBoard(void)
{
	Pieces* current_piece;
	for (int x = 1; x <= 8; x++)
	{
		for (int y = 1; y <= 8; y++)
		{
			current_piece = board[x][y];
			interface.printboard[x][y] = current_piece->name;
		}
	}
}

void Mastermind::updateGameData(void)
{
	if (pdest_piece != pnullpiece)
	{
		pdest_piece->captured = true;
	}
	updatePinStatus();
	interface.check_status = check_status;
	switchTurn();
	updateInterfaceBoard();
}

void Mastermind::printInterface(void)
{
	interface.printBoard();
	interface.printGameConds();
	interface.getInput();
}

bool Mastermind::runChecks(void)
{
	if (pcurrent_piece->type == 'R')
	{
		if (rRunChecks())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (pcurrent_piece->type == 'B')
	{
		if (bRunChecks())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (pcurrent_piece->name == "WP ")
	{
		if (pMoveWhiteValidity())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (pcurrent_piece->name == "BP ")
	{
		if (pMoveBlackValidity())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (pcurrent_piece->type == 'K')
	{
		if (kMoveValidity())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}









