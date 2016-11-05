#ifndef GRAPHICS_H
#define GRAPHICS_H

class GraphicsSDL
{
public:
	GraphicsSDL(){ std::cout << "Initializing GraphicsSDL" << std::cout; };
	const SDL_Point Field;
	const int FieldX;
	const int FieldY;
	int Row;
	int Col;
	int MenuChoiceOne;
	bool ShowMenu;
	bool Splash;
	
	bool Init();
	void SplashScreen();
	void EraseScreen();
	bool Render();
	void Text();
	void Menu();
	void Input();
	void GameFinished();
	void Release();

	GraphicsSDL::GraphicsSDL(int x, int y);
};

class CGraphics
{
private:

	HWND main_window_handle;

	const int FieldX;
	const int FieldY;

	int Row;
	int Col;

	int MenuChoiceOne;
	
public:

	bool ShowMenu;
	bool Splash;

	bool Init(HWND hwnd);
	void SplashScreen();
	void EraseScreen();
	bool Render();
	void Text();
	void Menu();
	void Input();
	void GameFinished();
	void Release();

	CGraphics::CGraphics(int x, int y);
	~CGraphics();
};
#endif
