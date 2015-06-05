#include "VEScrollView.h"

VEScrollView* VEScrollView::create()
{
	VEScrollView* widget = new VEScrollView();
	if (widget && widget->init())
	{
		widget->autorelease();
		return widget;
	}
	CC_SAFE_DELETE(widget);
	return NULL;
}

bool VEScrollView::init()
{
    if (!CCLayer::init()) return false;

	m_eType = SCROLLVIEW_NONE;

	m_bTouching = false;

	m_fIntensity = 0.f;

	m_scrollBar = NULL;
	m_barScale = 0.f;


	m_contentSize = CCSizeMake(0, 0);

    m_pContainer = CCNode::create();
	this->addChild(m_pContainer);
	this->scheduleUpdate();

	this->setTouchEnabled(true);
	m_bTouchEnabled = true;

	m_touchHandler = NULL;

	return true;
}


void VEScrollView::addCell(CCNode* cell)
{
	m_pContainer->addChild(cell);
	reArrange();
}

void VEScrollView::removeCell(CCNode* cell)
{
	m_pContainer->removeChild(cell,true);
    reArrange();
}

void VEScrollView::removeAllCells()
{
	m_pContainer->removeAllChildren();
}

CCArray* VEScrollView::getAllCells()
{
	return m_pContainer->getChildren();
}

//set the size of the visible region 
void VEScrollView::setViewSize(CCSize size)
{
	m_viewSize = size;

	setContentSize(m_viewSize);

	m_pContainer->setPositionY(0);
}

CCPoint VEScrollView::getContentOffset() const
{
    return m_pContainer->getPosition();
}

void VEScrollView::setContentOffset(CCPoint offset)
{
    m_pContainer->setPosition(offset);
    reArrange();
}

CCRect VEScrollView::boundingBox()
{
	CCRect rect =  CCRectMake(-m_viewSize.width*0.5f,
		-m_viewSize.height*0.5,
		m_viewSize.width,
		m_viewSize.height);
	
	return CCRectApplyAffineTransform(rect, nodeToParentTransform());
}


bool VEScrollView::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint localPoint = (CCPoint)pTouch->getLocation();
	CCRect box = boundingBox();
    if(box.containsPoint(localPoint))
    {
        m_fTouchOffset = 0;
		m_fIntensity = 0.f;
		m_bTouching=true;
		makeScrollBar();
		return false;
	}
    return true;
}

void VEScrollView::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint currPoint = (CCPoint)pTouch->getLocation();
	CCPoint prevPoint = (CCPoint)pTouch->getPreviousLocation();
    
	if(m_bTouching)
    {
		CCPoint offset = currPoint - prevPoint;
		CCPoint pos = m_pContainer->getPosition();

		float scale = 1.f;
		switch (m_eType) {
		case SCROLLVIEW_HORIZONTAL:
			// intensity
			if (pos.x > 0.f) { 
				m_fIntensity = pos.x;
			}else if(pos.x < -(m_contentSize.width-m_viewSize.width)){
				m_fIntensity = abs(pos.x + m_contentSize.width - m_viewSize.width);
			}
			if (m_fIntensity > 0.f ){
				scale = 1.f - m_fIntensity * 2 / m_viewSize.width;
			}
			m_fTouchOffset = offset.x;
			m_pContainer->setPositionX(m_pContainer->getPositionX() + m_fTouchOffset*scale);
			break;
		case SCROLLVIEW_VERTICAL:		
			// intensity
			if (pos.y < 0.f) { 
				m_fIntensity = abs(pos.y);
			}else if(pos.y > m_contentSize.height-m_viewSize.height ){
				m_fIntensity = pos.y - m_contentSize.height+m_viewSize.height;
			}
			if (m_fIntensity > 0.f ){
				scale = 1.f - m_fIntensity * 2 / m_viewSize.height;
			}
			m_fTouchOffset = offset.y;
			m_pContainer->setPositionY(m_pContainer->getPositionY() + m_fTouchOffset*scale);
			break;
		default:
			CCLOG("wrong scroll type");
			break;
		}

	}
}

