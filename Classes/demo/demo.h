#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class CCCursorTextField;
class Demo : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
	// a selector callback
	void menuCallback(CCObject * pSender);
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(Demo);

	virtual void ccKeyboardBegin(unsigned int INparam);
	virtual void ccKeyboardEnd(unsigned int INparam);

	CCCursorTextField	*pTf;
	cocos2d::CCSprite	*m_pSprite;
	cocos2d::CCNode		*m_pLightning;
	std::vector<cocos2d::CCSprite*> m_pSpriteVec;

	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);

private:
	CCPoint m_tBeginPos;
	CCMenu* m_pItemMenu;
};

#endif // __HELLOWORLD_SCENE_H__
