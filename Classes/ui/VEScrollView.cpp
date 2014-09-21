#include "VEScrollView.h"


bool VEScrollView::init()
{
    if (!CCLayer::init()) return false;

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

	return true;
}


void VEScrollView::addLayer(CCNode* layer)
{
	m_pContainer->addChild(layer);
	reArrange();
}

void VEScrollView::removeLayer(CCNode* view)
{
	m_pContainer->removeChild(view,true);
    reArrange();
}

void VEScrollView::removeAllLayers()
{
	m_pContainer->removeAllChildren();
}

CCArray* VEScrollView::getChildren()
{
    return m_pContainer->getChildren();
}

//set the size of the visible region 
void VEScrollView::setViewSize(CCSize size)
{
	m_viewSize = size;

	m_pContainer->setPositionY(0);
}

float VEScrollView::getContentY()
{
    return m_pContainer->getPositionY();
}

void VEScrollView::setContentY(float y)
{
    m_pContainer->setPositionY(y);
    reArrange();
}

void VEScrollView::reset()
{
    m_pContainer->setPositionY(0);
}

CCRect VEScrollView::boundingBox()
{
	return CCRectMake(-m_viewSize.width*0.5f,
                      -m_viewSize.height*0.5,
                      m_viewSize.width,
                      m_viewSize.height);
}


bool VEScrollView::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCPoint localPoint = convertTouchToNodeSpace(pTouch);
    if(boundingBox().containsPoint(localPoint))
    {
        m_fTouchOffset = 0;
		m_fIntensity = 0.f;
		m_bTouching=true;
		makeScrollBar();
	}
    return true;
}

void VEScrollView::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint currPoint = (CCPoint)pTouch->getLocation();
	CCPoint prevPoint = (CCPoint)pTouch->getPreviousLocation();
    
	if(m_bTouching)
    {
		m_fTouchOffset = currPoint.y - prevPoint.y;
		
		// intensity
		float curPos = m_pContainer->getPositionY();
		if (curPos < 0.f) { 
			m_fIntensity = abs(curPos);
		}else if(curPos > m_contentSize.height-m_viewSize.height ){
			m_fIntensity = curPos - m_contentSize.height+m_viewSize.height;
		}
	
		float scale = 1.f;
		if (m_fIntensity > 0.f ){
			scale = 1.f - m_fIntensity * 2 / m_viewSize.height;
		}
		m_pContainer->setPositionY(m_pContainer->getPositionY() + m_fTouchOffset*scale);
	}
}