void VEScrollView::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	if(m_bTouching)
    {
        fadeScrollBar();
        if(m_fTouchOffset != 0)
        {
            float offset = fabsf(m_fTouchOffset);
            m_moveDir = m_fTouchOffset / offset;
            m_fTouchOffset = offset;
        }
        
        m_bTouching = false;

		// single click handle
		CCPoint currPoint = (CCPoint)pTouch->getLocation();
		CCPoint start = pTouch->getStartLocation();
		if (ccpDistance(currPoint, start) < 5){
			// click
			//CCLOG("click (%f, %f)", currPoint.x, currPoint.y);
			touchCheck(currPoint);
		}
    }
}


void VEScrollView::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
    ccTouchBegan((CCTouch*)pTouches->anyObject(), pEvent);
}
void VEScrollView::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
    ccTouchMoved((CCTouch*)pTouches->anyObject(), pEvent);
}
void VEScrollView::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
    ccTouchEnded((CCTouch*)pTouches->anyObject(), pEvent);
}


void VEScrollView::reArrange()
{
	CCArray *children = m_pContainer->getChildren();

	float posX = -m_viewSize.width/2.f;
	float posY = m_viewSize.height/2.f;

	for(int i = 0; i < m_pContainer->getChildrenCount(); i++)
    {
		CCNode *node = (CCNode*)children->objectAtIndex(i);
		CCSize nodeSize = node->getContentSize();
		node->setAnchorPoint(ccp(0.5, 0.5));
		switch (m_eType){
		case SCROLLVIEW_HORIZONTAL:
			node->setPositionX(posX+nodeSize.width/2.f);
			posX += nodeSize.width;
			break;
		case SCROLLVIEW_VERTICAL:
			node->setPositionY(posY-nodeSize.height/2.f);
			posY -= nodeSize.height;
			break;
		default:
			CCLOG("wrong scroll type");
			break;
		}
        //float nodeY = m_pContainer->getPositionY()+h;
        //node->setVisible(nodeY<nodeSize.height && nodeY>-m_viewSize.height);
        //if(dynamic_cast<CCLayer*>(node))
        //   dynamic_cast<CCLayer*>(node)->setTouchEnabled(nodeY<nodeSize.height && nodeY>-m_viewSize.height);

	}


	switch (m_eType){
	case SCROLLVIEW_HORIZONTAL:
		posX += m_viewSize.width/2.f;
		m_contentSize.width = abs(posX);
		m_contentSize.height = m_viewSize.height;
		break;
	case SCROLLVIEW_VERTICAL:
		posY -= m_viewSize.height/2.f;
		m_contentSize.width = m_viewSize.width;
		m_contentSize.height = abs(posY);
		break;
	default:
		CCLOG("wrong scroll type");
		break;
	}
}


