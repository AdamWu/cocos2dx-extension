#include "CCCursorTextField.h"
#include "CCGL.h"

const static float DELTA = 10.0f;
static int cursorHeight = 20;
const int column = 2;


static int _calcCharCount(const char * pszText)
{
	int n = 0;
	char ch = 0;
	while ((ch = *pszText))
	{
		CC_BREAK_IF(! ch);

		if (0x80 != (0xC0 & ch))
		{
			++n;
		}
		++pszText;
	}
	return n;
}


CCCursorTextField::CCCursorTextField():
	m_pCursorSprite(NULL),
	m_pCursorAction(NULL),
	m_sFontName(""),
	m_fFontSize(0),
	m_pInputText(""),
	m_nMaxBytes(0),
	m_nInputBytes(0)
{
	CCTextFieldTTF();
}


CCCursorTextField::~CCCursorTextField()
{
	
}


void CCCursorTextField::initCursorSprite()
{
	cursorHeight = m_fFontSize * 4;
	//int pixels[cursorHeight][column];
	int **pixels = (int **)malloc(cursorHeight*sizeof(int*));
	for (int i=0; i<cursorHeight; ++i) {
		pixels[i] = (int*)malloc(column*sizeof(int));
		for (int j=0; j<column; ++j) {
			pixels[i][j] = 0xffffffff;
		}
	}
	
	CCTexture2D *texture = new CCTexture2D();
	texture->initWithData(pixels, kCCTexture2DPixelFormat_RGB888, 1, 1, CCSizeMake(column, cursorHeight));

	//m_pCursorSprite = CCScale9Sprite::create("cursor.png", CCRectMake(1, 1, 4, 4));
	//m_pCursorSprite->setPreferredSize(CCSizeMake(2,m_fFontSize));

	m_pCursorSprite = CCSprite::createWithTexture(texture); 

	CCSize winSize = getContentSize();
	m_pCursorSprite->setAnchorPoint(ccp(0,1));
	m_aCursorPos = ccp(0, winSize.height);
	m_pCursorSprite->setPosition(m_aCursorPos);
	this->addChild(m_pCursorSprite);

	m_pCursorAction = CCRepeatForever::create((CCActionInterval *) CCSequence::create(CCFadeOut::create(0.25f), CCFadeIn::create(0.25f), NULL));

	m_pCursorSprite->runAction(m_pCursorAction);

	m_pCursorSprite->setVisible(false);

	this->setDelegate(this);
}


CCCursorTextField * CCCursorTextField::textFieldWithPlaceHolder(const char *placeholder, 
													 const char *fontName, 
													 float fontSize,
													 CCSize aContentSize)
{
	CCCursorTextField *pRet = new CCCursorTextField();

	if(pRet && pRet->initWithString("", fontName, fontSize))
	{
		pRet->m_sFontName = fontName;
		pRet->m_fFontSize = fontSize;
		pRet->setDimensions(aContentSize);
		pRet->m_fContentHeight = aContentSize.height;
		pRet->autorelease();
		if (placeholder)
		{
			pRet->setPlaceHolder(placeholder);
		}
		pRet->initCursorSprite();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);

	return NULL;
}


CCSize CCCursorTextField::getTextDimension(const char *text)
{
	CCLabelTTF *label = CCLabelTTF::create( text,m_sFontName.c_str(),m_fFontSize );
	return label->getContentSize();
}


void CCCursorTextField::setText( const char *pText )
{
	m_pInputText = pText ;
	setString(pText);
	CCSize winSize = getContentSize();
	m_aCursorPos = ccp(0, winSize.height);
	m_pCursorSprite->setPosition(m_aCursorPos);

}

bool CCCursorTextField::isInTextField(cocos2d::CCTouch *pTouch)
{
	CCRect box = this->boundingBox();
	CCPoint pos = convertTouchToNodeSpace(pTouch);

	return CCRectMake(0, 0, box.size.width, box.size.height).containsPoint(pos);
}


bool CCCursorTextField::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{    
	m_beginPos = pTouch->getLocationInView();
	m_beginPos = CCDirector::sharedDirector()->convertToGL(m_beginPos);
	return true;
}


void CCCursorTextField::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	/*CCPoint endPos = pTouch->getLocation();

	// 判断是否为点击事件
	if (::abs(endPos.x - m_beginPos.x) > DELTA || 
		::abs(endPos.y - m_beginPos.y)) 
	{
	
		// 不是点击事件 
		m_beginPos.x = m_beginPos.y = -1;

	//	return;
	}*/
	CCLOG("width: %f, height: %f.", getContentSize().width, getContentSize().height);

	// 是否打开输入法  
	isInTextField(pTouch) ? openIME() : closeIME();
}


