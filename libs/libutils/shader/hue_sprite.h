/********************************************************************
	hue efx
*********************************************************************/
#ifndef __HUE_SPRITE_H__
#define __HUE_SPRITE_H__

#include "cocos2d.h"

USING_NS_CC;

class HueSprite : public CCSprite
{

public:
    HueSprite();
    ~HueSprite();
    
    static HueSprite * create(const char* filename);

	bool initWithFile(const char* filename);

	void setHue(float hue);
	float getHue() { return m_hue;};

protected:
	virtual void draw();

	void updateMatrix();
    
    CCGLProgram*	m_shader;

	GLuint			m_loc_hue;


	float			m_hue;	// [0, 2pi]
	GLfloat			m_mat[3][3]; 
};

#endif //__HUE_SPRITE_H__