void VEScrollView::update(float dt)
{
    if(!m_bTouchEnabled)
        return;
    
	if(!m_bTouching )
    {
		CCPoint pos = m_pContainer->getPosition();
		CCSize gap = m_contentSize - m_viewSize;
		gap.width = MAX(gap.width, 0);
		gap.height = MAX(gap.height, 0);

		switch (m_eType){
		case SCROLLVIEW_HORIZONTAL:
			if (pos.x > 0) {
				easing(0);
				m_fTouchOffset = 0;
			}
			if (pos.x < -gap.width){
				easing(-gap.width);
				m_fTouchOffset = 0;
			}
			if (m_fTouchOffset != 0){
				m_fTouchOffset-=1;
				if(m_fTouchOffset < 0) m_fTouchOffset = 0;
				m_pContainer->setPositionX(m_pContainer->getPositionX() + m_moveDir * m_fTouchOffset);
			}
			break;
		case SCROLLVIEW_VERTICAL:
			if (pos.y < 0) {
				easing(0);
				m_fTouchOffset = 0;
			}
			if (pos.y > gap.height){
				easing(gap.height);
				m_fTouchOffset = 0;
			}
			if (m_fTouchOffset != 0){
				m_fTouchOffset-=1;
				if(m_fTouchOffset < 0 ) m_fTouchOffset = 0;
				m_pContainer->setPositionY(m_pContainer->getPositionY() + m_moveDir * m_fTouchOffset);
			}
			break;
		default:
			CCLOG("wrong scroll type");
			this->unscheduleUpdate();
			break;
		}
       
	}

	if(m_scrollBar && m_scrollBar->getOpacity())
	{
		CCPoint pos = m_pContainer->getPosition();
		CCSize gap = m_contentSize - m_viewSize;
		gap.width = MAX(gap.width, 0);
		gap.height = MAX(gap.height, 0);
		pos.x = MIN(pos.x, 0);
		pos.x = MAX(pos.x, -gap.width);
		pos.y = MAX(pos.y, 0);
		pos.y = MIN(pos.y, gap.height);
		

		static bool bFirstHalf = true;
		float offset = 0.f;
		switch(m_eType){
		case SCROLLVIEW_HORIZONTAL:
			if (pos.x < -gap.width/2 && bFirstHalf){
				bFirstHalf = false;
				m_scrollBar->setAnchorPoint(ccp(1, 0.5f));
				//offset = m_barSize.height;
			}else if(pos.x > -gap.width/2 && !bFirstHalf){
				bFirstHalf = true;
				m_scrollBar->setAnchorPoint(ccp(0, 0.5f));
				//offset = -m_barSize.height;
			}
			if (bFirstHalf)
				m_scrollBar->setPositionX(-m_viewSize.width/2-pos.x*m_barScale - offset);
			else 
				m_scrollBar->setPositionX(-m_viewSize.width/2-pos.x*m_barScale+m_barSize.width - offset);
			break;
		case SCROLLVIEW_VERTICAL:
			if (pos.y > gap.height/2 && bFirstHalf){
				bFirstHalf = false;
				m_scrollBar->setAnchorPoint(ccp(0.5, 0.f));
				//offset = m_barSize.height;
			}else if(pos.y < gap.height/2 && !bFirstHalf){
				bFirstHalf = true;
				m_scrollBar->setAnchorPoint(ccp(0.5, 1.f));
				//offset = -m_barSize.height;
			}
			if (bFirstHalf)
				m_scrollBar->setPositionY(m_viewSize.height/2-pos.y*m_barScale - offset);
			else 
				m_scrollBar->setPositionY(m_viewSize.height/2-pos.y*m_barScale-m_barSize.height - offset);
			break;
		default:
			CCLOG("wrong scroll type");
			break;
		}


		// auto-scale scrollbar
		pos = m_pContainer->getPosition();
		float scale = 1.f;
		switch(m_eType){
		case SCROLLVIEW_HORIZONTAL:
			if (pos.x > 0.f) { 
				scale = 1.f - pos.x/m_viewSize.width;
			}else if(pos.x < -(m_contentSize.width-m_viewSize.width)){
				scale = 1.f - fabsf(pos.x+m_contentSize.width-m_viewSize.width)/m_viewSize.width;
			}
			m_scrollBar->setScaleX(scale);
			break;
		case SCROLLVIEW_VERTICAL:
			if (pos.y < 0.f) {
				scale = 1.f - fabsf(pos.y)/m_viewSize.height;
			}else if(pos.y > m_contentSize.height-m_viewSize.height ){
				scale = 1.f - (pos.y-m_contentSize.height+m_viewSize.height)/m_viewSize.height;
			}
			m_scrollBar->setScaleY(scale);
			break;
		default:
			CCLOG("wrong scroll type");
			break;
		}
	}
	
	//reArrange();
}

