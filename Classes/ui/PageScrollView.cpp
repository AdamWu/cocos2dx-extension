#include "PageScrollView.h"
#include "Utils.h"

#define PI 3.1415926

USING_NS_CC;

PageScrollView::~PageScrollView()
{
    
    this->unscheduleUpdate();
}

bool PageScrollView::init(CCSize page , bool isShowOne)
{
	if(!ContentLayer::init())
        return false;

	this->page = page;
	touchPort = CCRect( -page.width , 0 , page.width*2 , page.height );
	setTouchEnabled(true);
	v = 0;
	v0 = 0;
	a = 6;
    moveTargetId = 0;
    viewPort = touchPort;
    this->isShowOne = isShowOne;
    isHomePage = false;

	targetPos = currentPos = 0;
	isTouchMoving = false;
	currentNodeId = 0;
    currIdCashe = -1;
    
    //callBack = [](CCSprite *node){};

	content = ContentLayer::create();
	addChild(content);

    
	return true;  
}

bool PageScrollView::initWithSprite(const std::vector<cocos2d::CCSprite *> &childNodes, cocos2d::CCSize page, bool isShowOne)
{
    if(!init(page , isShowOne))return false;
    
    //nodes = childNodes;
	size = childNodes.size();
	for(int i = 0 ; i < size ; i++){
		childNodes[i]->setAnchorPoint(ccp(0.5 , 0));
		childNodes[i]->setPosition(ccp(i*page.width , 0));
		if(isShowOne)childNodes[i]->setOpacity(0);
		content->addChild(childNodes[i]);
        nodes[i] = childNodes[i];
	}
    
    
    
	this->scheduleUpdate();
    
    return true;
}



void PageScrollView::setViewPort(cocos2d::CCRect value)
{
    this->viewPort = value;
}

CCRect PageScrollView::getViewPort()
{
    return viewPort;
}

void PageScrollView::setCurrentNode(int nodeId)
{
	content->setPositionX(-nodeId*page.width);
	nodes[nodeId]->setOpacity(255);
    moveTargetId = nodeId;
}

void PageScrollView::setMoveTargetId(int id)
{
    assert(id >= 0 && id <= size-1 && "id should be in the valid range");
    //this flag is to control if excute callBack
    isViewStop = false;
    moveTargetId = id;
}

void PageScrollView::onSettle()
{
    
}

double round(double num) {
	return (num > 0.0) ? floor(num + 0.5) : ceil(num - 0.5);
}

int PageScrollView::getCurrentNodeId()
{
	float pos = content->getPositionX();
    float t = -pos/page.width;
    int id = round(t);
    endNodeIndex = isHomePage ? size-1 : size - int(viewPort.size.width/page.width);
    id = id > 0 ? (id < endNodeIndex ? id : endNodeIndex) : 0;
    
	return id;
}

int PageScrollView::getTargetPos()
{
	return -page.width*moveTargetId;
}

/*
void PageScrollView::setCallBack(boost::function<void (cocos2d::CCSprite*)> callBack)
{
	this->callBack = callBack;
}
*/

void PageScrollView::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	CCTouch *touch = (CCTouch*)pTouches->anyObject();
	CCPoint point = convertTouchToNodeSpace(touch);

	if(viewPort.containsPoint(point)){
		isTouchMoving = true;
		isViewStop = false;
	}
	
}
void PageScrollView::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	CCTouch *touch = (CCTouch *)pTouches->anyObject();
	CCPoint currentPoint = (CCPoint)touch->getLocation();
	CCPoint prePoint = (CCPoint)touch->getPreviousLocation();

	if(isTouchMoving){
		v = currentPoint.x - prePoint.x;
		content->setPositionX(content->getPositionX() + v);
	}
	
}
void PageScrollView::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	
	if(isTouchMoving){
		//std::cout<<"targetPos"<<targetPos<<std::endl;
		isTouchMoving = false;

        v0 = abs(v);
        if(v0 > 6)
        {
            direction = v/v0;
            moveTargetId = MAX(0, MIN(getCurrentNodeId()-direction , size-1));
        }
        else
            moveTargetId = getCurrentNodeId();
        v = 0;
	}
		
}

