#include "scene_ui.h"
#include "demo/demo.h"
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
	this->addChild(label, 2);

    CCMenuItemImage *pBackItem = CCMenuItemImage::create( "back_0.png", "back_1.png", this, menu_selector(SceneUI::menuBackCallback));
	pBackItem->setPosition(ccp(winSize.width - pBackItem->getContentSize().width , winSize.height - pBackItem->getContentSize().height));

    CCMenu* pMenu = CCMenu::create(pBackItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
	
	CCSprite *bg = CCSprite::create("tex_0.png");
	bg->setPosition(ccp(winSize.width/2, winSize.height/2));
	bg->setScale(2);
	this->addChild(bg);

	VEScrollView *scrollview = VEScrollView::create();
	scrollview->setPosition(ccp(winSize.width/2-150, winSize.height/2+20));
	scrollview->setViewSize(CCSizeMake(180, 300));
	scrollview->setType(SCROLLVIEW_VERTICAL);
	for(int i = 0; i < 10 ; i ++){
		CCSprite *sprite = CCSprite::create("btn_1.png");
		scrollview->addCell(sprite);

		CCLabelTTF *label = CCLabelTTF::create();
		label->setFontSize(26);
		char str[10];
		sprintf(str, "%d", i);
		label->setString(str);
		label->setPosition(ccp(sprite->getContentSize().width/2, sprite->getContentSize().height/2));
		sprite->addChild(label);
	}
	this->addChild(scrollview);

	VEScrollView *scrollview2 = VEScrollView::create();
	scrollview2->setPosition(ccp(winSize.width/2, winSize.height/2-250));
	scrollview2->setViewSize(CCSizeMake(400, 130));
	scrollview2->setType(SCROLLVIEW_HORIZONTAL);
	for(int i = 0; i < 10 ; i ++){
		CCSprite *sprite = CCSprite::create("item1.png");
		scrollview2->addCell(sprite);

		CCLabelTTF *label = CCLabelTTF::create();
		label->setFontSize(26);
		char str[10];
		sprintf(str, "%d", i);
		label->setString(str);
		label->setPosition(ccp(sprite->getContentSize().width/2, sprite->getContentSize().height/2));
		sprite->addChild(label);
	}
	this->addChild(scrollview2);


	VEScrollView *scrollview3 = VEScrollView::create();
	scrollview3->setPosition(ccp(winSize.width/2+150, winSize.height/2+20));
	scrollview3->setViewSize(CCSizeMake(180, 300));
	scrollview3->setType(SCROLLVIEW_VERTICAL);
	{
		char str[1000];
		label = CCLabelTTF::create();
		label->setFontSize(40);
		sprintf(str, "Test");
		label->setString(str);
		scrollview3->addCell(label);		
		label = CCLabelTTF::create();
		label->setFontSize(26);
		sprintf(str, "this is a test for scroll view, this is a test for scroll view, this is a test for scroll view");
		label->setString(str);
		label->setDimensions(CCSizeMake(170, 200));
		scrollview3->addCell(label);		
		CCSprite *sprite = CCSprite::create("btn_1.png");
		scrollview3->addCell(sprite);
		label = CCLabelTTF::create();
		label->setFontSize(26);
		sprintf(str, "ok");
		label->setString(str);
		label->setPosition(ccp(sprite->getContentSize().width/2, sprite->getContentSize().height/2));
		sprite->addChild(label);
	}

	this->addChild(scrollview3);

    return true;
}


void SceneUI::menuBackCallback(CCObject* pSender)
{
	CCScene *pScene = Demo::scene();
	CCDirector::sharedDirector()->replaceScene(pScene);
}
