#ifndef __SCENE_BLOOM_H__
#define __SCENE_BLOOM_H__

#include "cocos2d.h"

class SceneBloom : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuBackCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(SceneBloom);

};

#endif // __SCENE_BLOOM_H__
