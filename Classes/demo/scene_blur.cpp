#include "scene_blur.h"
#include "shader/blur_sprite.h"
#include "demo.h"

USING_NS_CC;

CCScene* SceneBlur::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SceneBlur *layer = SceneBlur::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool SceneBlur::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCLabelTTF* label = CCLabelTTF::create("Blur", "Arial", 30); 
	label->setPosition(ccp(winSize.width/2, winSize.height-100));
	this->addChild(label);


    CCMenuItemImage *pBackItem = CCMenuItemImage::create( "back_0.png", "back_1.png", this, menu_selector(SceneBlur::menuBackCallback));
	pBackItem->setPosition(ccp(winSize.width - pBackItem->getContentSize().width , winSize.height - pBackItem->getContentSize().height));

    CCMenu* pMenu = CCMenu::create(pBackItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);


	CCSprite *sp = CCSprite::create("tex.png");
	sp->setPosition(ccp(winSize.width/2-200, winSize.height/2));
	this->addChild(sp);

	// blur
	BlurSprite *blur = BlurSprite::create("tex.png");
	blur->setPosition(ccp(winSize.width/2+200, winSize.height/2));
	this->addChild(blur);

    return true;
}


void SceneBlur::menuBackCallback(CCObject* pSender)
{
	CCScene *pScene = Demo::scene();
	CCDirector::sharedDirector()->replaceScene(pScene);
}
