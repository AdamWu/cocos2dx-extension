#ifndef __SCENE_NORMAL_H__
#define __SCENE_NORMAL_H__

#include "cocos2d.h"

USING_NS_CC;

class NormalSprite;
class SceneNormal : public CCLayer
{
public:
    virtual bool init();  

    static CCScene* scene();
    
    // a selector callback
    void menuBackCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(SceneNormal);

	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);

private:
	NormalSprite*	m_pNormalSprite;
};

#endif // __SCENE_NORMAL_H__
