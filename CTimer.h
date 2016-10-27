// Timer.h

#ifndef TIMER_H
#define TIMER_H

#include <windows.h>

class framerate
{
public:
  float         targetfps;
  float         fps;
  LARGE_INTEGER tickspersecond;
  LARGE_INTEGER currentticks;
  LARGE_INTEGER framedelay;
	
  float         speedfactor;			

  void          Init(float tfps);
  void          SetSpeedFactor();
};

#endif