bool CCCursorTextField::onTextFieldInsertText(cocos2d::CCTextFieldTTF *pSender, 
									    const char *text, int nLen)
{
	if( m_aCursorPos.y > m_fFontSize )
	{
		// 设置文本内容
		m_pInputText.append(text);
		setString(m_pInputText.c_str());
	}

	// 设置光标位置
	if( 0 == strcmp(text, "\n") )
	{
		m_aCursorPos.x = 0;
		
		if( m_aCursorPos.y > m_fFontSize )
		{
			m_aCursorPos.y -= m_fFontSize;
		}	
	}
	else
	{
		if( m_aCursorPos.y > m_fFontSize )
		{
			m_aCursorPos.x += getTextDimension(text).width;
		}
	}

	m_pCursorSprite->setPosition(m_aCursorPos);

	return true;
}


bool CCCursorTextField::onTextFieldDeleteBackward(cocos2d::CCTextFieldTTF *pSender, const char *delText, int nLen)
{
	// 删除字符
	std::string tempText = delText;
	m_pInputText.resize(m_pInputText.size() - nLen);
	setString(m_pInputText.c_str());
	m_nInputBytes -= nLen ;
	// 设置光标位置
	if( m_aCursorPos.x > 0 )
	{
		m_aCursorPos.x -= getTextDimension(tempText.c_str()).width;
	}
	else
	{
		uint32_t nFoundPos = m_pInputText.rfind("\n");
		if( nFoundPos != std::string::npos )
		{
			std::string sTmp(m_pInputText, nFoundPos + 1);
			m_aCursorPos.x = getTextDimension(sTmp.c_str()).width;
		}
		else if( 0 != m_pInputText.length() )
		{
			m_aCursorPos.x = getTextDimension(m_pInputText.c_str()).width;
		}
		else
		{
			m_aCursorPos.x = 0;
		}

		if( m_aCursorPos.y < m_fContentHeight)
		{
			m_aCursorPos.y += m_fFontSize;
		}
		
	}
	m_pCursorSprite->setPosition(m_aCursorPos);

	return false;
}


void CCCursorTextField::insertText(const char * text, int len)
{
	std::string sTmp;
	char* pChar = NULL;
	bool bAutoLineBreak = false;
	m_nInputBytes += len ;
	if( m_nInputBytes > m_nMaxBytes )
	{
		m_nInputBytes -= len ;
		return ;
	}
	CCLOG("Text = %s, Len = %d" ,text ,len);

	sTmp.assign(m_pInputText.begin(), m_pInputText.end());
	sTmp.append(text);

	// 文本内容长度超出控件长度，自动换行
	float nTextWidth = getTextDimension(sTmp.c_str()).width;
	if( nTextWidth > getContentSize().width )
	{
		pChar = "\n";
		bAutoLineBreak = true;
	}
	else
	{
		pChar = const_cast<char*>(text);
	}

	std::string sInsert(pChar, len);
	int nPos = sInsert.find('\n');
	if( (int)sInsert.npos != nPos )
	{
		len = nPos;
		sInsert.erase(nPos);
	}
	
	// 输入文本内容
	if( len > 0 )
	{
		if( m_pDelegate && m_pDelegate->onTextFieldInsertText(this, sInsert.c_str(), len) )
			return;

		m_nCharCount += _calcCharCount(sInsert.c_str());
		std::string sText(m_pInputText);
		sText.append(sInsert);
		setString(sText.c_str());
	}

	if( (int)sInsert.npos == nPos )
		return;

	
	// 文本换行
	if( m_pDelegate && m_pDelegate->onTextFieldInsertText(this, "\n", 1) )
	{
		// 换行后，插入剩下的文本内容
		if( bAutoLineBreak )
		{
			sInsert.append(text);
			m_pDelegate->onTextFieldInsertText(this, sInsert.c_str(), len);
		}
		return;
	}

	// if delegate hasn't processed, detach from IME by default
	detachWithIME();
}


bool CCCursorTextField::onTextFieldAttachWithIME(cocos2d::CCTextFieldTTF *pSender)
{
	return false;  
}


bool CCCursorTextField::onTextFieldDetachWithIME(cocos2d::CCTextFieldTTF *pSender)
{
	return false;
}


void CCCursorTextField::openIME()
{
	m_pCursorSprite->setVisible(true);
	attachWithIME();
}


void CCCursorTextField::closeIME()
{
	m_pCursorSprite->setVisible(false);
	detachWithIME();
}


void CCCursorTextField::onEnter()
{
	CCTextFieldTTF::onEnter();

	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, kCCMenuHandlerPriority, false);
}


void CCCursorTextField::onExit()
{
	CCTextFieldTTF::onExit();

	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}
