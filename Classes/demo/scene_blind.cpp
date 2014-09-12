#include "scene_blind.h"
#include "shader/blind_sprite.h"
#include "demo.h"

USING_NS_CC;

CCScene* SceneBlind::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SceneBlind *layer = SceneBlind::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool SceneBlind::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCLabelTTF* label = CCLabelTTF::create("Blind", "Arial", 30); 
	label->setPosition(ccp(winSize.width/2, winSize.height-100));
	this->addChild(label);

    CCMenuItemImage *pBackItem = CCMenuItemImage::create( "back_0.png", "back_1.png", this, menu_selector(SceneBlind::menuBackCallback));
	pBackItem->setPosition(ccp(winSize.width - pBackItem->getContentSize().width , winSize.height - pBackItem->getContentSize().height));

    CCMenu* pMenu = CCMenu::create(pBackItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
	
	CCArray *arr = CCArray::create();
	arr->addObject(CCString::create("tex_0.png"));
	arr->addObject(CCString::create("tex_1.jpg"));
	arr->addObject(CCString::create("tex_2.png"));
	BlindSprite *blind = BlindSprite::create(arr);
	blind->setPosition(ccp(winSize.width/2, winSize.height/2));
	this->addChild(blind);

    return true;
}


void SceneBlind::menuBackCallback(CCObject* pSender)
{
	CCScene *pScene = Demo::scene();
	CCDirector::sharedDirector()->replaceScene(pScene);
}
