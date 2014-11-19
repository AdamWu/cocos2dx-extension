#ifndef __SCENE_UI_H__
#define __SCENE_UI_H__

#include "cocos2d.h"

class SceneUI : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuBackCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(SceneUI);

};

#endif // __SCENE_BLIND_H__
