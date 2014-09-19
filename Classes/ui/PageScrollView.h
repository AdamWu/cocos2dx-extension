/****************************************************************************
	Copyright (c) 2014 , AdamWu calvinmankor@gmail.com
	All rights reserved.

	Use, modification and distribution are subject to the "New BSD License"
    as listed at <url: http://www.opensource.org/licenses/bsd-license.php >.

	COMPANY:  
	CREATED:  2014年09月15日
****************************************************************************/

#pragma once 

#include "ContentLayer.h"
#include "cocos2d.h"

namespace PH
{
    struct Hero;
}


class PageScrollView : public ContentLayer
{
public:
    int endNodeIndex;
    bool isHomePage;
    int size;
    
	~PageScrollView();

    ContentLayer *content;
    bool isShowOne;

	bool init(cocos2d::CCSize page , bool isShowOne);
    bool initWithSprite(const std::vector<cocos2d::CCSprite*>& childNodes , cocos2d::CCSize page , bool isShowOne);
	virtual void setCurrentNode(int nodeId);
    virtual void setMoveTargetId(int id);
    virtual void onSettle();
	int getTargetPos();
	//void setCallBack(boost::function<void (cocos2d::CCSprite*)> callBack);
	virtual int getCurrentNodeId();
    void setViewPort(cocos2d::CCRect value);
    CCRect getViewPort();

	virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);


	virtual void update(float dt);
    virtual void visit();

	static PageScrollView *create(const std::vector<cocos2d::CCSprite*> &nodes , cocos2d::CCSize page , bool isShowOne = true)
	{
		PageScrollView* o = new PageScrollView();
		if(o != NULL && o->initWithSprite(nodes , page , isShowOne))
		{
			o->autorelease();
			return o;
		}
		CC_SAFE_DELETE(o);
		return NULL;
	};

protected:
    std::map<int, cocos2d::CCSprite*> nodes;
    std::vector<PH::Hero*> heroes;
	cocos2d::CCSize page;
    cocos2d::CCRect viewPort;
	int v;
	int a;
	int v0;
	int direction;
    
	cocos2d::CCRect touchPort;
	int currentPos;
	int targetPos;
	int currentNodeId;
    int moveTargetId;
    int currIdCashe;

	bool isTouchMoving;
	bool isViewStop;
	
	//boost::function<void (cocos2d::CCSprite*)> callBack;
};

class ScrollMenu : public CCNode, public CCTouchDelegate
{
public:
    
    virtual bool init(std::vector<CCSprite*> nodes);
    
    void menuLeft();
    void menuRight();
    
    void setTouchEnabled(bool value);
    void setScrollEnabled(bool value);
    
    /* 触摸相关 */
    virtual void onEnter();
    virtual void onExit();
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    // optional
    
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
    static ScrollMenu *create(std::vector<CCSprite*> nodes)
	{
		ScrollMenu* o = new ScrollMenu();
		if(o != NULL && o->init(nodes))
		{
			o->autorelease();
			return o;
		}
		CC_SAFE_DELETE(o);
		return NULL;
	};
    
private:
    PageScrollView* scrollView;
    CCSprite* arrowColor;
    CCSprite* arrowGray;
    bool isTouchable;
    std::vector<CCSprite*> btns;
    CCRect touchRegion;
};



