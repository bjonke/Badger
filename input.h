#ifndef INPUT_H
#define INPUT_H

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

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
 
/*
struct TILES
{
	HBITMAP hBadAcorn;
	BITMAP BadAcorn;
	HBITMAP hAcorn;
	BITMAP Acorn;
	HBITMAP hWall;
	HBITMAP hExit;
	BITMAP Wall;
	BITMAP Exit;
	HBITMAP hIntro;
	BITMAP Intro;
};

struct PLAYER
{
	int x;
	int y;
	int Score;
	int Velocity;
	double Acorns;
	HBITMAP hIcon;
	BITMAP Icon;
	
	bool BadAcorn;
	
};
*/

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

/*
class CInput
{
private:

	int Splash;
	PLAYER Character;
	PLAYER Character2;

	int Col;
	int Row;
	int FieldX;
	int FieldY;
	
public:

	int AcornField[FieldSize][FieldSize];
	
	bool Collecting();
	bool Sick();
	bool CheckForAcorns();
	void SpreadAcorns();
	int Acorns();
	int Acorns2();
	int Score();
	int Score2();
	int Xloc();
	int Yloc();
	int Xloc2();
	int Yloc2();
	void KeyPress();
	int ShowSplash();

	void Reset();

	int GameFinished();
	CInput();
	CInput::CInput(int x, int y);
	~CInput() {};
};
#endif
*/
