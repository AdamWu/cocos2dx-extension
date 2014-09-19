#include <vector>

#include "demo.h"

#include "demo/scene_stream.h"
#include "demo/scene_blind.h"
#include "demo/scene_blur.h"
#include "demo/scene_frost.h"
#include "demo/scene_bloom.h"
#include "demo/scene_ui.h"

using namespace std;

USING_NS_CC;

enum
{
	TEST_STREAM = 0,
	TEST_BLIND,
	TEST_BLUR,
	TEST_FROST,
	TEST_BLOOM,
	TEST_UI,

	// last one
	TESTS_COUNT,
};

const std::string g_aTestNames[TESTS_COUNT] = {
	"Stream",
	"Blind",
	"Blur",
	"Frost",
	"Bloom",
	"UI",
};

static CCPoint s_tCurPos = CCPointZero;

const float CELL_WIDTH = 300;

CCScene* Demo::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Demo *layer = Demo::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Demo::init()
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
		CCMenuItemSprite* pMenuItem = CCMenuItemSprite::create(sprite, sprite, sprite, this, menu_selector(Demo::menuCallback));
		m_pItemMenu->addChild(pMenuItem, i + 10000);
		pMenuItem->setPosition(ccp(50 + i * CELL_WIDTH + CELL_WIDTH/2, winSize.height/2));
		pMenuItem->setScale(0.2);

		CCLabelTTF* label = CCLabelTTF::create(g_aTestNames[i].c_str(), "Arial", 24); 
		label->setPosition(ccp(500, -100));
		label->setScale(5);
		pMenuItem->addChild(label);
	}
	m_pItemMenu->setPosition(s_tCurPos);
	addChild(m_pItemMenu);

	// menu close
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this, menu_selector(Demo::menuCloseCallback));
	pCloseItem->setPosition(ccp(winSize.width - pCloseItem->getContentSize().width , winSize.height - pCloseItem->getContentSize().height));
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	addChild(pMenu);

	setTouchEnabled(true);
	
    return true;
}

void Demo::menuCallback(CCObject * pSender)
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
	case TEST_UI:
		pScene = SceneUI::scene(); break;
	default:
		break;
	}
	if (pScene)
		CCDirector::sharedDirector()->replaceScene(pScene);
}

void Demo::ccKeyboardBegin(unsigned int INparam)
{
	// A->Z
	// 41->5A
	CCLOG("begin %d", INparam);
	if (INparam == 0x41) {//a
		//m_pSprite->runAction(CCMoveBy::create(.2, ccp(-10, 0)));
	}else if (INparam == 0x44){//d
		//m_pSprite->runAction(CCMoveBy::create(.2, ccp(10, 0)));
	}else if (INparam == 0x53){//s
		//m_pSprite->runAction(CCMoveBy::create(.2, ccp(0, -10)));
	}else if (INparam == 0x57) {//w
		//m_pSprite->runAction(CCMoveBy::create(.2, ccp(0, 10)));
	}
 }

void Demo::ccKeyboardEnd(unsigned int INparam)
{

	CCLOG("end %d", INparam);
}



void Demo::menuCloseCallback(CCObject* pSender)
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


void Demo::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*)(*it);

	m_tBeginPos = touch->getLocation();    
}

void Demo::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
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