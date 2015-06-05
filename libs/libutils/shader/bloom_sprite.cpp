#include "bloom_sprite.h"

BloomSprite::BloomSprite()
{
}

BloomSprite::~BloomSprite()
{
}

BloomSprite* BloomSprite::create(const char* filename)
{
    BloomSprite * ret = new BloomSprite();
    if (ret && ret->initWithFile(filename))
    {
        ret->autorelease();
        return ret;
    }
    
    CC_SAFE_RELEASE(ret);
    return NULL;
}


bool BloomSprite::initWithFile(const char* filename)
{
	bool ret = CCSprite::initWithFile(filename);

	m_tex_size = this->getContentSize();

	m_frameTexture = CCRenderTexture::create(m_tex_size.width, m_tex_size.height);
	m_frameTexture->retain();
	
	m_frameTexture2 = CCRenderTexture::create(m_tex_size.width, m_tex_size.height);
	m_frameTexture2->retain();

#if CC_DEBUG
	m_frameTexture3 = CCRenderTexture::create(m_tex_size.width, m_tex_size.height);
	m_frameTexture3->retain();
#endif

	//
	// brightness shader
	//
	m_shader_brightness = CCShaderCache::sharedShaderCache()->programForKey("Shader_Brightness");

	//
	// blur shader
	//
	m_shader_blur = CCShaderCache::sharedShaderCache()->programForKey("Shader_Blur");  
 

	m_location_pix_size = glGetUniformLocation(m_shader_blur->getProgram(), "pix_size");


	this->scheduleUpdate();
	return ret;
}



void BloomSprite::draw()
{

    CC_PROFILER_START_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");

	//CC_NODE_DRAW_SETUP();
	ccGLEnable( m_eGLServerState );

	ccGLBlendFunc( m_sBlendFunc.src, m_sBlendFunc.dst );

	// bright
	m_frameTexture->clear(0.f, 0.f, 0.f, 0.f);
	m_frameTexture->begin();
	{
		m_shader_brightness->use();
		m_shader_brightness->setUniformsForBuiltins();

		if (m_pobTexture != NULL)
		{
			ccGLBindTexture2D( m_pobTexture->getName());
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
	}
	m_frameTexture->end();
#if CC_DEBUG
	m_frameTexture->saveToFile("brightness.png");
#endif

	// 水平方向blur 
	CCTexture2D* rt = m_frameTexture->getSprite()->getTexture();
	m_frameTexture2->clear(0.f, 0.f, 0.f, 0.f);
	m_frameTexture2->begin();
	{

		m_shader_blur->use();
		m_shader_blur->setUniformsForBuiltins();

		glUniform2f(m_location_pix_size, 2.0f/m_tex_size.width, 2.0f/m_tex_size.height);

		if (rt != NULL)
		{
			ccGLBindTexture2D(rt->getName());
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

	}
	m_frameTexture2->end();


	// 垂直方向blur
	rt = m_frameTexture2->getSprite()->getTexture();
#if CC_DEBUG
	m_frameTexture3->clear(0, 0, 0, 0);
	m_frameTexture3->begin();
#endif
	{
		m_shader_blur->use();
		m_shader_blur->setUniformsForBuiltins();

		glUniform2f(m_location_pix_size, 0, 1.f/m_tex_size.height);

		if ( rt != NULL)
		{
			ccGLBindTexture2D(rt->getName());
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
	}
#if CC_DEBUG
	m_frameTexture3->end();
	m_frameTexture3->saveToFile("bloom.png");
#endif
        
	CC_INCREMENT_GL_DRAWS(1);
        
	CC_PROFILER_STOP_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");
}

void BloomSprite::update( float delta )
{
	
}




