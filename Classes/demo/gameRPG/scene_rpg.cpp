#include <string>
#include "scene_rpg.h"
#include "demo/demo.h"
#include "ui/VEScrollView.h"
#include "ui/Utils.h"
#include "config.h"
#include "game_controller.h"
#include "game_ui.h"
#include "game_bg.h"

USING_NS_CC;


CCScene* SceneRPG::scene()
{
	// config
	Config::GetInstance()->init();
	GameController::GetInstance()->init();

    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SceneRPG *layer = SceneRPG::create();

    // add layer as a child to scene
    scene->addChild(layer);


    // return the scene
    return scene;
}


bool SceneRPG::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	m_bgLayer = GameBgLayer::create();
	this->addChild(m_bgLayer);
	
	m_uiLayer = GameUILayer::create();
	this->addChild(m_uiLayer);

	GameController::GetInstance()->setBgLayer(m_bgLayer);
	GameController::GetInstance()->setUILayer(m_uiLayer);

	//this->setTouchEnabled(true);

    return true;
}

bool SceneRPG::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint localPoint = convertTouchToNodeSpace(pTouch);
	
	return true;
}

void SceneRPG::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{

}

void SceneRPG::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{

}

void SceneRPG::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	ccTouchBegan((CCTouch*)pTouches->anyObject(), pEvent);
}

void SceneRPG::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	ccTouchMoved((CCTouch*)pTouches->anyObject(), pEvent);
}

void SceneRPG::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	ccTouchEnded((CCTouch*)pTouches->anyObject(), pEvent);
}