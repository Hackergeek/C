#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <time.h>
#include <math.h>

#pragma comment(lib, "msimg32.lib")

#define WINDOW_WIDTH    654                            
#define WINDOW_HEIGHT   513                            
#define WINDOW_TITLE    _T("Demo")
#define WINDOW_CLASS    _T("ForTheTest")

HWND InitInstance(HINSTANCE hInstance, int nShowCmd);
LRESULT CALLBACK WndProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam );

BOOL GameInit(HWND hWnd);
BOOL GameAction(HWND hWnd);
BOOL GamePaint(HWND hWnd);
BOOL GameClearup(HWND hWnd);

HINSTANCE g_hInst;
HDC g_hdcMem;
HDC g_hdcMem1;
HBITMAP g_hBmpMem;
HBITMAP g_hBmpBackground;
HBITMAP g_hBmpPlayer;
POINT g_ptActive;
enum DIRECTION{DOWN, LEFT, RIGHT, UP, DOWNLEFT, DOWNRIGHT, UPLEFT, UPRIGHT} g_emDirection;
INT g_nDistance;
RECT g_rtClip;
RECT g_rtBk;
INT g_nWidth, g_nHeight;
BOOL g_bMove;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASSEX wndClass = { 0 };
	wndClass.cbSize        = sizeof( WNDCLASSEX ) ;
	wndClass.style         = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc   = WndProc;
	wndClass.cbClsExtra    = 0;
	wndClass.cbWndExtra    = 0;
	wndClass.hInstance     = hInstance;
	wndClass.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor       = LoadCursor( NULL, IDC_ARROW );
	wndClass.hbrBackground = GetStockBrush(WHITE_BRUSH);
	wndClass.lpszMenuName  = NULL;
	wndClass.lpszClassName = WINDOW_CLASS;

	if( !RegisterClassEx( &wndClass ) )
		return -1;

	g_hInst = hInstance;
	
	HWND hWnd = InitInstance(hInstance, nShowCmd);
	if ( !hWnd)
		return -1;

	MSG msg = { 0 };
	DWORD dwTick, dwPreTick = GetTickCount();
	if ( !GameInit(hWnd))
		return -1;

	while( msg.message != WM_QUIT )
	{
		if( PeekMessage( &msg, 0, 0, 0, PM_REMOVE ) )
		{
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
		else
		{
			dwTick = GetTickCount();
			if (dwTick - dwPreTick > 40)
			{
				if (GameAction(hWnd))
					GamePaint(hWnd);
				dwPreTick = GetTickCount();
			}
		}
	}
	UnregisterClass(WINDOW_CLASS, wndClass.hInstance); 
	return 0;  
}

// 居中显示
HWND InitInstance(HINSTANCE hInstance, int nShowCmd)
{
	int cx = GetSystemMetrics(SM_CXSCREEN);
	int cy = GetSystemMetrics(SM_CYSCREEN);
	HWND hWnd = CreateWindow(WINDOW_CLASS, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		(cx-WINDOW_WIDTH)/2, (cy-WINDOW_HEIGHT)/2, WINDOW_WIDTH, WINDOW_HEIGHT, 
		NULL, NULL, hInstance, NULL);
	if (!hWnd)
		return NULL;
	ShowWindow(hWnd, nShowCmd);
	UpdateWindow(hWnd);
	return hWnd;
}

// 窗口过程
LRESULT CALLBACK WndProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam )      
{
	switch( message )
	{
	case WM_CLOSE:
		{
			GameClearup(hwnd);
			DestroyWindow(hwnd);
			break;
		}
	case WM_DESTROY:
		{
			PostQuitMessage( 0 );
			break;
		}
	default:
		return DefWindowProc( hwnd, message, wParam, lParam );
	}
	return 0;
}

// 游戏初始化
BOOL GameInit(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);
	g_hdcMem = CreateCompatibleDC(hdc);
	g_hdcMem1 = CreateCompatibleDC(hdc);
	g_hBmpMem = CreateCompatibleBitmap(hdc, 640, 480);
	SelectBitmap(g_hdcMem, g_hBmpMem);
	ReleaseDC(hWnd, hdc);

	// 加载位图
	g_hBmpBackground = (HBITMAP)LoadImage(g_hInst, _T("Res/background.bmp"), IMAGE_BITMAP, 640, 480, LR_LOADFROMFILE);
	g_hBmpPlayer = (HBITMAP)LoadImage(g_hInst, _T("Res/boy.bmp"), IMAGE_BITMAP, 280, 992, LR_LOADFROMFILE);

	g_nWidth = 70;
	g_nHeight = 124;
	g_ptActive.x = 320;
	g_ptActive.y = 240;
	g_emDirection = DOWN;
	g_nDistance = 5;
	g_bMove = FALSE;
	
	SetRect(&g_rtClip, 35, 62, 640-35, 480-62);
	SetRect(&g_rtBk, -320, -240, 320, 240);

	return TRUE;
}