void PageScrollView::update(float dt)
{
    if(!isTouchMoving){
        int currId = getCurrentNodeId();
        if(easing(content , getTargetPos()) && currIdCashe != currId)
        {
            //callBack(nodes[currId]);
            currIdCashe = currId;
        }
	}

	if(isShowOne && !isViewStop){
        for(std::map<int, cocos2d::CCSprite*>::iterator it = nodes.begin() ; it != nodes.end() ; it++)
            it->second->setOpacity(0);
        
		float tp = -page.width*getCurrentNodeId();
		float cp = content->getPositionX();
		float temp = abs(tp - cp)/page.width;
        int id = getCurrentNodeId();
		nodes[id]->setOpacity(255*(1-temp));
		if(id < size-1 && cp < tp)nodes[id+1]->setOpacity(255*temp);
		if(id > 0 && cp > tp)nodes[id-1]->setOpacity(255*temp);
	}
}

void PageScrollView::visit()
{
    CCDirector *director = CCDirector::sharedDirector();
    
	float n_width = viewPort.size.width ;
    float n_height = viewPort.size.height ;
    
	CCPoint pos = getPosition();
	CCPoint pos2 = ccp(pos.x + viewPort.origin.x , pos.y+viewPort.origin.y);
    
    // apply world transform
	CCPoint temp = getParent()->convertToWorldSpace(pos2);
    
    float x = temp.x;
    float y = temp.y;
    
    glEnable(GL_SCISSOR_TEST);
	director->getOpenGLView()->setScissorInPoints(x, y, n_width, n_height);
    CCLayer::visit();
    glDisable(GL_SCISSOR_TEST);
}




bool ScrollMenu::init(std::vector<CCSprite*> nodes)
{
    isTouchable = true;
    btns = nodes;
    
    arrowColor = GetSprite("gameui/fangxiang_daohang.png");
    addChild(arrowColor);
    arrowGray = GetSprite("gameui/fangxiang_daohang2.png");
    addChild(arrowGray);
    
    std::vector<CCSprite*> btnsToScroll;
    for(int i = 0; i < btns.size(); i ++)
    {
		CCSprite *btn = btns[i];
        cocos2d::CCSprite* btnBg = GetSprite("gameui/yuandi.png");
        btn->setPosition(ccp(btnBg->getContentSize().width*0.5f, btnBg->getContentSize().height*0.5f));
        btnBg->addChild(btn);
        btnsToScroll.push_back(btnBg);
    }
    
    scrollView  = PageScrollView::create(btnsToScroll,CCSizeMake(110, 100),false);
    scrollView->setViewPort(CCRectMake(-60, 0, 550, 120));
    scrollView->setPositionX(45);
    addChild(scrollView);
    
    scrollView->setTouchEnabled(false);
    
    menuLeft();
    
    return true;
}

void ScrollMenu::menuLeft()
{
    arrowColor->setFlipX(false);
    arrowColor->setPosition(ccp(560,50));
    arrowGray->setFlipX(false);
    arrowGray->setPosition(ccp(-40, 50));
}

void ScrollMenu::menuRight()
{
    arrowColor->setFlipX(true);
    arrowColor->setPosition(ccp(-40,50));
    arrowGray->setFlipX(true);
    arrowGray->setPosition(ccp(560, 50));
}

void ScrollMenu::setScrollEnabled(bool value)
{
    if (isTouchable != value)
    {
        isTouchable = value;
        if (m_bRunning)
        {
            if (value)
            {
                CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,-200, false);
            }
            else
            {
                CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
            }
        }
    }
}

void ScrollMenu::setTouchEnabled(bool value)
{
	for(int i = 0; i < btns.size(); i ++)
	{
		CCSprite *btn = btns[i];
        //btn->setTouchEnabled(value);
	}
    
    //setScrollEnabled(value);
}

/* 触摸相关 */
void ScrollMenu::onEnter()
{
    CCNode::onEnter();
    if(isTouchable)
        CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,-128, false);
    
}

void ScrollMenu::onExit()
{
    CCNode::onExit();
    if(isTouchable)
        CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool ScrollMenu::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCSet set;
    set.addObject(pTouch);
    scrollView->ccTouchesBegan(&set, pEvent);
    return true;
}
// optional

void ScrollMenu::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    CCSet set;
    set.addObject(pTouch);
    scrollView->ccTouchesMoved(&set, pEvent);
}

void ScrollMenu::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    CCSet set;
    set.addObject(pTouch);
    scrollView->ccTouchesEnded(&set, pEvent);
    if(scrollView->getCurrentNodeId() == 0)
        menuLeft();
    else if(scrollView->getCurrentNodeId() == scrollView->endNodeIndex)
        menuRight();
}

void ScrollMenu::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    CCSet set;
    set.addObject(pTouch);
    scrollView->ccTouchesCancelled(&set, pEvent);
}

