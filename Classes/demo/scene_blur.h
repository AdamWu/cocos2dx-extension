#ifndef __SCENE_BLUR_H__
#define __SCENE_BLUR_H__

#include "cocos2d.h"

class SceneBlur : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuBackCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(SceneBlur);

};

#endif // __SCENE_BLUR_H__
