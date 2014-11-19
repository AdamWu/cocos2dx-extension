#include <string>
#include "tinyxml2/tinyxml2.h"
#include "config.h"
#include "game_controller.h"
#include "game_bg.h"
#include "game_ui.h"

USING_NS_CC;

const float GRID_WIDTH = 28;
const float GRID_HEIGHT = 21;

const float MAP_OFFSET_X = 0;
const float MAP_OFFSET_Y = 10;

// calculate the aligned pos for any informal position
CCPoint getCellPos(float x, float y, bool bOdd)
{
	float _x = int((x-MAP_OFFSET_X)/GRID_WIDTH) * GRID_WIDTH + MAP_OFFSET_X;
	float _y = int((y-MAP_OFFSET_Y)/GRID_HEIGHT) * GRID_HEIGHT + MAP_OFFSET_Y;
	if (!bOdd){
		_y -= GRID_HEIGHT/2;
	}
	return ccp(_x, _y);
}

bool GameBgLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	m_root = CCNode::create();
	m_root->setPosition(ccp(winSize.width/2, winSize.height/2));
	this->addChild(m_root);

	CCSprite *bg1 = CCSprite::create("rpg/bg_1.jpg");
	bg1->setPosition(ccp(-bg1->getContentSize().width/2, -bg1->getContentSize().height/2));
	m_root->addChild(bg1);
	CCSprite *bg2 = CCSprite::create("rpg/bg_2.jpg");
	bg2->setPosition(ccp(+bg2->getContentSize().width/2, -bg2->getContentSize().height/2));
	m_root->addChild(bg2);
	CCSprite *bg3 = CCSprite::create("rpg/bg_3.jpg");
	bg3->setPosition(ccp(+bg3->getContentSize().width/2, bg3->getContentSize().height/2));
	m_root->addChild(bg3);
	CCSprite *bg4 = CCSprite::create("rpg/bg_4.jpg");
	bg4->setPosition(ccp(-bg4->getContentSize().width/2, bg4->getContentSize().height/2));
	m_root->addChild(bg4);

	this->setTouchEnabled(true);

	m_eTouchStatus = TOUCH_NONE;

	m_pSelected = NULL;

	// load map
	this->loadMap();

	CCSpriteFrameCache *frameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	frameCache->addSpriteFramesWithFile("rpg/role/role_Wizard.plist");
	CCAnimationCache *animCache = CCAnimationCache::sharedAnimationCache();
	animCache->addAnimationsWithFile("rpg/role/role_Wizard_ani.plist");

	//根据动画定义文件中的名称获取3个动画
	CCAnimation *normal = animCache->animationByName("run");
	normal->setRestoreOriginalFrame(true);


	//创建一个不带纹理的精灵
	CCSprite *grossini = CCSprite::createWithSpriteFrameName("1/run/bpfs_pao_1_00010.png");
	//grossini->setDisplayFrame(frame);
	//grossini->setPosition(ccp(100, 100));
	m_root->addChild(grossini);

	//播放动画
	grossini->runAction(CCRepeatForever::create(CCAnimate::create(normal)));


    return true;
}

void GameBgLayer::addBuilding(Building *pBuilding)
{
	CCSprite *pSprite1;
	char buf[1024];
	BuildingInfo *pInfo = Config::GetInstance()->getBuildingInfo(pBuilding->buildingid);

	pBuilding->size = pInfo->size_map;
	pBuilding->pRes = new CCNode;

	CCNode *pNode = pBuilding->pRes;
	pNode->setAnchorPoint(ccp(0.5, 0.5));
	pNode->setPosition(pBuilding->pos);
	m_root->addChild(pNode);
	// ground
	sprintf(buf, "rpg/ground/%d.png", pInfo->size_map);
	pSprite1 = CCSprite::create(buf);
	pSprite1->setAnchorPoint(ccp(0.5, 0.5));
	pSprite1->setTag(0);
	pNode->addChild(pSprite1);

	// building
	sprintf(buf, "rpg/buildings/%d.png", pBuilding->buildingid);
	pSprite1 = CCSprite::create(buf);
	pSprite1->setTag(1);
	pSprite1->setAnchorPoint(pInfo->anchor_point);
	pNode->addChild(pSprite1);
}

