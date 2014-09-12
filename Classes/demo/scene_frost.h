#ifndef __SCENE_FROST_H__
#define __SCENE_FROST_H__

#include "cocos2d.h"

class SceneFrost : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuBackCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(SceneFrost);

};

#endif // __SCENE_FROST_H__
