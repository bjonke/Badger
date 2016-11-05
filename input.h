#ifndef INPUT_H
#define INPUT_H

const int FieldSize = 5;

class TilesSDL
{
	TilesSDL(){ std::cout << "Initializing SDL_TILES..." << std::endl; };
	
	SDL_Texture* BadAcorn;
	SDL_Texture* Acorn;
	SDL_Texture* Wall;
	SDL_Texture* Exit;
	SDL_Texture* Intro;
};

class PlayerSDL
{
	PlayerSDL(){ std::cout << "Initializing SDL_Player..." << std::endl; };
	SDL_Texture* Texture;
	SDL_Point Position;
	SDL_Velocity;
	int Score;
	int Acorns;
	bool BadAcorn;
};

class InputSDL
{
	InputSDL(){ std::cout << "Initializing InputSDL..." << std::endl; };
	InputSDL::InputSDL(int x, int y);
	
	int Splash;
	PlayerSDL Character[2];
	SDL_Point Position;
	SDL_Point FieldPosition;
	int AcornField[FieldSize][FieldSize];
	
	bool Collecting();
	bool Sick();
	bool CheckForAcorns();
	
	int Acorns();
	int Acorns2();
	int Score();
	int Score2();
	int Xloc();
	int Yloc();
	int Xloc2();
	int Yloc2();
	int ShowSplash();
	int GameFinished();
	
	void SpreadAcorns();
	void Reset();
	void KeyPress();
};

#endif
