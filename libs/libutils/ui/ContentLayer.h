/****************************************************************************
	Copyright (c) 2014 , AdamWu calvinmankor@gmail.com
	All rights reserved.

	Use, modification and distribution are subject to the "New BSD License"
    as listed at <url: http://www.opensource.org/licenses/bsd-license.php >.

	COMPANY:  
	CREATED:  2014.09.15
****************************************************************************/

#pragma once

#include "cocos2d.h"

USING_NS_CC;

class ContentLayer : public CCLayer
{
public:
	virtual bool init();
    virtual void setTouchEnabled(bool value);
    
    // default implements are used to call script callback if exist
	virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    
    // default implements are used to call script callback if exist
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    
    virtual void onSingleClick(CCTouch* touch){}
    virtual void onLongClick(CCTouch* touch){}

    
    // Always called when pushing a layer.
    virtual void onEnterAnimationDone(){}

	CREATE_FUNC(ContentLayer);

private:
    CCTouch* currentTouch;
    bool isSingleClick;

    void onPressTimer(float dt);
};

