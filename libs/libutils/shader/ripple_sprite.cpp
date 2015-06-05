#include "ripple_sprite.h"

RippleSprite::RippleSprite()
{
	m_time = 0.f;
	m_factor_tile = 0.02;
	m_factor_noise = 0.01;
	m_factor_speed = 0.005;
}

RippleSprite::~RippleSprite()
{

}

RippleSprite* RippleSprite::create(const char* filename)
{
    RippleSprite * ret = new RippleSprite();
    if (ret && ret->initWithFile(filename))
    {
        ret->autorelease();
        return ret;
    }
    
    CC_SAFE_RELEASE(ret);
    return NULL;
}


bool RippleSprite::initWithFile(const char* filename)
{

	CCSize winSize=CCDirector::sharedDirector()->getWinSize();

	bool ret = CCSprite::initWithFile(filename);

	m_shader = CCShaderCache::sharedShaderCache()->programForKey("Shader_Ripple");  

	m_texNoise = CCTextureCache::sharedTextureCache()->addImage("standard/noise_2d_std.png");

	m_loc_texnoise = glGetUniformLocation(m_shader->getProgram(), "u_texNoise");
	m_loc_time = glGetUniformLocation(m_shader->getProgram(), "u_time");
	m_loc_tile = glGetUniformLocation(m_shader->getProgram(), "u_factor_tile");
	m_loc_noise = glGetUniformLocation(m_shader->getProgram(), "u_factor_noise");
	m_loc_speed = glGetUniformLocation(m_shader->getProgram(), "u_factor_speed");

	this->scheduleUpdate();
	return ret;
}



void RippleSprite::draw()
{

    CC_PROFILER_START_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");
        
	CCAssert(!m_pobBatchNode, "If CCSprite is being rendered by CCSpriteBatchNode, CCSprite#draw SHOULD NOT be called");
        
	//CC_NODE_DRAW_SETUP();
	ccGLEnable( m_eGLServerState );
        
	ccGLBlendFunc( m_sBlendFunc.src, m_sBlendFunc.dst );
        
	m_shader->use();
    m_shader->setUniformsForBuiltins();


	if (m_pobTexture != NULL)
	{
		//ccGLBindTexture2D( m_texure1->getName());
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_pobTexture->getName());
	}
	else
	{
		ccGLBindTexture2D(0);
	}

	// texture normalmap
	glActiveTexture(GL_TEXTURE1);
	glBindTexture( GL_TEXTURE_2D,  m_texNoise->getName());
	glUniform1i(m_loc_texnoise, 1);

	m_shader->setUniformLocationWith1f(m_loc_time, m_time);
	m_shader->setUniformLocationWith1f(m_loc_tile, m_factor_tile);
	m_shader->setUniformLocationWith1f(m_loc_noise, m_factor_noise);
	m_shader->setUniformLocationWith1f(m_loc_speed, m_factor_speed);

	//
	// Attributes
	//
	ccGLEnableVertexAttribs( kCCVertexAttribFlag_PosColorTex );
        
#define kQuadSize sizeof(m_sQuad.bl)
	long offset = (long)&m_sQuad;
        
	// vertex
	int diff = offsetof( ccV3F_C4B_T2F, vertices);
	glVertexAttribPointer(kCCVertexAttrib_Position, 3, GL_FLOAT, GL_FALSE, kQuadSize, (void*) (offset + diff));
        
	// texCoods
	diff = offsetof( ccV3F_C4B_T2F, texCoords);
	glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE, kQuadSize, (void*)(offset + diff));
        
	// color
	diff = offsetof( ccV3F_C4B_T2F, colors);
	glVertexAttribPointer(kCCVertexAttrib_Color, 4, GL_UNSIGNED_BYTE, GL_TRUE, kQuadSize, (void*)(offset + diff));
        
        
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        
	CHECK_GL_ERROR_DEBUG();
        
	CC_INCREMENT_GL_DRAWS(1);
        
	CC_PROFILER_STOP_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");
}

void RippleSprite::update(float delta)
{
	m_time += delta;
}



