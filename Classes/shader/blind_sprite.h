/********************************************************************
	window blind (ads window)
*********************************************************************/


#include "cocos2d.h"

USING_NS_CC;

class BlindSprite : public CCSprite
{

public:
    BlindSprite();
    ~BlindSprite();
    
    static BlindSprite * create(CCArray *filelist);

	bool initWithFile(CCArray *filelist);

	void setSplitNum(int num) {m_lineWidth = 1.f/num;};
	void setDuration(float duration);
    
private:
	void switchTexture();

protected:
    
	virtual void update(float delta);

    virtual void draw();
    
    CCGLProgram *m_shader;

	// textures
	CCArray		*m_array;
	int			m_idx;
	CCTexture2D *m_texure1;
	CCTexture2D *m_texure2;
	
	GLuint m_texture1Location;

	// uniform
	float	m_flag;			// reduce switch-tex times 
	float	m_lineWidth;
	float	m_offset;

	GLuint m_flag_location;
	GLuint m_linewidth_location;
	GLuint m_offset_location;

	float m_duration;		// time cost for one window-blind
	float m_delay;			// time delay for next window-blind
	
	float m_timer;
    
};