void GameBgLayer::addBuildingNew(int buildingid)
{
	Building *pBuilding = new Building;
	pBuilding->buildingid = buildingid;
	pBuilding->pos = ccp(0, 0);

	this->addBuilding(pBuilding);
	this->select(pBuilding);

	m_eTouchStatus = TOUCH_PICK;
	m_items.push_back(pBuilding);
}

void GameBgLayer::select(Building *pBuilding)
{		
	CCLOG("selected %p %d\n", pBuilding, pBuilding->buildingid);

	if (m_pSelected) {
		if (m_pSelected == pBuilding) 
			return;
		else{
			m_pSelected->pRes->setZOrder(0);
			CCSprite *land = (CCSprite*)m_pSelected->pRes->getChildByTag(0);
			if (land) land->removeAllChildren();
		}
	}
	m_pSelected = pBuilding;
	m_pSelected->pRes->setZOrder(100);

	char buf[1024];
	BuildingInfo *pInfo = Config::GetInstance()->getBuildingInfo(pBuilding->buildingid);

	CCNode *pNode = pBuilding->pRes;
	CCSprite *land = (CCSprite*)m_pSelected->pRes->getChildByTag(0);
	
	// warning color
	sprintf(buf, "rpg/ground_grid/e%d.png", pInfo->size_map);
	CCSprite *pSprite2 = CCSprite::create(buf);
	pSprite2->setPosition(ccp(land->getContentSize().width/2, land->getContentSize().height/2));
	land->addChild(pSprite2);

	sprintf(buf, "rpg/ground_arrow/%d.png", pInfo->size_map);
	pSprite2 = CCSprite::create(buf);
	pSprite2->setPosition(ccp(land->getContentSize().width/2, land->getContentSize().height/2));
	land->addChild(pSprite2);
}

// check if touch a building
Building * GameBgLayer::pickup(CCPoint pos)
{
	Building *pBuilding = NULL;
	CCPoint np = m_root->convertToNodeSpace(pos);
	for(std::vector<Building*>::iterator iter = m_items.begin(); iter != m_items.end(); ++ iter)
	{
		CCNode *node = (*iter)->pRes;
		CCRect box = node->boundingBox();
		pos = np - box.origin;
		if(pos.x+pos.y > -70 && pos.x+pos.y<70 && pos.x-pos.y>-70 && pos.x-pos.y<70){
			pBuilding = *iter;
		}
	}

	return pBuilding;
}

// check the collision btw buildings
bool GameBgLayer::collide(CCNode *pItem)
{
	CCNode *pNode = NULL;
	CCPoint np = pItem->getPosition();
	for(std::vector<Building*>::iterator iter = m_items.begin(); iter != m_items.end(); ++ iter)
	{
		CCNode *pNode = (*iter)->pRes;
		if (pItem != pNode){
			CCRect box = pNode->boundingBox();
			CCPoint pos = np - box.origin;
			if(pos.x*pos.x+pos.y*pos.y < 141*141){
				// more check collide
				return true;
			}
		}
	}
	
	return false;
}

struct cc_timeval tv;
static CCPoint pos_start;
static bool bTouchMap = true;
bool GameBgLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLOG("ccTouchBegan, status %d", m_eTouchStatus);
	CCPoint localPoint = convertTouchToNodeSpace(pTouch);

	CCTime::gettimeofdayCocos2d(&tv, NULL);

	pos_start = (CCPoint)pTouch->getLocation();

	CCArray *children = this->getChildren();
	bTouchMap = GameController::GetInstance()->getUILayer()->touchCheck(localPoint) == NULL? true:false;
	if (bTouchMap){
		Building* pBuilding = this->pickup(localPoint);
		if (pBuilding && pBuilding == m_pSelected){
			m_eTouchStatus = TOUCH_PICK;
			return true;
		}
		// remove select
		if (m_pSelected) {
			CCNode *pNode = m_pSelected->pRes->getChildByTag(0);
			if (pNode){
				pNode->removeAllChildren();
			}
			m_pSelected = NULL;
		}

		// touch map
		m_eTouchStatus = TOUCH_DRAG;
	}
	return true;
}

void GameBgLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	if (!bTouchMap) return;

	CCLOG("ccTouchMoved, status %d", m_eTouchStatus);
	CCPoint currPoint = (CCPoint)pTouch->getLocation();
	CCPoint prevPoint = (CCPoint)pTouch->getPreviousLocation();
	
	CCPoint pos;

	switch (m_eTouchStatus){
	case TOUCH_NONE:
		break;
	case TOUCH_DRAG:
		pos = m_root->getPosition();
		{
			CCSize winSize = CCDirector::sharedDirector()->getWinSize();
			CCPoint dst = ccp(pos.x+currPoint.x-prevPoint.x,pos.y+currPoint.y-prevPoint.y);
			dst.x = max(dst.x, winSize.width/2-160);
			dst.x = min(dst.x, winSize.width/2+160);
			dst.y = max(dst.y, winSize.height/2-192);
			dst.y = min(dst.y, winSize.height/2+192);
			m_root->setPosition(dst);
		}
		break;
	case TOUCH_ADD:
		break;
	case TOUCH_PICK:
		if (m_pSelected) {
			pos = m_root->getPosition();
			m_pSelected->pRes->setPosition(getCellPos(currPoint.x-pos.x, currPoint.y-pos.y, m_pSelected->size%2==0));
		}
		break;
	default:
		break;
	}
}

void GameBgLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	if (!bTouchMap) return;

	CCLOG("ccTouchEnded, status %d", m_eTouchStatus);

	CCPoint currPoint = (CCPoint)pTouch->getLocation();

	CCPoint pos;

	switch (m_eTouchStatus) {
	case TOUCH_NONE:
		break;
	case TOUCH_DRAG:	
		struct cc_timeval tmp;
		CCTime::gettimeofdayCocos2d(&tmp, NULL);
		if (tmp.tv_sec - tv.tv_sec < 0.1){
			// pick item
			Building *pPick = this->pickup(currPoint);
			if (pPick) {
				this->select(pPick);
			} else{
				m_eTouchStatus = TOUCH_NONE;
				m_pSelected = NULL;
			}
		} else {
			m_eTouchStatus = TOUCH_NONE;
			m_pSelected = NULL;
		}
		break;
	case TOUCH_ADD:
		/*
		if (m_pSelected){
			pNode = m_pSelected->pRes->getChildByTag(0);
			if (pNode){
				pNode->removeAllChildren();
			}
			
			// save to map
			this->saveMap();
		}
		m_eTouchStatus = TOUCH_NONE;
		m_pSelected = NULL;
		*/
		break;
	case TOUCH_PICK:
		// save to map
		this->saveMap();
		break;
	default:
		m_eTouchStatus = TOUCH_NONE;
		m_pSelected = NULL;
		break;
	}

}

void GameBgLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	ccTouchBegan((CCTouch*)pTouches->anyObject(), pEvent);
}

void GameBgLayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	ccTouchMoved((CCTouch*)pTouches->anyObject(), pEvent);
}

void GameBgLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	ccTouchEnded((CCTouch*)pTouches->anyObject(), pEvent);
}

bool GameBgLayer::loadMap()
{
	tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();

	tinyxml2::XMLError error = pDoc->LoadFile("map.xml");

	if (error != tinyxml2::XML_SUCCESS) {
		delete pDoc;
		return false;
	}
	
	// load map data
	tinyxml2::XMLElement *root = pDoc->RootElement();
	tinyxml2::XMLElement *pElement = root->FirstChildElement();
	while (pElement){
		const char *value = pElement->Attribute("id");
		Building *pBuilding = new Building;
		pBuilding->buildingid = atoi(value);
		pBuilding->pos.x = atof(pElement->Attribute("x"));
		pBuilding->pos.y = atof(pElement->Attribute("y"));
		m_items.push_back(pBuilding);

		this->addBuilding(pBuilding);
		
		// next
		pElement = pElement->NextSiblingElement();
	}

	delete pDoc;

	return true;
}

bool GameBgLayer::saveMap()
{
	tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument;

	tinyxml2::XMLDeclaration *pDel = pDoc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");
	pDoc->LinkEndChild(pDel);

	tinyxml2::XMLElement *root = pDoc->NewElement("root");
	pDoc->LinkEndChild(root);

	for (std::vector<Building*>::iterator it = m_items.begin(); it != m_items.end(); ++it){
		tinyxml2::XMLElement *pElement = pDoc->NewElement("building");
		root->LinkEndChild(pElement);
		pElement->SetAttribute("id", (*it)->buildingid);
		pElement->SetAttribute("x", (*it)->pRes->getPositionX());
		pElement->SetAttribute("y", (*it)->pRes->getPositionY());
	}

	tinyxml2::XMLError error = pDoc->SaveFile("map.xml");

	delete pDoc;

	return error == tinyxml2::XML_SUCCESS;
}