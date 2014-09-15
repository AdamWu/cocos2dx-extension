/********************************************************************
	blur efx
*********************************************************************/

#include "cocos2d.h"

USING_NS_CC;

#define CC_DEBUG 0

class BlurSprite : public CCSprite
{

public:
    BlurSprite();
    ~BlurSprite();

	static BlurSprite * create(const char* filename);
	static BlurSprite * createWithTexture(CCTexture2D *pTexture);

	bool initWithTexture(CCTexture2D *pTexture, const CCRect& rect);
	bool initWithFile(const char* filename);
    

protected:
    
	virtual void update(float delta);

    virtual void draw();
    
    CCGLProgram *m_shader;
	
	CCSize m_tex_size;
	GLuint m_location_pix_size;

	CCRenderTexture * m_frameTexture;

#if CC_DEBUG
	CCRenderTexture * m_frameTexture2;// for debug
#endif
};