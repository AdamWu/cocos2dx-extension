/********************************************************************
	gray sprite
*********************************************************************/


#include "cocos2d.h"

USING_NS_CC;

class GraySprite : public CCSprite
{

public:
    GraySprite();
    ~GraySprite();
    
	static GraySprite * create(const char* filename);
	static GraySprite * createWithTexture(CCTexture2D *pTexture);

	bool initWithFile(const char* filename);
	bool initWithTexture(CCTexture2D *pTexture, const CCRect& rect);

protected:

    virtual void draw();
    
    CCGLProgram *m_shader;  
};