//-------------------------------------------------------------------------
// Namn: Rickard Skeppström
// Personnr: 790930-xxxx
// Klass: SP6
// E-mail: rickard_skeppstrom@msn.com alt rickard.skeppstrom@powerhouse.net
// Lab: Projekt spel
//-------------------------------------------------------------------------

#ifndef COINTOSS_H
#define COINTOSS_H


class CCoinToss
{
private:

	bool HeadsOrTail;

public:

	bool TossCoin();
	CCoinToss::CCoinToss();
	~CCoinToss() {};
};
#endif