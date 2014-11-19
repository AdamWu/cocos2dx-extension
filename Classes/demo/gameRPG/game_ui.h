#ifndef __GAME_UI_H__
#define __GAME_UI_H__

#include "cocos2d.h"

USING_NS_CC;

class VEScrollView;
class GameUILayer : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    // a selector callback
    void menuCallback(CCNode* pSender);

	void scrollTouchHandler(CCObject *pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(GameUILayer);

	// default implements are used to call script callback if exist
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	// default implements are used to call script callback if exist
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);

	CCNode *touchCheck(CCPoint touchPoint);
private:
	VEScrollView *m_scrollview;
};

#endif // __GAME_UI_H__
