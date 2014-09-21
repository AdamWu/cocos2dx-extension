/****************************************************************************
	Copyright (c) 2014 , AdamWu calvinmankor@gmail.com
	All rights reserved.

	Use, modification and distribution are subject to the "New BSD License"
    as listed at <url: http://www.opensource.org/licenses/bsd-license.php >.

	COMPANY:  
	CREATED:  2014Äê09ÔÂ15ÈÕ
****************************************************************************/
#ifndef __VESCROLLVIEW_H__
#define __VESCROLLVIEW_H__


#include "cocos2d.h"
#include "CCScale9Sprite.h"
#include "ContentLayer.h"

USING_NS_CC;

enum ScrollViewType
{
    Horizontal = 1,
    Vertical,
};

class VEScrollView : public CCLayer
{
public:
	// implement the "static node()"
	CREATE_FUNC(VEScrollView);

public:
	virtual bool init();
	virtual CCRect boundingBox();
    
	void addLayer(CCNode* layer);
    void removeLayer(CCNode* layer);
    void removeAllLayers();
    virtual CCArray* getChildren();
    
	void setViewSize(CCSize size);
	void setViewSize(CCSize size, CCRect actionport);
    
	virtual void reArrange();
	virtual void makeScrollBar();
	void fadeScrollBar();
    void reset();

    // default implements are used to call script callback if exist
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    
    // default implements are used to call script callback if exist
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);

	virtual void visit();
    
    void setTouchEnabled(bool val);
    bool getTouchEnabled() const { return m_bTouchEnabled; }
    
    float getContentY();
    void setContentY(float y);

protected:
	virtual void update(float dt);

	bool easing(float tY);
	CCNode *touchCheck(CCPoint touchPoint);
protected:
	// scroll-view type
	ScrollViewType m_direction;

	// root node
	CCNode* m_pContainer;

	// view size
	CCSize m_viewSize;

	// content size
	CCSize m_contentSize;

	// touch handle
	bool m_bTouching;
    bool m_bTouchEnabled;
	
	// touch start point
	CCPoint	m_tStartPoint;
	// move offset for each touch move 
	float	m_fTouchOffset;
	// move direction  
	int		m_moveDir;

	// elastic intensity offset
	// [0:normal,>0:stretch]
	float	m_fIntensity;

	// scroll bar 
	CCScale9Sprite* m_scrollBar;
	float m_barScale;
	CCSize m_barSize;
};

#endif //__VESCROLLVIEW_H__
