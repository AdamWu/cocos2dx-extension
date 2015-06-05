/********************************************************************
	bloom efx
	bright & blur
*********************************************************************/


#include "cocos2d.h"

#define CC_DEBUG 0

USING_NS_CC;

class BloomSprite : public CCSprite
{

public:
    BloomSprite();
    ~BloomSprite();
    
    static BloomSprite * create(const char* filename);

	bool initWithFile(const char* filename);
    

protected:
    
	virtual void update(float delta);

    virtual void draw();
    
	CCGLProgram *m_shader_brightness;
	CCGLProgram *m_shader_blur;
	
	CCSize m_tex_size;
	GLuint m_location_pix_size;

	CCRenderTexture* m_frameTexture;
	CCRenderTexture* m_frameTexture2;
#if CC_DEBUG
	CCRenderTexture* m_frameTexture3;
#endif
};