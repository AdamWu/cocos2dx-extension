#include "blind_sprite.h"

BlindSprite::BlindSprite()
{
	m_flag = 1.f;
	m_lineWidth = 1.f/8;
	m_offset = 0;

	m_duration = 2;
	m_delay = 4;
	m_timer = 0;

	m_array = CCArray::createWithCapacity(5);
	m_array->retain();

	m_idx = 0;
	m_texure1 = NULL;
	m_texure2 = NULL;
}

BlindSprite::~BlindSprite()
{

}

BlindSprite* BlindSprite::create(CCArray *filelist)
{
    BlindSprite * ret = new BlindSprite();
    if (ret && ret->initWithFile(filelist))
    {
        ret->autorelease();
        return ret;
    }
    
    CC_SAFE_RELEASE(ret);
    return NULL;
}


bool BlindSprite::initWithFile(CCArray *filelist)
{
	CCObject *object = NULL;
	CCARRAY_FOREACH(filelist, object){
		CCString *str = (CCString*)object;

		CCTexture2D *tex = CCTextureCache::sharedTextureCache()->addImage(str->getCString());
		CCAssert(tex, "texture not fount");
		m_array->addObject(tex);
	}


	this->switchTexture();

	m_shader = CCShaderCache::sharedShaderCache()->programForKey("Shader_Blind");   

	m_texture1Location = glGetUniformLocation(m_shader->getProgram(), "texture1");
	m_flag_location = glGetUniformLocation(m_shader->getProgram(), "flag");
	m_linewidth_location = glGetUniformLocation(m_shader->getProgram(), "lineWidth");
	m_offset_location = glGetUniformLocation(m_shader->getProgram(), "offset");

	bool ret = true;
	ret = CCSprite::initWithTexture((CCTexture2D*)m_array->objectAtIndex(0));

	this->scheduleUpdate();
	return ret;
}

void BlindSprite::switchTexture()
{
	printf("switchTexture idx %d\n",m_idx);
	m_texure1 = (CCTexture2D *)m_array->objectAtIndex(m_idx);
	m_idx = (++m_idx)%(m_array->count());
	m_texure2 = (CCTexture2D *)m_array->objectAtIndex(m_idx);
	printf("switch tex %p, %p\n",m_texure1, m_texure2);
}



void BlindSprite::draw()
{

    CC_PROFILER_START_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");
        
	CCAssert(!m_pobBatchNode, "If CCSprite is being rendered by CCSpriteBatchNode, CCSprite#draw SHOULD NOT be called");
        
	//CC_NODE_DRAW_SETUP();
	ccGLEnable( m_eGLServerState );
        
	ccGLBlendFunc( m_sBlendFunc.src, m_sBlendFunc.dst );
        
	m_shader->use();
    m_shader->setUniformsForBuiltins();

	glUniform1f(m_flag_location, m_flag);
	glUniform1f(m_linewidth_location, m_lineWidth);
	glUniform1f(m_offset_location, m_offset);
		
	if (m_texure1 != NULL)
	{
		//ccGLBindTexture2D( m_texure1->getName());
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_texure1->getName());
	}
	else
	{
		ccGLBindTexture2D(0);
	}

	if(m_texure2 != NULL)
	{
		glActiveTexture(GL_TEXTURE1);
		glBindTexture( GL_TEXTURE_2D,  m_texure2->getName());
		glUniform1i(m_texture1Location, 1);
	}
	else
	{
		ccGLBindTexture2D(0);
	}

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

void BlindSprite::update( float delta )
{
	static bool state = true; // state 1,2
	m_timer += delta;
	if (state) {
		// in window-blind
		m_offset = m_timer / m_duration;
		//printf("blind %f\n", m_offset);
		if (m_timer > m_duration)
		{
			state = false;
			m_timer = 0;
		}
	} else {
		// in break time
		//printf("break %f\n", m_timer);
		if (m_timer > m_delay){
			state = true;
			m_timer = 0;

			m_offset = 0.f;
			//m_flag *= -1;
			this->switchTexture();
		}
	}
}

void BlindSprite::setDuration( float duration )
{
	m_duration = duration;
}




