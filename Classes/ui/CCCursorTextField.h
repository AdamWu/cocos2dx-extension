#ifndef __CC_CURSOR_TEXTFIELD_H__
#define __CC_CURSOR_TEXTFIELD_H__

#include "cocos2d.h"
//#include "cocos-ext.h"
using namespace cocos2d;
//using namespace extension;
class CCCursorTextField :public CCTextFieldTTF, public  CCTouchDelegate,public CCTextFieldDelegate
{
public:
	CCCursorTextField ();
	virtual ~CCCursorTextField ();

	// static
	static CCCursorTextField* textFieldWithPlaceHolder(const char *placeholder, 
		const char *fontName, const float fontSize, CCSize aContectSize);

	void onEnter();
	void onExit();

	// ��ʼ����꾫��
	void initCursorSprite();

	CCSize getTextDimension(const char* pText);

	// CCTextFieldDelegate
	virtual bool onTextFieldAttachWithIME(CCTextFieldTTF *pSender);
	virtual bool onTextFieldDetachWithIME(CCTextFieldTTF * pSender);
	virtual bool onTextFieldInsertText(CCTextFieldTTF * pSender, const char * text, int nLen);
	virtual bool onTextFieldDeleteBackward(CCTextFieldTTF * pSender, const char * delText, int nLen);

	// CCLayer
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	// �ж��Ƿ�����TextField��
	bool isInTextField(CCTouch *pTouch);


	const char *getText(){return m_pInputText.c_str() ;}
	void setText( const char *pText );
	void setMaxBytes( const uint32_t bytes ) { m_nMaxBytes = bytes ;}

	// �����뷨
	void openIME();
	// �ر����뷨
	void closeIME();

protected:
  virtual void insertText(const char * text, int len);

private:
	CCPoint		m_beginPos;						//�����ʼλ��

	//CCScale9Sprite*	m_pCursorSprite;				// ��꾫��
	CCSprite*	m_pCursorSprite;				// ��꾫��
	CCAction*	m_pCursorAction;				// ��궯��
	CCPoint		m_aCursorPos;					// �������

	float			m_fFontSize;
	std::string		m_sFontName;
	std::string	m_pInputText;				// ������ı�����
	uint32_t		m_nMaxBytes;
	uint32_t		m_nInputBytes;
	float		m_fContentHeight;
};

#endif //__CC_AUZ_CODE_LAYER_H__
