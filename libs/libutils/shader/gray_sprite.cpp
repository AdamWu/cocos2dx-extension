#include "gray_sprite.h"

GraySprite::GraySprite()
{
}

GraySprite::~GraySprite()
{
}

GraySprite* GraySprite::create(const char* filename)
{
    GraySprite * ret = new GraySprite();
    if (ret && ret->initWithFile(filename))
    {
        ret->autorelease();
        return ret;
    }
    
    CC_SAFE_RELEASE(ret);
    return NULL;
}


GraySprite* GraySprite::createWithTexture(CCTexture2D *pTexture)
{
	CCAssert(pTexture != NULL, "Invalid texture for sprite");

	CCRect rect = CCRectZero;
	rect.size = pTexture->getContentSize();

	GraySprite *ret = new GraySprite();
	if (ret && ret->initWithTexture(pTexture, rect))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}


bool GraySprite::initWithTexture(CCTexture2D *pTexture, const CCRect& rect)
{
	if (CCSprite::initWithTexture(pTexture, rect))
	{	
		m_shader = CCShaderCache::sharedShaderCache()->programForKey("Shader_Gray");

		return true;

	} else {
		return false;
	}
}

bool GraySprite::initWithFile(const char* filename)
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


void GraySprite::draw()
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
        
	CC_INCREMENT_GL_DRAWS(1);
        
	CC_PROFILER_STOP_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");
}



