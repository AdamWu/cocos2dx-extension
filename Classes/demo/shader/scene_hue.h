#ifndef __SCENE_HUE_H__
#define __SCENE_HUE_H__

#include "cocos2d.h"

USING_NS_CC;

class HueSprite;
class SceneHue : public CCLayer
{
public:
    virtual bool init();  

    static CCScene* scene();
    
    // a selector callback
    void menuBackCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(SceneHue);

private:
	HueSprite*	m_pSprite;
};

#endif // __SCENE_HUE_H__
