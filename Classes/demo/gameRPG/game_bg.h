#ifndef __GAME_BG_H__
#define __GAME_BG_H__

#include "cocos2d.h"

USING_NS_CC;

enum TOUCH_STATUS 
{
	TOUCH_NONE = 0,		// no opt
	TOUCH_DRAG,			// drag the map
	TOUCH_ADD,			// add a new item
	TOUCH_PICK,			// pick a item in the map
	TOUCH_MULTI,
};

// building info
typedef struct{
	int buildingid;
	int size;
	CCPoint pos;
	CCNode *pRes;
}Building;


class GameBgLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();  
    
    CREATE_FUNC(GameBgLayer);

	// default implements are used to call script callback if exist
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	// default implements are used to call script callback if exist
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);


	void select(Building *pBuilding);
	void addBuilding(Building *pBuilding);
	void addBuildingNew(int buildingid);
	Building * pickup(CCPoint pos);
	
	bool collide(CCNode *pItem);
	
protected:
	bool loadMap();
	bool saveMap();

private:
	CCNode *m_root;
	TOUCH_STATUS m_eTouchStatus;

	std::vector<Building*>	m_items;
	Building *m_pSelected;
};

#endif // __GAME_BG_H__
