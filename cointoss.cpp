#include <iostream>
#include <ctime>
using namespace std;
#include <windows.h>

#include "cointoss.h"

bool CCoinToss::TossCoin()
{
	if(rand()%2 == 1)
		HeadsOrTail = true;
	else
		HeadsOrTail = false;

	return HeadsOrTail;
}

CCoinToss::CCoinToss()
{
	srand(time(0));
	HeadsOrTail = false;
}