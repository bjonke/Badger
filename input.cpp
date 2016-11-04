#include <iostream>
#include <cstdio>
using namespace std;
#include <windows.h>
#include "Input.h"

void CInput::KeyPress()
{
	if(KEY_DOWN(VK_ESCAPE))
	{
		PostQuitMessage(0);
	}
	//--------------------------------------------
	//	Movement keys for Character 1
	//--------------------------------------------
	
	if(KEY_DOWN(VK_UP) && Character.y > 0)
	{
		Character.y -= Character.Velocity;
	}

	if(KEY_DOWN(VK_DOWN) && Character.y < 448)
	{
		Character.y += Character.Velocity;
	}

	if(KEY_DOWN(VK_RIGHT) && Character.x < 576)
	{
		Character.x += Character.Velocity;
	}

	if(KEY_DOWN(VK_LEFT) && Character.x > 0)
	{
		Character.x -= Character.Velocity;
	}

	//--------------------------------------------
	//	Movement keys for Character 2
	//--------------------------------------------
	if(KEY_DOWN('W') && Character2.y > 0)
	{
		Character2.y -= Character2.Velocity;
	}

	if(KEY_DOWN('S') && Character2.y < 448)
	{
		Character2.y += Character2.Velocity;
	}

	if(KEY_DOWN('D') && Character2.x < 576)
	{
		Character2.x += Character2.Velocity;
	}

	if(KEY_DOWN('A') && Character2.x > 0)
	{
		Character2.x -= Character2.Velocity;
	}
		
	///////////////////////////////////////////


}

void CInput::SpreadAcorns()
{
	for(Col = 0; Col < FieldX; Col++)
	{
		for(Row = 0; Row < FieldY; Row++)
		{
			AcornField[Row][Col] = rand() % 4;
		}
	}
}

bool CInput::CheckForAcorns()
{
	for(Col = 0; Col < FieldX; Col++)
	{
		for(Row = 0; Row < FieldY; Row++)
		{
			if(AcornField[Row][Col] == 1)
			{
				return true;
			}
		}
	}
	return false;
}

bool CInput::Collecting()
{
	// Player 1 stuff
	int xid = Character.x/32;
	int yid = Character.y/32;
	if(!(xid > FieldSize -1) && !(yid > FieldSize -1))
	{
		if(AcornField[xid][yid] == 1)
		{
			Character.Score += 100;
			Character.Acorns++;
			AcornField[xid][yid] = 0;
			Character.BadAcorn = false;
		}
		else if( AcornField[xid][yid] == 3)
		{
			AcornField[xid][yid] = 0;
			Character.BadAcorn = true;
		}
	}
	// Player 2 stuff
	xid = Character2.x/32;
	yid = Character2.y/32;

	if(!(xid > FieldSize -1) && !(yid > FieldSize -1))
	{
		if(AcornField[xid][yid] == 1)
		{
			Character2.Score += 100;
			Character2.Acorns++;
			AcornField[xid][yid] = 0;
		}
		else if( AcornField[xid][yid] == 3)
		{
			AcornField[xid][yid] = 0;
		}
	}
	return true;
}

bool CInput::Sick()
{
	// Check if player 1 is sick
	if(Character.BadAcorn)
	{
		Character.Velocity = 1;
	}
	else
		Character.Velocity = 2;

	if(Character2.BadAcorn)
	{
		Character2.Velocity = 1;
	}
	else
		Character2.Velocity = 2;

	return true;
}

int CInput::GameFinished()
{
	if(Character.Acorns > Character2.Acorns)
	{
		return 1;
	}
	else
	{
		return 2;
	}

	return 0;
}

int CInput::Acorns()
{
	return Character.Acorns;
}

int CInput::Acorns2()
{
	return Character2.Acorns;
}

int CInput::Score()
{
	return Character.Score;
}

int CInput::Score2()
{
	return Character2.Score;
}

int CInput::Xloc()
{
	return Character.x;
}

int CInput::Yloc()
{
	return Character.y;
}

int CInput::Xloc2()
{
	return Character2.x;
}

int CInput::Yloc2()
{
	return Character2.y;
}

int CInput::ShowSplash()
{
	return Splash;
}

void CInput::Reset()
{
	Character.BadAcorn = false;
	Character.Velocity = 1;
	Character.Acorns = 0;
	Character.x = 576;
	Character.y = 0;
	Character.Score = 0;

	Character2.BadAcorn = false;
	Character2.Velocity = 1;
	Character2.Acorns = 0;
	Character2.x = 576;
	Character2.y = 448;
	Character2.Score = 0;

	Col = 0;
	Row = 0;

	SpreadAcorns();
	
	Splash = 0;
}

CInput::CInput(int x, int y) : FieldX(x), FieldY(y)
{
	Character.BadAcorn = false;
	Character.Velocity = 1;
	Character.Acorns = 0;
	Character.x = 576;
	Character.y = 0;
	Character.Score = 0;

	Character2.BadAcorn = false;
	Character2.Velocity = 1;
	Character2.Acorns = 0;
	Character2.x = 576;
	Character2.y = 448;
	Character2.Score = 0;

	Character.hIcon = 0;
	Character2.hIcon = 0;

	Col = 0;
	Row = 0;

	SpreadAcorns();
	
	Splash = 0;
}
