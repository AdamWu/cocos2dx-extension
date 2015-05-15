/********************************************************************
	water ripple efx
*********************************************************************/


#include "cocos2d.h"

USING_NS_CC;

class RippleSprite : public CCSprite
{

public:
    RippleSprite();
    ~RippleSprite();
    
    static RippleSprite * create(const char* filename);

	bool initWithFile(const char* filename);

	void setTile(float tile) {m_factor_tile=tile;};
	void setNoiseFactor(float factor) {m_factor_noise=factor;};
	void setSpeed(float speed) {m_factor_speed=speed;};

protected:
	virtual void update(float delta);
    virtual void draw();
    
    CCGLProgram*	m_shader;

	GLuint			m_loc_texnoise;
	GLuint			m_loc_time;
	GLuint			m_loc_tile;
	GLuint			m_loc_noise;
	GLuint			m_loc_speed;

	CCTexture2D*	m_texNoise;
	float			m_time;

	float			m_factor_tile;
	float			m_factor_noise;
	float			m_factor_speed;
};