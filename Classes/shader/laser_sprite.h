/********************************************************************
	laser efx
*********************************************************************/


#include "cocos2d.h"

USING_NS_CC;

class LaserSprite : public CCSprite
{

public:
    LaserSprite();
    ~LaserSprite();
    
    static LaserSprite * create(const char* filename);

	bool initWithFile(const char* filename);

protected:

    virtual void draw();
	virtual void update(float dt);
    
    CCGLProgram*	m_shader;

	GLuint			m_loc_texMask1;
	GLuint			m_loc_texMask2;
	GLuint			m_loc_texNoise1;
	GLuint			m_loc_texNoise2;
	GLuint			m_loc_time;
	GLuint			m_loc_porN;
	GLuint			m_loc_klightcolor;
	GLuint			m_loc_kglowcolor;
	GLuint			m_loc_noisescale;

	CCTexture2D*	m_texMask1;
	CCTexture2D*	m_texMask2;
	CCTexture2D*	m_texNoise1;
	CCTexture2D*	m_texNoise2;

	float			m_time;
};