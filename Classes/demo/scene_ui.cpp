#include "scene_ui.h"
#include "demo.h"
#include "ui/VEScrollView.h"

USING_NS_CC;

CCScene* SceneUI::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SceneUI *layer = SceneUI::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool SceneUI::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCLabelTTF* label = CCLabelTTF::create("UI", "Arial", 30); 
	label->setPosition(ccp(winSize.width/2, winSize.height-100));
	this->addChild(label);

    CCMenuItemImage *pBackItem = CCMenuItemImage::create( "back_0.png", "back_1.png", this, menu_selector(SceneUI::menuBackCallback));
	pBackItem->setPosition(ccp(winSize.width - pBackItem->getContentSize().width , winSize.height - pBackItem->getContentSize().height));

    CCMenu* pMenu = CCMenu::create(pBackItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
	
	CCSprite *bg = CCSprite::create("tex_0.png");
	bg->setPosition(ccp(winSize.width/2, winSize.height/2));
	this->addChild(bg);

	VEScrollView *scrollview = VEScrollView::create();
	scrollview->setPosition(ccp(winSize.width/2, winSize.height/2));
	scrollview->setViewSize(CCSizeMake(200, 200));

	for(int i = 0; i < 10 ; i ++){
		CCSprite *sprite = CCSprite::create("btn_1.png");
		scrollview->addLayer(sprite);

		CCLabelTTF *label = CCLabelTTF::create();
		label->setFontSize(26);
		char str[10];
		sprintf(str, "%d", i);
		label->setString(str);
		label->setPosition(ccp(sprite->getContentSize().width/2, sprite->getContentSize().height/2));
		sprite->addChild(label);
	}	

	this->addChild(scrollview);

    return true;
}


void SceneUI::menuBackCallback(CCObject* pSender)
{
	CCScene *pScene = Demo::scene();
	CCDirector::sharedDirector()->replaceScene(pScene);
}
