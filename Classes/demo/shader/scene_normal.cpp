#include "scene_normal.h"
#include "shader/normal_sprite.h"
#include "demo_shader.h"

USING_NS_CC;

CCScene* SceneNormal::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SceneNormal *layer = SceneNormal::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool SceneNormal::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCLabelTTF* label = CCLabelTTF::create("Normal", "Arial", 30); 
	label->setPosition(ccp(winSize.width/2, winSize.height-100));
	this->addChild(label);


    CCMenuItemImage *pBackItem = CCMenuItemImage::create( "back_0.png", "back_1.png", this, menu_selector(SceneNormal::menuBackCallback));
	pBackItem->setPosition(ccp(winSize.width - pBackItem->getContentSize().width , winSize.height - pBackItem->getContentSize().height));

    CCMenu* pMenu = CCMenu::create(pBackItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);


	m_pNormalSprite = NormalSprite::create("powered.png", "powered_n.jpg");
	m_pNormalSprite->setPosition(ccp(winSize.width/2, winSize.height/2));
	this->addChild(m_pNormalSprite);

	m_pNormalSprite->setLightPos(ccp(winSize.width/2, winSize.height/2));
	this->setTouchEnabled(true);

    return true;
}


void SceneNormal::menuBackCallback(CCObject* pSender)
{
	CCScene *pScene = Demo_shader::scene();
	CCDirector::sharedDirector()->replaceScene(pScene);
}


void SceneNormal::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	CCSetIterator it;
	CCTouch* touch;
	for( it = touches->begin(); it != touches->end(); it++)
	{
		touch = (CCTouch*)(*it);
		if(!touch)
			break;

		CCPoint loc_winSpace = touch->getLocationInView();
		CCPoint loc_GLSpace = CCDirector::sharedDirector()->convertToGL(loc_winSpace);
		//CCLOG("loc_GLSpace:%f,%f",loc_GLSpace.x,loc_GLSpace.y);

		m_pNormalSprite->setLightPos(loc_GLSpace);
	}
}

void SceneNormal::ccTouchesMoved(cocos2d::CCSet* touches , cocos2d::CCEvent* event)
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	CCSetIterator it;
	CCTouch* touch;
	for( it = touches->begin(); it != touches->end(); it++)
	{
		touch = (CCTouch*)(*it);

		if(!touch)
			break;

		CCPoint loc_winSpace = touch->getLocationInView();
		CCPoint loc_GLSpace = CCDirector::sharedDirector()->convertToGL(loc_winSpace);

		m_pNormalSprite->setLightPos(loc_GLSpace);
	}
}
