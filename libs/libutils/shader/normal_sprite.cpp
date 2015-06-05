#include "normal_sprite.h"

NormalSprite::NormalSprite()
{

}

NormalSprite::~NormalSprite()
{

}

NormalSprite* NormalSprite::create(const char* filename, const char* normalmap)
{
    NormalSprite * ret = new NormalSprite();
    if (ret && ret->initWithFile(filename, normalmap))
    {
        ret->autorelease();
        return ret;
    }
    
    CC_SAFE_RELEASE(ret);
    return NULL;
}


bool NormalSprite::initWithFile(const char* filename, const char* normalmap)
{

	CCSize winSize=CCDirector::sharedDirector()->getWinSize();

	bool ret = CCSprite::initWithFile(filename);

	m_shader = CCShaderCache::sharedShaderCache()->programForKey("Shader_Normal"); 

	m_texNormal = CCTextureCache::sharedTextureCache()->addImage(normalmap);

	m_loc_normalmap = glGetUniformLocation(m_shader->getProgram(), "u_normalMap");
	
	float location_contentsize = glGetUniformLocation(m_shader->getProgram(), "u_contentSize");
	m_loc_lightdiffuse = glGetUniformLocation(m_shader->getProgram(), "u_diffuseL");
	m_loc_lightpos = glGetUniformLocation(m_shader->getProgram(), "u_lightPosInLocalSpace");

	m_shader->setUniformLocationWith2f(location_contentsize, getContentSize().width, getContentSize().height);

	this->scheduleUpdate();
	return ret;
}



void NormalSprite::draw()
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
	glBindTexture( GL_TEXTURE_2D,  m_texNormal->getName());
	glUniform1i(m_loc_normalmap, 1);

	// uniforms
	CCPoint lightPosInLocalSpace=CCPointApplyAffineTransform(ccp(m_light.pos.x, m_light.pos.y),this->parentToNodeTransform());
	m_shader->setUniformLocationWith4f(m_loc_lightpos, lightPosInLocalSpace.x, lightPosInLocalSpace.y, m_light.pos.z, 1.f);
	m_shader->setUniformLocationWith3f(m_loc_lightdiffuse, m_light.diffuse.r, m_light.diffuse.g, m_light.diffuse.b);

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





