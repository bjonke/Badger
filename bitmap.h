//-------------------------------------------------------------------------
// Namn: Rickard Skeppström
// Personnr: 790930-xxxx
// Klass: SP6
// E-mail: rickard_skeppstrom@msn.com alt rickard.skeppstrom@powerhouse.net
// Lab: Projekt spel
//-------------------------------------------------------------------------

#ifndef BITMAP_H
#define BITMAP_H


class CBitmap
{
private:



protected:

public:

	int ShowButton(HDC BackBuffer, int xloc, int yloc, POINT location, HDC bitmap, HBITMAP hbutton, BITMAP button);
	HBITMAP Load(char* test);
	CBitmap::CBitmap();
	~CBitmap() {};
};
#endif