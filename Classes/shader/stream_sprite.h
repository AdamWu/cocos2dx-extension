/********************************************************************
	stream efx
*********************************************************************/


#include "cocos2d.h"

USING_NS_CC;

class StreamSprite : public CCSprite
{

public:
    StreamSprite();
    ~StreamSprite();
    
    static StreamSprite * create(const char* filename);

	bool initWithFile(const char* filename);
    

protected:
    
	virtual void update(float delta);

    virtual void draw();
    
    CCGLProgram *m_shader;
	
	float m_factor;
	GLuint m_location_factor;

	// ¿í¶È
	float m_width;
	GLuint m_location_width;

	// line function x+y-c=0
	// offset
    float m_offset;
	GLuint m_location_offset;

	// color
	ccColor3B m_color;
	GLuint m_location_color;
};