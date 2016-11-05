#include <ctime>
#include "graphics.h"
#include "Input.h"

CGraphics* g_Game = 0;

#include <SDL.h>
 
int main(int argc, char ** argv)
{
    // variables
 
    bool quit = false;
    SDL_Event event;
    int x = 288;
    int y = 208;
 
    // init SDL
 
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * window = SDL_CreateWindow("SDL2 Keyboard/Mouse events",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
 
    SDL_Surface * image = SDL_LoadBMP("spaceship.bmp");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
        image);
    SDL_FreeSurface(image);
 
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
 
    // handle events
 
    while (!quit)
    {
        SDL_WaitEvent(&event);
 
        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        }
 
        SDL_Rect dstrect = { x, y, 64, 64 };
 
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_RenderPresent(renderer);
    }
 
    // cleanup SDL
 
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
 
/* WINDOWS */
	srand ( time(0) );

	g_Game = new CGraphics(5,5);

	ShowWindow(hwnd, iCmdShow) ;
	UpdateWindow(hwnd);

	g_Game->Init(hwnd);

	while(msg.message != WM_QUIT)
	{
		if(PeekMessage (&msg,0,0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else if(GetFocus() == hwnd)
		{
			g_Game->EraseScreen();
			g_Game->Text();

			if( (!g_Game->Splash) && (!g_Game->ShowMenu))
				g_Game->Input();

			if(g_Game->Splash)
				g_Game->SplashScreen();

			if(g_Game->ShowMenu && !g_Game->Splash)
				g_Game->Menu();
			if(!g_Game->Splash && !g_Game->ShowMenu)
				g_Game->Render();		
		}
		else
		{
			if(g_Game->Splash)
				g_Game->SplashScreen();

			if(g_Game->ShowMenu && !g_Game->Splash)
				g_Game->Menu();
			if(!g_Game->Splash && !g_Game->ShowMenu)
				g_Game->Render();
		}
	}
	delete g_Game;
/* ******* */
	
    return 0;
}
