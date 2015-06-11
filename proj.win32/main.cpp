#include "main.h"
#include "../Classes/AppDelegate.h"
#include "CCEGLView.h"

USING_NS_CC;

// uncomment below line, open debug console
#define USE_WIN32_CONSOLE

#include "pathfind/MapSearch.h"

// Global data

// The world map

const int MAP_WIDTH = 50;
const int MAP_HEIGHT = 50;

int world_map[ MAP_WIDTH * MAP_HEIGHT ] = 
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,   // 00
	0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,   // 01
	0,9,9,0,0,9,9,9,0,9,0,9,0,9,0,9,9,9,0,0,   // 02
	0,9,9,0,0,9,9,9,0,9,0,9,0,9,0,9,9,9,0,0,   // 03
	0,9,0,0,0,0,9,9,0,9,0,9,0,0,0,0,9,9,0,0,   // 04
	0,9,0,0,9,0,0,0,0,9,0,0,0,0,9,0,0,0,0,0,   // 05
	0,9,9,9,9,0,0,0,0,0,0,9,9,9,9,0,0,0,0,0,   // 06
	0,9,9,9,9,9,9,9,9,0,0,0,9,9,9,9,9,9,9,0,   // 07
	0,9,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,   // 08
	0,9,0,9,9,9,9,9,9,9,0,0,9,9,9,9,9,9,9,0,   // 09
	0,9,0,0,0,0,9,0,0,9,0,0,0,0,0,0,0,0,0,0,   // 10
	0,9,9,9,9,9,0,9,0,9,0,9,9,9,9,9,0,0,0,0,   // 11
	0,9,0,9,0,9,9,9,0,9,0,9,0,9,0,9,9,9,0,0,   // 12
	0,9,0,9,0,9,9,9,0,9,0,9,0,9,0,9,9,9,0,0,   // 13
	0,9,0,0,0,0,9,9,0,9,0,9,0,0,0,0,9,9,0,0,   // 14
	0,9,0,0,9,0,0,0,0,9,0,0,0,0,9,0,0,0,0,0,   // 15
	0,9,9,9,9,0,0,0,0,0,0,9,9,9,9,0,0,0,0,0,   // 16
	0,0,9,9,9,9,9,9,9,0,0,0,9,9,9,0,9,9,9,9,   // 17
	0,9,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,   // 18
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,   // 19

};

void test()
{
	MapSearch::getInstance()->init(MAP_WIDTH, MAP_HEIGHT, world_map);
	clock_t start, finish;   
	double duration;   
	start = clock();
	MapSearch::getInstance()->search(0, 0, 46, 48);
	finish = clock();   
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf( "%f seconds\n", duration ); 

	int state = MapSearch::getInstance()->getSearchState();
	if (state == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED ){
		int size = MapSearch::getInstance()->getSearchSteps();
		for (int i = 0; i < size; i ++) {
			int x = MapSearch::getInstance()->getSearchNodeX(i);
			int y = MapSearch::getInstance()->getSearchNodeY(i);

			printf("(%d, %d)\n", x, y);
		}
	}

}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

#ifdef USE_WIN32_CONSOLE 
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
#endif

    // create the application instance
    AppDelegate app;
    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
    eglView->setViewName("shader");
	//eglView->setFrameSize(960, 640);
	eglView->setFrameSize(1280, 720);
    // The resolution of ipad3 is very large. In general, PC's resolution is smaller than it.
	// So we need to invoke 'setFrameZoomFactor'(only valid on desktop(win32, mac, linux)) to make the window smaller.
	//eglView->setFrameSize(2048, 1536);
    //eglView->setFrameZoomFactor(0.4f);

    return CCApplication::sharedApplication()->run();
}