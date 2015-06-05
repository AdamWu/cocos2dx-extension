#include "laser_sprite.h"

LaserSprite::LaserSprite()
	:m_time(0.f)
{

}

LaserSprite::~LaserSprite()
{

}

LaserSprite* LaserSprite::create(const char* filename)
{
    LaserSprite * ret = new LaserSprite();
    if (ret && ret->initWithFile(filename))
    {
        ret->autorelease();
        return ret;
    }
    
    CC_SAFE_RELEASE(ret);
    return NULL;
}


bool LaserSprite::initWithFile(const char* filename)
{

	CCSize winSize=CCDirector::sharedDirector()->getWinSize();

	bool ret = CCSprite::initWithFile(filename);

	m_shader = CCShaderCache::sharedShaderCache()->programForKey("Shader_Laser");  

	{
		ccTexParams texParams= {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
		this->getTexture()->setTexParameters(&texParams);
	}
	m_texMask1 = CCTextureCache::sharedTextureCache()->addImage("laser/mask2.png");
	//m_texMask1 = CCTextureCache::sharedTextureCache()->addImage("card2.png");
	{
		ccTexParams texParams= {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
		m_texMask1->setTexParameters(&texParams);
	}
	//m_texMask2 = CCTextureCache::sharedTextureCache()->addImage("laser/mask2.png");
	m_texNoise1 = CCTextureCache::sharedTextureCache()->addImage("cloud/clouds2.png");
	{
		ccTexParams texParams= {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
		m_texNoise1->setTexParameters(&texParams);
	}
	m_texNoise2 = CCTextureCache::sharedTextureCache()->addImage("cloud/clouds1.png");
	{
		ccTexParams texParams= {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
		m_texNoise2->setTexParameters(&texParams);
	}

	m_loc_texMask1 = glGetUniformLocation(m_shader->getProgram(), "u_maskTex");
	//m_loc_texMask2 = glGetUniformLocation(m_shader->getProgram(), "u_maskTex2");
	m_loc_texNoise1 = glGetUniformLocation(m_shader->getProgram(), "u_noiseTex");
	m_loc_texNoise2 = glGetUniformLocation(m_shader->getProgram(), "u_noiseTex2");
	
	float loc_spritesize = glGetUniformLocation(m_shader->getProgram(), "u_spriteSize");
	float loc_noisesize = glGetUniformLocation(m_shader->getProgram(), "u_noiseSize");
	float loc_hightlight = glGetUniformLocation(m_shader->getProgram(), "u_highlight");
	m_loc_time = glGetUniformLocation(m_shader->getProgram(), "u_time");
	m_loc_porN = glGetUniformLocation(m_shader->getProgram(), "u_PorN");
	m_loc_klightcolor = glGetUniformLocation(m_shader->getProgram(), "u_kLightColor");
	m_loc_kglowcolor = glGetUniformLocation(m_shader->getProgram(), "u_kGlowColor");
	m_loc_noisescale = glGetUniformLocation(m_shader->getProgram(), "u_noiseScale");

	m_shader->setUniformLocationWith2f(loc_spritesize, getContentSize().width, getContentSize().height);
	m_shader->setUniformLocationWith2f(loc_noisesize, m_texNoise1->getContentSize().width, m_texNoise1->getContentSize().height);

	m_shader->setUniformLocationWith1f(loc_hightlight, 1.f);
	m_shader->setUniformLocationWith1f(m_loc_porN, 1.f);
	m_shader->setUniformLocationWith1f(m_loc_klightcolor, 0.2f);
	m_shader->setUniformLocationWith1f(m_loc_kglowcolor, 3.5f);
	m_shader->setUniformLocationWith1f(m_loc_noisescale, 1.0f);

	this->scheduleUpdate();
	return ret;
}

void LaserSprite::draw()
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
	glBindTexture( GL_TEXTURE_2D,  m_texMask1->getName());
	glUniform1i(m_loc_texMask1, 1);

	glActiveTexture(GL_TEXTURE2);
	glBindTexture( GL_TEXTURE_2D,  m_texNoise1->getName());
	glUniform1i(m_loc_texNoise1, 2);

	glActiveTexture(GL_TEXTURE3);
	glBindTexture( GL_TEXTURE_2D,  m_texNoise2->getName());
	glUniform1i(m_loc_texNoise2, 3);


	m_shader->setUniformLocationWith1f(m_loc_time, m_time);

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

void LaserSprite::update(float dt)
{
	m_time += dt;

}



