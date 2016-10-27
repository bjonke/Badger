#include <iostream>
using namespace std;
#include <windows.h>
#include "headcoach.h"
#include "input.h"


bool CHeadCoach::ShowPaymentButton(HDC BackBuffer, char* caption,POINT location, HDC bitmap, HBITMAP hbutton, BITMAP button)
{
	char buffer[100];
	static RECT Information;

	SetRect(&Information,250,590,250+button.bmWidth,590+button.bmHeight);

	if(PaymentButton)
	{
		SelectObject(bitmap, hbutton);
		TransparentBlt( BackBuffer, 250, 590, 
		button.bmWidth, button.bmHeight,
		bitmap, 0, 0, button.bmWidth, button.bmHeight, RGB(0,0,0) );

		
		if(PtInRect(&Information,location))
			if(KEY_DOWN(VK_LBUTTON))
			{
			if(!Payed)  //PaymentButton = false;
				Money -= Payment;
				Payed = false;
				PaymentButton = false;
			}
	}
return true;
}

void CHeadCoach::ResetPayed()
{
	Payed = false;
}
void CHeadCoach::Pay(HDC test, int Sum, POINT mouseloc, bool state)
{
	PaymentButton = state;
		Payment = Sum;
}
int CHeadCoach::Treasury()
{
	return Money;
}

CHeadCoach::CHeadCoach()
{
	PaymentButton = false;
	Payed = false;
	Money = 1000000;
	Payment = 0;
	fan_factor = 1;
}
