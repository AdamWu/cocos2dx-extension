#include "stream_sprite.h"

StreamSprite::StreamSprite()
{
	m_factor = 1.f;
	m_width = 0.3f;
	m_offset = 2.f;
	//m_color = ccc3(125, 100, 50);
	m_color = ccc3(100, 100, 100);
}

StreamSprite::~StreamSprite()
{

}

StreamSprite* StreamSprite::create(const char* filename)
{
    StreamSprite * ret = new StreamSprite();
    if (ret && ret->initWithFile(filename))
    {
        ret->autorelease();
        return ret;
    }
    
    CC_SAFE_RELEASE(ret);
    return NULL;
}


bool StreamSprite::initWithFile(const char* filename)
{
	bool ret = CCSprite::initWithFile(filename);

	m_shader = CCShaderCache::sharedShaderCache()->programForKey("Shader_Stream");  

	m_location_factor = glGetUniformLocation(m_shader->getProgram(), "factor");
	m_location_width = glGetUniformLocation(m_shader->getProgram(), "width");
	m_location_offset = glGetUniformLocation(m_shader->getProgram(), "offset");
	m_location_color = glGetUniformLocation(m_shader->getProgram(), "color");


	this->scheduleUpdate();
	return ret;
}



void StreamSprite::draw()
{
    CC_PROFILER_START_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");
        
	CCAssert(!m_pobBatchNode, "If CCSprite is being rendered by CCSpriteBatchNode, CCSprite#draw SHOULD NOT be called");
        
	//CC_NODE_DRAW_SETUP();
	ccGLEnable( m_eGLServerState );
        
	ccGLBlendFunc( m_sBlendFunc.src, m_sBlendFunc.dst );
        
	m_shader->use();
    m_shader->setUniformsForBuiltins();

	glUniform1f(m_location_factor, m_factor);
	glUniform1f(m_location_offset, m_offset);
	glUniform1f(m_location_width, m_width);
	glUniform3f(m_location_color, (GLfloat)(m_color.r/255.f),(GLfloat)(m_color.g/255.f),(GLfloat)(m_color.b/255.f));
		
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

void StreamSprite::update( float delta )
{
	//m_factor = m_factor + delta;
	if (m_factor > 4.f){
		m_factor = 1.f;
	}

	m_offset = m_offset - delta;
	if (m_offset < 0.f){
		m_offset = 3.f;
	}
	
}