void VEScrollView::makeScrollBar()
{
	float scale = 0.f;
	int length_bar = 0;
	switch (m_eType) {
	case SCROLLVIEW_HORIZONTAL:
		scale = m_viewSize.width/m_contentSize.width;
		length_bar = MAX(m_viewSize.width*scale, 30);
		m_barScale = scale - (length_bar-int(m_viewSize.width*scale))/m_contentSize.width;
		break;
	case SCROLLVIEW_VERTICAL:
		scale = m_viewSize.height/m_contentSize.height;
		length_bar = MAX(m_viewSize.height*scale, 30);
		m_barScale = scale - (length_bar-int(m_viewSize.height*scale))/m_contentSize.height;
		break;
	default:
		CCLOG("wrong scroll type");
		break;
	}
    if(scale >= 1)
    {
        if(m_scrollBar) m_scrollBar->setVisible(false);
        return;
    }
	
	switch(m_eType){
	case SCROLLVIEW_HORIZONTAL:
		if(!m_scrollBar)
		{
			m_scrollBar = CCScale9Sprite::create(CCRect(5, 5, 1, 1), "standard/scrollbar_horizontal.png");
			addChild(m_scrollBar, 2);
			m_scrollBar->setAnchorPoint(ccp(0, 0.5));
			m_scrollBar->setPosition(ccp(-m_viewSize.width/2.f, -m_viewSize.height/2.f+6));
		}
		m_scrollBar->setContentSize(CCSize(length_bar, m_scrollBar->getContentSize().height));
		break;
	case SCROLLVIEW_VERTICAL:
		if(!m_scrollBar)
		{
			m_scrollBar = CCScale9Sprite::create(CCRect(5, 5, 1, 1), "standard/scrollbar_vertical.png");
			addChild(m_scrollBar, 2);

			m_scrollBar->setAnchorPoint(ccp(0.5 , 1));
			m_scrollBar->setPosition(ccp(m_viewSize.width/2-6, m_viewSize.height));
		}
		m_scrollBar->setContentSize(CCSize(m_scrollBar->getContentSize().width, length_bar));
		break;
	default:
		CCLOG("wrong scroll type");
		break;
	}

	// store scroll-bar size
	m_barSize = m_scrollBar->getContentSize();

	m_scrollBar->setVisible(true);
	if(m_scrollBar->isRunning())
    {
		m_scrollBar->stopAllActions();
		m_scrollBar->setOpacity(255);
	}

}

void VEScrollView::fadeScrollBar()
{
	CCFiniteTimeAction *fade = CCFadeOut::create(1);
	CCAction *seq = CCSequence::create(fade,
									   NULL);
	if(m_scrollBar)
        m_scrollBar->runAction(seq);
}

//make the visible region
void VEScrollView::visit()
{
    CCDirector *director = CCDirector::sharedDirector();

	CCPoint pos = getPosition();
	CCPoint pos2 = ccp(pos.x - m_viewSize.width*0.5f , pos.y - m_viewSize.height*0.5f);
    
    // apply world transform
	CCPoint wp = getParent()->convertToWorldSpace(pos2);
    
    glEnable(GL_SCISSOR_TEST);
	director->getOpenGLView()->setScissorInPoints(wp.x, wp.y, m_viewSize.width, m_viewSize.height);
    CCLayer::visit();    
    glDisable(GL_SCISSOR_TEST);
}

// easing movement when top or bottom
bool VEScrollView::easing(float target)
{
	CCPoint pos = m_pContainer->getPosition();
	switch (m_eType){
	case SCROLLVIEW_HORIZONTAL:
		m_pContainer->setPositionX(pos.x + (target - pos.x) * 0.2);
		if(fabsf(target - pos.x)<0.1 ){
			m_pContainer->setPositionX(target);
			return true;
		}
		break;
	case SCROLLVIEW_VERTICAL:
		m_pContainer->setPositionY(pos.y + (target - pos.y) * 0.2);
		if(fabsf(target - pos.y)<0.1 ){
			m_pContainer->setPositionY(target);
			return true;
		}
		break;
	default:
		break;
	}
	return false;
}

void VEScrollView::setTouchEnabled(bool val)
{
    m_bTouchEnabled = val;
    CCLayer::setTouchEnabled(m_bTouchEnabled);
    reArrange();
}

//check if any node is clicked.
CCNode *VEScrollView::touchCheck(CCPoint touchPoint)
{
	CCArray *children = m_pContainer->getChildren();

    if(children == NULL)
        return NULL;

	CCPoint np = m_pContainer->convertToNodeSpace(touchPoint);
    for(int i=0; i<children->count(); i++)
    {
        CCNode *node = (CCNode*)children->objectAtIndex(i);
		CCRect box = node->boundingBox();
        if(node->boundingBox().containsPoint(np)){
			CCLOG("click node %d %p\n", i, node);
			if (m_touchListener && m_touchHandler) 
				(m_touchListener->*m_touchHandler)(node);
			return node;
		}
    }

	return NULL;
}