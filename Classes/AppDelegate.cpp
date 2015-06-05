/****************************************************************************
Copyright (c) 2010-2013 cocos2d-x.org
Copyright (c) Microsoft Open Technologies, Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#include "AppDelegate.h"

#include <vector>
#include <string>

#include "CCLuaEngine.h"
#include "LuaCocos2d.h"
#include "LuaCocoStudio.h"
#include "cjson/lua_cjson.h"
#include "lua_utils.h"

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

	//pDirector->setProjection(kCCDirectorProjection2D);
    pDirector->setOpenGLView(pEGLView);
	CCSize frameSize = pEGLView->getFrameSize();

    //pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);
	pEGLView->setDesignResolutionSize(960, 640, kResolutionFixedHeight);

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

	// register lua engine
	CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
	CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);

	CCLuaStack *pStack = pEngine->getLuaStack();
	lua_State *tolua_s = pStack->getLuaState();
	luaopen_cjson(tolua_s);
	tolua_Cocos2d_open(tolua_s);
	tolua_CocoStudio_open(tolua_s);
	tolua_utils_open(tolua_s);


	std::vector<std::string> searchPaths;
	searchPaths.push_back("script");
	CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);


	std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("main.lua");
	pEngine->executeScriptFile(path.c_str());

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
