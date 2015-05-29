#include "scene_hue.h"
#include "shader/hue_sprite.h"
#include "demo_shader.h"

USING_NS_CC;

CCScene* SceneHue::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SceneHue *layer = SceneHue::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool SceneHue::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCLabelTTF* label = CCLabelTTF::create("Ripple", "Arial", 30); 
	label->setPosition(ccp(winSize.width/2, winSize.height-100));
	this->addChild(label);


    CCMenuItemImage *pBackItem = CCMenuItemImage::create( "back_0.png", "back_1.png", this, menu_selector(SceneHue::menuBackCallback));
	pBackItem->setPosition(ccp(winSize.width - pBackItem->getContentSize().width , winSize.height - pBackItem->getContentSize().height));

    CCMenu* pMenu = CCMenu::create(pBackItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);


	CCSprite* left = CCSprite::create("powered.png");
	left->setPosition(ccp(winSize.width/2-250, winSize.height/2));
	this->addChild(left);

	m_pSprite = HueSprite::create("powered.png");
	m_pSprite->setPosition(ccp(winSize.width/2, winSize.height/2));
	m_pSprite->setHue(M_PI*1.f/5.f);
	this->addChild(m_pSprite);

	m_pSprite = HueSprite::create("powered.png");
	m_pSprite->setPosition(ccp(winSize.width/2+250, winSize.height/2));
	m_pSprite->setHue(M_PI*9.f/5.f);
	this->addChild(m_pSprite);

	this->setTouchEnabled(true);

    return true;
}


void SceneHue::menuBackCallback(CCObject* pSender)
{
	CCScene *pScene = Demo_shader::scene();
	CCDirector::sharedDirector()->replaceScene(pScene);
}