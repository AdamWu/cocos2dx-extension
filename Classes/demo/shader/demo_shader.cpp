#include <vector>

#include "demo_shader.h"

#include "scene_stream.h"
#include "scene_blind.h"
#include "scene_blur.h"
#include "scene_frost.h"
#include "scene_bloom.h"
#include "scene_normal.h"
#include "scene_laser.h"
#include "scene_ripple.h"
#include "demo/demo.h"

using namespace std;

USING_NS_CC;

enum
{
	TEST_STREAM = 0,
	TEST_BLIND,
	TEST_BLUR,
	TEST_FROST,
	TEST_BLOOM,
	TEST_NORMAL,
	TEST_LASER,
	TEST_RIPPLE,

	// last one
	TESTS_COUNT,
};

const std::string g_aTestNames[TESTS_COUNT] = {
	"Stream",
	"Blind",
	"Blur",
	"Frost",
	"Bloom",
	"Normal",
	"Laser",
	"Ripple",
};

static CCPoint s_tCurPos = CCPointZero;

const float CELL_WIDTH = 300;

CCScene* Demo_shader::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Demo_shader *layer = Demo_shader::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Demo_shader::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();


	CCLabelTTF* title = CCLabelTTF::create("Experiment", "Arial", 40); 
	title->setPosition(ccp(winSize.width/2, winSize.height-150));
	this->addChild(title);


	// add menu items for tests
	m_pItemMenu = CCMenu::create();
	for (int i = 0; i < TESTS_COUNT; ++i)
	{  
		CCSprite* sprite = CCSprite::create();
		bool bRet = sprite->initWithFile((string("demo/")+g_aTestNames[i].c_str()+".jpg").c_str());
		if (bRet == false) {
			sprite->initWithFile("demo/default.png");
		}
		CCMenuItemSprite* pMenuItem = CCMenuItemSprite::create(sprite, sprite, sprite, this, menu_selector(Demo_shader::menuCallback));
		m_pItemMenu->addChild(pMenuItem, i + 10000);
		pMenuItem->setAnchorPoint(ccp(0.5, 0.5));
		pMenuItem->setPosition(ccp(50 + i * CELL_WIDTH + CELL_WIDTH/2, winSize.height/2));
		pMenuItem->setScale(0.3f);

		CCLabelTTF* label = CCLabelTTF::create(g_aTestNames[i].c_str(), "Arial", 24);
		label->setAnchorPoint(ccp(0.5, 0.5));
		label->setPosition(ccp(500, -100));
		label->setScale(5);
		pMenuItem->addChild(label);
	}
	m_pItemMenu->setPosition(s_tCurPos);
	addChild(m_pItemMenu);

	// menu close    
	CCMenuItemImage *pBackItem = CCMenuItemImage::create( "back_0.png", "back_1.png", this, menu_selector(Demo_shader::menuBackCallback));
	pBackItem->setPosition(ccp(winSize.width - pBackItem->getContentSize().width , winSize.height - pBackItem->getContentSize().height));

	CCMenu* pMenu = CCMenu::create(pBackItem, NULL);
	pMenu->setPosition(CCPointZero);
	addChild(pMenu);

	setTouchEnabled(true);
	
    return true;
}

void Demo_shader::menuCallback(CCObject * pSender)
{
	// get the userdata, it's the index of the menu item clicked
	CCMenuItem* pMenuItem = (CCMenuItem *)(pSender);
	int nIdx = pMenuItem->getZOrder() - 10000;
	
	CCScene* pScene = NULL;
	switch (nIdx)
	{
	case TEST_STREAM:
		pScene = SceneStream::scene(); break;
	case TEST_BLIND:
		pScene = SceneBlind::scene(); break;
	case TEST_BLUR:
		pScene = SceneBlur::scene(); break;
	case TEST_FROST:
		pScene = SceneFrost::scene(); break;
	case TEST_BLOOM:
		pScene = SceneBloom::scene(); break;
	case TEST_NORMAL:
		pScene = SceneNormal::scene(); break;
	case TEST_LASER:
		pScene = SceneLaser::scene(); break;
	case TEST_RIPPLE:
		pScene = SceneRipple::scene(); break;
	default:
		break;
	}
	if (pScene)
		CCDirector::sharedDirector()->replaceScene(pScene);
}



void Demo_shader::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}


void Demo_shader::menuBackCallback(CCObject* pSender)
{
	CCScene *pScene = Demo::scene();
	CCDirector::sharedDirector()->replaceScene(pScene);
}

void Demo_shader::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*)(*it);

	m_tBeginPos = touch->getLocation();    
}

void Demo_shader::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*)(*it);

	CCPoint touchLocation = touch->getLocation();    
	float nMoveX = touchLocation.x - m_tBeginPos.x;

	CCPoint curPos  = m_pItemMenu->getPosition();
	CCPoint nextPos = ccp(curPos.x + nMoveX, curPos.y);

	if (nextPos.x > 0.0f)
	{
		m_pItemMenu->setPosition(CCPointZero);
		return;
	}

	if (nextPos.x < winSize.width-(TESTS_COUNT * CELL_WIDTH + CELL_WIDTH/2))
	{
		m_pItemMenu->setPosition(ccp(winSize.width-(TESTS_COUNT*CELL_WIDTH + CELL_WIDTH/2), 0));
		return;
	}

	m_pItemMenu->setPosition(nextPos);
	m_tBeginPos = touchLocation;
	s_tCurPos   = nextPos;
}