// 游戏逻辑
BOOL GameAction(HWND hWnd)
{
	// 判断键盘
	SHORT rec = 0;
	rec += (GetAsyncKeyState(VK_UP)<0) ? 8 : 0;
	rec += (GetAsyncKeyState(VK_RIGHT)<0) ? 4 : 0;
	rec += (GetAsyncKeyState(VK_DOWN)<0) ? 2 : 0;
	rec += (GetAsyncKeyState(VK_LEFT)<0) ? 1 : 0;

	int x=0, y=0;
	switch (rec)
	{
	case 1:
		g_emDirection = LEFT;
		x = -g_nDistance;
		break;
	case 2:
		g_emDirection = DOWN;
		y = g_nDistance;
		break;
	case 4:
		g_emDirection = RIGHT;
		x = g_nDistance;
		break;
	case 8:
		g_emDirection = UP;
		y = -g_nDistance;
		break;
	case 3:
		g_emDirection = DOWNLEFT;
		x = -g_nDistance;
		y = g_nDistance;
		break;
	case 6:
		g_emDirection = DOWNRIGHT;
		x = g_nDistance;
		y = g_nDistance;
		break;
	case 9:
		g_emDirection = UPLEFT;
		x = -g_nDistance;
		y = -g_nDistance;
		break;
	case 12:
		g_emDirection = UPRIGHT;
		x = g_nDistance;
		y = -g_nDistance;
		break;
	default:
		g_bMove = FALSE;
		return TRUE;
	}

	// 计算运动坐标
	g_bMove = TRUE;
	g_ptActive.x += x;
	g_ptActive.y += y;

	if (g_ptActive.x < g_rtClip.left)
	{
		g_ptActive.x = g_rtClip.left;
		x = 0;
	}
	else if (g_ptActive.x > g_rtClip.right)
	{
		g_ptActive.x = g_rtClip.right;
		x = 0;
	}
	
	if (g_ptActive.y < g_rtClip.top)
	{
		g_ptActive.y = g_rtClip.top;
		y = 0;
	}
	else if (g_ptActive.y > g_rtClip.bottom)
	{
		g_ptActive.y = g_rtClip.bottom;
		y = 0;
	}

	// 背景绘图矩形
	OffsetRect(&g_rtBk, -x, -y);

	return TRUE;
}

// 游戏绘制
BOOL GamePaint(HWND hWnd)
{
	// 绘制地图
	SelectBitmap(g_hdcMem1, g_hBmpBackground);
	BitBlt(g_hdcMem, g_rtBk.left, g_rtBk.top, 640, 480, g_hdcMem1, 0, 0, SRCCOPY);
	BitBlt(g_hdcMem, g_rtBk.right, g_rtBk.top, 640, 480, g_hdcMem1, 0, 0, SRCCOPY);
	BitBlt(g_hdcMem, g_rtBk.left, g_rtBk.bottom, 640, 480, g_hdcMem1, 0, 0, SRCCOPY);
	BitBlt(g_hdcMem, g_rtBk.right, g_rtBk.bottom, 640, 480, g_hdcMem1, 0, 0, SRCCOPY);
	
	// 绘制角色
	static int sTag=0, sDir=0;
	static DWORD sTickWalk = GetTickCount();
	if (g_bMove)
	{
		if (sDir != g_emDirection)
		{
			sTag = 0;
			sDir = g_emDirection;
		}
		else if (GetTickCount() - sTickWalk > 150)
		{
			sTag = (sTag + 1) % 4;
			sTickWalk = GetTickCount();
		}
	}
	else
	{
		sTag = 0;
	}

	SelectBitmap(g_hdcMem1, g_hBmpPlayer);
	TransparentBlt(g_hdcMem, g_ptActive.x-35, g_ptActive.y-62, 70, 124,
				   g_hdcMem1, 70*sTag, 124*sDir, 70, 124, RGB(255, 255, 255));

	HDC hdc = GetDC(hWnd);
	BitBlt(hdc, 0, 0, 640, 480, g_hdcMem, 0, 0, SRCCOPY);
	ReleaseDC(hWnd, hdc);

	return TRUE;
}

// 游戏清除
BOOL GameClearup(HWND hWnd)
{
	DeleteDC(g_hdcMem);
	DeleteDC(g_hdcMem1);
	
	DeleteBitmap(g_hBmpMem);
	DeleteBitmap(g_hBmpBackground);
	DeleteBitmap(g_hBmpPlayer);

	return TRUE;
}