#include "scene_frost.h"
#include "shader/frost_sprite.h"
#include "demo_shader.h"

USING_NS_CC;

CCScene* SceneFrost::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SceneFrost *layer = SceneFrost::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool SceneFrost::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCLabelTTF* label = CCLabelTTF::create("Frost", "Arial", 30); 
	label->setPosition(ccp(winSize.width/2, winSize.height-100));
	this->addChild(label);


    CCMenuItemImage *pBackItem = CCMenuItemImage::create( "back_0.png", "back_1.png", this, menu_selector(SceneFrost::menuBackCallback));
	pBackItem->setPosition(ccp(winSize.width - pBackItem->getContentSize().width , winSize.height - pBackItem->getContentSize().height));

    CCMenu* pMenu = CCMenu::create(pBackItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);


	CCSprite *sp = CCSprite::create("tex.png");
	sp->setPosition(ccp(winSize.width/2-200, winSize.height/2));
	this->addChild(sp);

	// frost
	FrostSprite *frost = FrostSprite::create("tex.png");
	frost->setPosition(ccp(winSize.width/2+200, winSize.height/2));
	this->addChild(frost);

    return true;
}


void SceneFrost::menuBackCallback(CCObject* pSender)
{
	CCScene *pScene = Demo_shader::scene();
	CCDirector::sharedDirector()->replaceScene(pScene);
}
