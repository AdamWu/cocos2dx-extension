#include "scene_ripple.h"
#include "shader/ripple_sprite.h"
#include "demo_shader.h"

USING_NS_CC;

CCScene* SceneRipple::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SceneRipple *layer = SceneRipple::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool SceneRipple::init()
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


    CCMenuItemImage *pBackItem = CCMenuItemImage::create( "back_0.png", "back_1.png", this, menu_selector(SceneRipple::menuBackCallback));
	pBackItem->setPosition(ccp(winSize.width - pBackItem->getContentSize().width , winSize.height - pBackItem->getContentSize().height));

    CCMenu* pMenu = CCMenu::create(pBackItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);


	m_pSprite = RippleSprite::create("powered.png");
	m_pSprite->setPosition(ccp(winSize.width/2-200, winSize.height/2));
	this->addChild(m_pSprite);

	m_pSprite = RippleSprite::create("powered.png");
	m_pSprite->setPosition(ccp(winSize.width/2+200, winSize.height/2));
	m_pSprite->setTile(0.1f);
	m_pSprite->setNoiseFactor(0.01f);
	m_pSprite->setSpeed(0.02f);
	this->addChild(m_pSprite);

	this->setTouchEnabled(true);

    return true;
}


void SceneRipple::menuBackCallback(CCObject* pSender)
{
	CCScene *pScene = Demo_shader::scene();
	CCDirector::sharedDirector()->replaceScene(pScene);
}