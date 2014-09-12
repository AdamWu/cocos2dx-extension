#ifndef __SCENE_STREAM_H__
#define __SCENE_STREAM_H__

#include "cocos2d.h"

class SceneStream : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuBackCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(SceneStream);

};

#endif // __SCENE_STREAM_H__
