#include <string>
#include "ui/VEScrollView.h"
#include "config.h"
#include "game_controller.h"
#include "game_ui.h"
#include "game_bg.h"

USING_NS_CC;

enum{
	TAG_BACK=0,
	TAG_ADD,
};

bool GameUILayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite *back = CCSprite::create("back_0.png");
	back->setTag(TAG_BACK);
	back->setPosition(ccp(winSize.width - back->getContentSize().width , winSize.height - back->getContentSize().height));
	this->addChild(back);

	CCSprite *shop = CCSprite::create("rpg/menu_add.png");
	shop->setTag(TAG_ADD);
	shop->setPosition(ccp(80, 80));
	this->addChild(shop);

	// scroll view
	VEScrollView *scrollview = VEScrollView::create();
	scrollview->setPosition(ccp(-70, winSize.height/2));
	scrollview->setViewSize(CCSizeMake(140, winSize.height));
	scrollview->setType(SCROLLVIEW_VERTICAL);
	scrollview->addTouchHandler(this, scroll_touch(&GameUILayer::scrollTouchHandler));
	char buf[1024];
	for(int i = 0; i < 8 ; i ++){
		CCSprite *cell = CCSprite::create("rpg/item_bg.png");
		cell->setTag(10000+i);
		sprintf(buf, "rpg/buildings/1%04d.png", i);
		CCSprite *item = CCSprite::create(buf);
		item->setPosition(ccp(cell->getContentSize().width/2, cell->getContentSize().height/2));
		cell->addChild(item);
		scrollview->addCell(cell);
	}
	this->addChild(scrollview);
	m_scrollview = scrollview;

	this->setTouchEnabled(true);

    return true;
}

void GameUILayer::scrollTouchHandler(CCObject *pSender)
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	m_scrollview->runAction(CCMoveTo::create(0.5, ccp(-70, winSize.height/2)));


	int tag = ((CCNode*)pSender)->getTag();
	printf("scrollTouchHandler %d\n", tag);

	GameController::GetInstance()->getBgLayer()->addBuildingNew(tag);
}

void GameUILayer::menuCallback(CCNode* pSender)
{    
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	switch (pSender->getTag()){
	case TAG_BACK:
		{
		}
		break;
	case TAG_ADD:
		{
			m_scrollview->runAction(CCMoveTo::create(0.5, ccp(70, winSize.height/2)));
		}
	default:
		break;
	}
}


bool GameUILayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint localPoint = convertTouchToNodeSpace(pTouch);

	printf("began (%f, %f)\n", localPoint.x, localPoint.y);

	if (this->touchCheck(localPoint)){
		return false;
	}
	return true;
}

void GameUILayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{

}


void GameUILayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint localPoint = convertTouchToNodeSpace(pTouch);
	CCNode *pNode = this->touchCheck(localPoint);
	if (pNode && pNode != m_scrollview){
		this->menuCallback(pNode);
	}
}

void GameUILayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	ccTouchBegan((CCTouch*)pTouches->anyObject(), pEvent);
}

void GameUILayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	ccTouchMoved((CCTouch*)pTouches->anyObject(), pEvent);
}

void GameUILayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	ccTouchEnded((CCTouch*)pTouches->anyObject(), pEvent);
}

//check if any node is clicked.
CCNode *GameUILayer::touchCheck(CCPoint touchPoint)
{
	CCArray *children = this->getChildren();

	if(children == NULL)
		return NULL;

	CCPoint np = this->convertToNodeSpace(touchPoint);
	for(int i=0; i<children->count(); i++)
	{
		CCNode *node = (CCNode*)children->objectAtIndex(i);
		CCRect box = node->boundingBox();
		if (node == m_scrollview) box = ((VEScrollView*)node)->boundingBox();
		if(box.containsPoint(np)){
			return node;
		}
	}

	return NULL;
}