#ifndef __SCENE_RPG_H__
#define __SCENE_RPG_H__

#include "cocos2d.h"

USING_NS_CC;

class GameBgLayer;
class GameUILayer;
class SceneRPG : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static CCScene* scene();
    
    // implement the "static node()" method manually
    CREATE_FUNC(SceneRPG);

	// default implements are used to call script callback if exist
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	// default implements are used to call script callback if exist
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);

private:
	GameBgLayer *m_bgLayer;
	GameUILayer *m_uiLayer;
};

#endif // __SCENE_RPG_H__
