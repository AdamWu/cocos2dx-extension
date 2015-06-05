#include "frost_sprite.h"

FrostSprite::FrostSprite()
{
}

FrostSprite::~FrostSprite()
{
}

FrostSprite* FrostSprite::create(const char* filename)
{
    FrostSprite * ret = new FrostSprite();
    if (ret && ret->initWithFile(filename))
    {
        ret->autorelease();
        return ret;
    }
    
    CC_SAFE_RELEASE(ret);
    return NULL;
}


bool FrostSprite::initWithFile(const char* filename)
{
	bool ret = CCSprite::initWithFile(filename);

	m_tex_size = this->getContentSize();

#if CC_DEBUG
	m_frameTexture = CCRenderTexture::create(m_tex_size.width, m_tex_size.height);
	m_frameTexture->retain();
#endif
  
	m_shader = CCShaderCache::sharedShaderCache()->programForKey("Shader_Frost");  

	m_texure1 = CCTextureCache::sharedTextureCache()->addImage("standard/noise_2d_std.png");
 

	m_location_pix_size = glGetUniformLocation(m_shader->getProgram(), "pix_size");
	m_location_texture1 = glGetUniformLocation(m_shader->getProgram(), "tex_noise");


	this->scheduleUpdate();
	return ret;
}



void FrostSprite::draw()
{

    CC_PROFILER_START_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");
        
	CCAssert(!m_pobBatchNode, "If CCSprite is being rendered by CCSpriteBatchNode, CCSprite#draw SHOULD NOT be called");
        
	//CC_NODE_DRAW_SETUP();
	ccGLEnable( m_eGLServerState );
        
	ccGLBlendFunc( m_sBlendFunc.src, m_sBlendFunc.dst );
        
#if CC_DEBUG
	m_frameTexture->clear(0, 0, 0, 0);
	m_frameTexture->begin();
#endif
	m_shader->use();
    m_shader->setUniformsForBuiltins();

	glUniform2f(m_location_pix_size, 1.f/m_tex_size.width, 1.f/m_tex_size.height);
		
	if (m_pobTexture != NULL)
	{
		ccGLBindTexture2D( m_pobTexture->getName());
	}
	else
	{
		ccGLBindTexture2D(0);
	}

	if (m_texure1 != NULL)
	{
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, m_texure1->getName());
		glUniform1i(m_location_texture1, 1);
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

#if CC_DEBUG
	m_frameTexture->end();
	m_frameTexture->saveToFile("frost.png");
#endif


	CC_INCREMENT_GL_DRAWS(1);
        
	CC_PROFILER_STOP_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");
}

void FrostSprite::update( float delta )
{
	
}




