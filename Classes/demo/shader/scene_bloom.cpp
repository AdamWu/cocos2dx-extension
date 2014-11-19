#include "scene_bloom.h"
#include "shader/bloom_sprite.h"
#include "demo_shader.h"

USING_NS_CC;

CCScene* SceneBloom::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SceneBloom *layer = SceneBloom::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool SceneBloom::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCLabelTTF* label = CCLabelTTF::create("Bloom", "Arial", 30); 
	label->setPosition(ccp(winSize.width/2, winSize.height-100));
	this->addChild(label);


    CCMenuItemImage *pBackItem = CCMenuItemImage::create( "back_0.png", "back_1.png", this, menu_selector(SceneBloom::menuBackCallback));
	pBackItem->setPosition(ccp(winSize.width - pBackItem->getContentSize().width , winSize.height - pBackItem->getContentSize().height));

    CCMenu* pMenu = CCMenu::create(pBackItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

	// bloom
	CCSprite *sp = CCSprite::create("batfly.png");
	sp->setPosition(ccp(winSize.width/2-200, winSize.height/2));
	this->addChild(sp);

	BloomSprite *bloom = BloomSprite::create("batfly.png");
	bloom->setPosition(ccp(winSize.width/2+200, winSize.height/2));
	this->addChild(bloom);
	CCSprite *sp2 = CCSprite::create("batfly.png");
	sp2->setPosition(ccp(winSize.width/2+200, winSize.height/2));
	this->addChild(sp2);

    return true;
}


void SceneBloom::menuBackCallback(CCObject* pSender)
{
	CCScene *pScene = Demo_shader::scene();
	CCDirector::sharedDirector()->replaceScene(pScene);
}