void VEScrollView::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	if(m_bTouching)
    {
        fadeScrollBar();
        if(m_fTouchOffset != 0)
        {
            float offset = std::abs(m_fTouchOffset);
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

	float h = m_viewSize.height/2.f;

	for(int i = 0; i < m_pContainer->getChildrenCount(); i++)
    {
		CCNode *node = (CCNode*)children->objectAtIndex(i);
		CCSize nodeSize = node->getContentSize();
		node->setAnchorPoint(ccp(0.5, 0.5));
		node->setPositionY(h-nodeSize.height/2.f);
        //float nodeY = m_pContainer->getPositionY()+h;
        //node->setVisible(nodeY<nodeSize.height && nodeY>-m_viewSize.height);
        //if(dynamic_cast<CCLayer*>(node))
        //   dynamic_cast<CCLayer*>(node)->setTouchEnabled(nodeY<nodeSize.height && nodeY>-m_viewSize.height);

		h -= nodeSize.height;
	}
	
	h -= m_viewSize.height/2.f;

	m_contentSize.width = m_viewSize.width;
	m_contentSize.height = abs(h);
}


void VEScrollView::update(float dt)
{
    if(!m_bTouchEnabled)
        return;
    
	if(!m_bTouching )
    {
		if(m_pContainer->getPositionY() < 0)
        {
			easing(0);
			m_fTouchOffset = 0;
		}

		float gap = m_contentSize.height - m_viewSize.height; 
		gap = max(gap, 0);
		if(m_pContainer->getPositionY() > gap)
		{
			easing(gap);
			m_fTouchOffset = 0;
		}
        
		if(m_fTouchOffset != 0)
        {
			m_fTouchOffset-=1;
			if(m_fTouchOffset < 0 ) m_fTouchOffset = 0;
			m_pContainer->setPositionY(m_pContainer->getPositionY() + m_moveDir * m_fTouchOffset);
		}
	}

	if(m_scrollBar && m_scrollBar->getOpacity())
	{
		float gap = m_contentSize.height - m_viewSize.height; 
		gap = max(gap, 0);

		float p = m_pContainer->getPositionY();
		if(p < 0)
			p = 0;		
		else if(p > gap)
			p = gap;

		static bool bFirstHalf = true;
		float offset = 0.f;
		if (p > gap/2 && bFirstHalf){
			bFirstHalf = false;
			m_scrollBar->setAnchorPoint(ccp(0.5, 0.f));
			offset = m_barSize.height;
		}else if(p < gap/2 && !bFirstHalf){
			bFirstHalf = true;
			m_scrollBar->setAnchorPoint(ccp(0.5, 1.f));
			offset = -m_barSize.height;
		}
		if (bFirstHalf)
			m_scrollBar->setPositionY(m_viewSize.height/2-p*m_barScale - offset);
		else 
			m_scrollBar->setPositionY(m_viewSize.height/2-p*m_barScale-m_barSize.height - offset);

		float scale = 1.f;
		float curPos = m_pContainer->getPositionY();
		if (curPos < 0.f) { 
			scale = 1.f - abs(curPos)/m_viewSize.height;
		}else if(curPos > m_contentSize.height-m_viewSize.height ){
			scale = 1.f - (curPos-m_contentSize.height+m_viewSize.height)/m_viewSize.height;
		}

		m_scrollBar->setScaleY(scale);
	}
	
	//reArrange();
}

void VEScrollView::makeScrollBar()
{
	float actionHeight = m_viewSize.height;
	float scale = actionHeight / m_contentSize.height;
    if(scale >= 1)
    {
        if(m_scrollBar) m_scrollBar->setVisible(false);
        return;
    }
    m_barScale = scale;
	int barHeight = max(int(actionHeight*m_barScale) , 30);
	m_barScale = scale - (barHeight-int(actionHeight*m_barScale))/ m_contentSize.height;
	
	if(!m_scrollBar)
    {
		m_scrollBar = CCScale9Sprite::create(CCRect(5, 5, 1, 1), "scrollbar.png");
		m_scrollBar->setAnchorPoint(ccp(0.5 , 1));
        
        CCSize winSize = CCEGLView::sharedOpenGLView()->getVisibleSize();
		m_scrollBar->setPosition(ccp(m_viewSize.width/2-20, m_viewSize.height));
		addChild(m_scrollBar , 2);
	}
    
	if(m_scrollBar->isRunning())
    {
		m_scrollBar->stopAllActions();
		m_scrollBar->setOpacity(255);
	}
	m_scrollBar->setContentSize(CCSize(m_scrollBar->getContentSize().width, barHeight));
	m_scrollBar->setVisible(true);
	m_barSize = m_scrollBar->getContentSize();
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
	float curPosY = m_pContainer->getPositionY();
	m_pContainer->setPositionY( curPosY + (target - curPosY) * 0.2);

	if(std::abs(target - m_pContainer->getPositionY())<0.1 ){
		m_pContainer->setPositionY(target);
		return true;
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

	CCPoint pos = this->convertToNodeSpace(touchPoint);
	CCPoint np = m_pContainer->convertToNodeSpace(touchPoint);
    for(int i=0; i<children->count(); i++)
    {
        CCNode *node = (CCNode*)children->objectAtIndex(i);
		CCRect box = node->boundingBox();
        if(node->boundingBox().containsPoint(np)){
			CCLOG("click node %d %p", i, node);
			return node;
		}
    }

	return NULL;
}