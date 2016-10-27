//-------------------------------------------------------------------------
// Namn: Rickard Skeppström
// Personnr: 790930-xxxx
// Klass: SP6
// E-mail: rickard_skeppstrom@msn.com alt rickard.skeppstrom@powerhouse.net
// Lab: Projekt spel
//-------------------------------------------------------------------------


#ifndef HEADCOACH_H
#define HEADCOACH_H

class CHeadCoach
{
private:

	int Money;
	bool Payed;
	bool PaymentButton;
	int Payment;
	int fan_factor;

public:

	bool ShowPaymentButton(HDC BackBuffer, char* caption, POINT location, HDC bitmap, HBITMAP hbutton, BITMAP button);
	void ResetPayed();
	void Pay(HDC test, int Sum, POINT mouseloc,bool state);
	int Treasury();
	CHeadCoach();
	~CHeadCoach() {};
};
#endif