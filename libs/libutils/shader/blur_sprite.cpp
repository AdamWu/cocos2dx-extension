#include "blur_sprite.h"

BlurSprite::BlurSprite()
{
}

BlurSprite::~BlurSprite()
{
	m_frameTexture->release();
}

BlurSprite* BlurSprite::create(const char* filename)
{
    BlurSprite * ret = new BlurSprite();
    if (ret && ret->initWithFile(filename))
    {
        ret->autorelease();
        return ret;
    }
    
    CC_SAFE_RELEASE(ret);
    return NULL;
}

BlurSprite* BlurSprite::createWithTexture(CCTexture2D *pTexture)
{
	CCAssert(pTexture != NULL, "Invalid texture for sprite");

	CCRect rect = CCRectZero;
	rect.size = pTexture->getContentSize();

	BlurSprite *ret = new BlurSprite();
	if (ret && ret->initWithTexture(pTexture, rect))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}


bool BlurSprite::initWithTexture(CCTexture2D *pTexture, const CCRect& rect)
{
	if (CCSprite::initWithTexture(pTexture, rect))
	{
		m_tex_size = this->getContentSize();

		this->setScaleY(-1);

		m_frameTexture = CCRenderTexture::create(m_tex_size.width, m_tex_size.height);
		m_frameTexture->retain();

#if CC_DEBUG
		m_frameTexture2 = CCRenderTexture::create(m_tex_size.width, m_tex_size.height);
		m_frameTexture2->retain();
#endif
		m_shader = CCShaderCache::sharedShaderCache()->programForKey("Shader_Blur");

		m_location_pix_size = glGetUniformLocation(m_shader->getProgram(), "pix_size");


		this->scheduleUpdate();

		return true;
	} else {
		return false;
	}
}


bool BlurSprite::initWithFile(const char* filename)
{
	CCAssert(filename != NULL, "Invalid filename for sprite");

	CCTexture2D *pTexture = CCTextureCache::sharedTextureCache()->addImage(filename);
	if (pTexture)
	{
		CCRect rect = CCRectZero;
		rect.size = pTexture->getContentSize();
		return initWithTexture(pTexture, rect);
	}

	return false;
}



void BlurSprite::draw()
{

    CC_PROFILER_START_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");
        
	CCAssert(!m_pobBatchNode, "If CCSprite is being rendered by CCSpriteBatchNode, CCSprite#draw SHOULD NOT be called");
        
	//CC_NODE_DRAW_SETUP();
	ccGLEnable( m_eGLServerState );

	ccGLBlendFunc( m_sBlendFunc.src, m_sBlendFunc.dst );

	// 水平方向blur 
	m_frameTexture->clear(0.f, 0.f, 0.f, 0.f);
	m_frameTexture->begin();
	{

		m_shader->use();
		m_shader->setUniformsForBuiltins();

		glUniform2f(m_location_pix_size, 1.f/m_tex_size.width, 0);

		if (m_pobTexture != NULL)
		{
			ccGLBindTexture2D(m_pobTexture->getName());
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

	// 垂直方向blur
	CCTexture2D* rt = m_frameTexture->getSprite()->getTexture();
#if CC_DEBUG
	m_frameTexture2->clear(0.f, 0.f, 0.f, 0.f);
	m_frameTexture2->begin();
#endif
	{
		m_shader->use();
		m_shader->setUniformsForBuiltins();

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
	m_frameTexture2->end();
	m_frameTexture2->saveToFile("blur_complete.png");
#endif

	CC_INCREMENT_GL_DRAWS(1);
        
	CC_PROFILER_STOP_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");
}

void BlurSprite::update( float delta )
{
	
}




