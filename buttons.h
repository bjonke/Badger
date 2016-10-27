//-------------------------------------------------------------------------
// Namn: Rickard Skeppström
// Personnr: 790930-xxxx
// Klass: SP6
// E-mail: rickard_skeppstrom@msn.com alt rickard.skeppstrom@powerhouse.net
// Lab: Projekt spel
//-------------------------------------------------------------------------


#ifndef BUTTONS_H
#define BUTTONS_H

#include "bitmap.h"

class CButtons : public CBitmap
{
private:

public:

	bool Button(HDC BackBuffer, char* caption, POINT location, HDC bitmap, HBITMAP hbutton, BITMAP button);
	bool CreateButton(HDC BackBuffer, RECT size, char* caption, POINT location);
	virtual bool Trigger(HDC BackBuffer, RECT size, char* caption, POINT location) const;
	CButtons();
	~CButtons() {};
};
#endif