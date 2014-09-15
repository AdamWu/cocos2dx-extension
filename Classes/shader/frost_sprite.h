/********************************************************************
	frost efx
*********************************************************************/


#include "cocos2d.h"

#define CC_DEBUG 0

USING_NS_CC;

class FrostSprite : public CCSprite
{

public:
    FrostSprite();
    ~FrostSprite();
    
    static FrostSprite * create(const char* filename);

	bool initWithFile(const char* filename);
    

protected:
    
	virtual void update(float delta);

    virtual void draw();
    
    CCGLProgram *m_shader;

	CCTexture2D *m_texure1;
	GLuint m_location_texture1;
	
	CCSize m_tex_size;
	GLuint m_location_pix_size;

#if CC_DEBUG
	CCRenderTexture * m_frameTexture;// for debug
#endif
};