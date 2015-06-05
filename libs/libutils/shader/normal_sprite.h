/********************************************************************
	normal efx
*********************************************************************/


#include "cocos2d.h"

USING_NS_CC;

struct SpotLight {
	ccVertex3F	pos;
	ccColor4F	diffuse;
	SpotLight() {
		pos.x = pos.y = 0.f;
		pos.z = 50.f;
		diffuse.r = diffuse.g = diffuse.b = diffuse.a = 1.f;
	}
};

class NormalSprite : public CCSprite
{

public:
    NormalSprite();
    ~NormalSprite();
    
    static NormalSprite * create(const char* filename, const char* normalmap);

	bool initWithFile(const char* filename, const char* normalmap);
    
	void setLight(SpotLight light) {m_light=light;};
	void setLightPos(CCPoint pos) {
		m_light.pos.x = pos.x;
		m_light.pos.y = pos.y;
	};
	void setLightColor(ccColor3B color) {
		m_light.diffuse.r = color.r;
		m_light.diffuse.g = color.g;
		m_light.diffuse.b = color.b;
	};

protected:

    virtual void draw();
    
    CCGLProgram*	m_shader;

	GLuint			m_loc_normalmap;
	GLuint			m_loc_lightdiffuse;
	GLuint			m_loc_lightpos;

	CCTexture2D*	m_texNormal;

	SpotLight		m_light;
};