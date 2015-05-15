#ifndef __SCENE_LASER_H__
#define __SCENE_LASER_H__

#include "cocos2d.h"

USING_NS_CC;

class LaserSprite;
class SceneLaser : public CCLayer
{
public:
    virtual bool init();  

    static CCScene* scene();
    
    // a selector callback
    void menuBackCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(SceneLaser);

private:
	LaserSprite*	m_pLaserSprite;
};

#endif // __SCENE_NORMAL_H__
