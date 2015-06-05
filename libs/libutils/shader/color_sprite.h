/********************************************************************
	multi color sprite
*********************************************************************/

#include "cocos2d.h"

USING_NS_CC;

class ColorSprite : public CCSprite
{

public:
    ColorSprite();
    ~ColorSprite();
    
	static ColorSprite * create(const char* filename);
	static ColorSprite * createWithTexture(CCTexture2D *pTexture);

	bool initWithFile(const char* filename);
	bool initWithTexture(CCTexture2D *pTexture, const CCRect& rect);

	void setColor(ccColor3B color) {m_color = color;};


protected:

    virtual void draw();
    
    CCGLProgram *m_shader;

	// uniform
	// color
	ccColor3B m_color;
	GLuint m_location_color;    
};