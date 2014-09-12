#ifndef __SCENE_BLIND_H__
#define __SCENE_BLIND_H__

#include "cocos2d.h"

class SceneBlind : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuBackCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(SceneBlind);

};

#endif // __SCENE_BLIND_H__
