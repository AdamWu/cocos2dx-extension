#include "ContentLayer.h"

USING_NS_CC;

using namespace std;

bool ContentLayer::init()
{
	 if ( !CCLayer::init() )
    {
        return false;
    }

    CCLayer::setTouchEnabled(true);
    isSingleClick = false;
    
	return true;
}

void ContentLayer::setTouchEnabled(bool value)
{
    CCLayer::setTouchEnabled(value);
}

// default implements are used to call script callback if exist
bool ContentLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    currentTouch = pTouch;
    isSingleClick = true;
    this->scheduleOnce(schedule_selector(ContentLayer::onPressTimer), 0.5);
    return true;
}
void ContentLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint currPoint = pTouch->getLocationInView();
	CCPoint prevPoint = pTouch->getPreviousLocationInView();
    
	if(ccpDistance(currPoint, prevPoint) > 5)
    {
        isSingleClick = false;
        this->unschedule(schedule_selector(ContentLayer::onPressTimer));
    }
}
void ContentLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    this->unschedule(schedule_selector(ContentLayer::onPressTimer));
    if(isSingleClick)
    {
        this->onSingleClick(pTouch);
        isSingleClick = false;
    }
}

// default implements are used to call script callback if exist
void ContentLayer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    ccTouchBegan((CCTouch*)pTouches->anyObject(), pEvent);
}
void ContentLayer::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    ccTouchMoved((CCTouch*)pTouches->anyObject(), pEvent);
        
}
void ContentLayer::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    ccTouchEnded((CCTouch*)pTouches->anyObject(), pEvent);
}

void ContentLayer::onPressTimer(float dt)
{
    isSingleClick = false;
    onLongClick(currentTouch);
}
