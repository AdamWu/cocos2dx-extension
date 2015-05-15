#ifndef __SCENE_RIPPLE_H__
#define __SCENE_RIPPLE_H__

#include "cocos2d.h"

USING_NS_CC;

class RippleSprite;
class SceneRipple : public CCLayer
{
public:
    virtual bool init();  

    static CCScene* scene();
    
    // a selector callback
    void menuBackCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(SceneRipple);

private:
	RippleSprite*	m_pSprite;
};

#endif // __SCENE_RIPPLE_H__
