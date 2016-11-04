#include <windows.h>
#include <ctime>
#include "graphics.h"
#include "Input.h"


//--------------------------------------------------------------------
// Globals
//--------------------------------------------------------------------
CGraphics* g_Game = 0;

//--------------------------------------------------------------------
// Functions
//--------------------------------------------------------------------
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

//--------------------------------------------------------------------
//	Main window entry point
//--------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
				   PSTR szCmdLine, int iCmdShow) 
{
	TCHAR szAppName[] = "Projekt";
	HWND hwnd;
	MSG			msg = {0};
	WNDCLASS	wndclass ;

	wndclass.style			= CS_HREDRAW | CS_VREDRAW ;
	wndclass.lpfnWndProc	= WndProc ;
	wndclass.cbClsExtra		= 0 ;
	wndclass.cbWndExtra		= 0 ;
	wndclass.hInstance		= hInstance ;
	wndclass.hIcon			= LoadIcon (hInstance, IDI_APPLICATION) ;
	wndclass.hCursor		= LoadCursor (hInstance, IDC_ARROW) ;
	wndclass.hbrBackground	= (HBRUSH) GetStockObject (BLACK_BRUSH) ;
	wndclass.lpszMenuName	= NULL ;
	wndclass.lpszClassName	= szAppName ;

	if (!RegisterClass (&wndclass))
	{
		MessageBox (NULL, TEXT ("This program requires a advanced windows"),
					szAppName, MB_ICONERROR) ;
		return 0;
	}
	
	// Huvudfönstret
	hwnd = CreateWindow (szAppName,		// Window class name
						 TEXT ("Projekt"),	//window caption
						 WS_OVERLAPPED | WS_BORDER,
						 0,
						 0,
						 646,
						 525,
						 NULL,
						 NULL,
						 hInstance,
						 NULL) ;


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
	return(msg.wParam) ;
}

/*******************************************************************************
* LRESULT CALLBACK WndProc() sköter grovjobbet
/*******************************************************************************/
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{	
	switch (message)
	{
		case WM_QUIT:
			return 0;

		case WM_DESTROY:
			PostQuitMessage (0) ;
			return 0;
	}
	return DefWindowProc (hwnd, message, wParam, lParam) ;
}
