#include "hue_sprite.h"



void xRotateMat(float mat[3][3], float rs, float rc)
{
	mat[0][0] = 1.0;
	mat[0][1] = 0.0;
	mat[0][2] = 0.0;

	mat[1][0] = 0.0;
	mat[1][1] = rc;
	mat[1][2] = rs;

	mat[2][0] = 0.0;
	mat[2][1] = -rs;
	mat[2][2] = rc;
}

void yRotateMat(float mat[3][3], float rs, float rc)
{
	mat[0][0] = rc;
	mat[0][1] = 0.0;
	mat[0][2] = -rs;

	mat[1][0] = 0.0;
	mat[1][1] = 1.0;
	mat[1][2] = 0.0;

	mat[2][0] = rs;
	mat[2][1] = 0.0;
	mat[2][2] = rc;
}


void zRotateMat(float mat[3][3], float rs, float rc)
{
	mat[0][0] = rc;
	mat[0][1] = rs;
	mat[0][2] = 0.0;

	mat[1][0] = -rs;
	mat[1][1] = rc;
	mat[1][2] = 0.0;

	mat[2][0] = 0.0;
	mat[2][1] = 0.0;
	mat[2][2] = 1.0;
}

void matrixMult(float a[3][3], float b[3][3], float c[3][3])
{
	int x, y;
	float temp[3][3];

	for(y=0; y<3; y++) {
		for(x=0; x<3; x++) {
			temp[y][x] = b[y][0] * a[0][x] + b[y][1] * a[1][x] + b[y][2] * a[2][x];
		}
	}
	for(y=0; y<3; y++) {
		for(x=0; x<3; x++) {
			c[y][x] = temp[y][x];
		}
	}
}

void hueMatrix(GLfloat mat[3][3], float angle)
{
#define SQRT_2      sqrt(2.0)
#define SQRT_3      sqrt(3.0)

	float mag, rot[3][3];
	float xrs, xrc;
	float yrs, yrc;
	float zrs, zrc;

	// Rotate the grey vector into positive Z
	mag = SQRT_2;
	xrs = 1.0/mag;
	xrc = 1.0/mag;
	xRotateMat(mat, xrs, xrc);
	mag = SQRT_3;
	yrs = -1.0/mag;
	yrc = SQRT_2/mag;
	yRotateMat(rot, yrs, yrc);
	matrixMult(rot, mat, mat);

	// Rotate the hue
	zrs = sin(angle);
	zrc = cos(angle);
	zRotateMat(rot, zrs, zrc);
	matrixMult(rot, mat, mat);

	// Rotate the grey vector back into place
	yRotateMat(rot, -yrs, yrc);
	matrixMult(rot,  mat, mat);
	xRotateMat(rot, -xrs, xrc);
	matrixMult(rot,  mat, mat);
}

HueSprite::HueSprite()
{
	m_hue = 0.f;
	updateMatrix();
}

HueSprite::~HueSprite()
{

}

HueSprite* HueSprite::create(const char* filename)
{
    HueSprite * ret = new HueSprite();
    if (ret && ret->initWithFile(filename))
    {
        ret->autorelease();
        return ret;
    }
    
    CC_SAFE_RELEASE(ret);
    return NULL;
}


bool HueSprite::initWithFile(const char* filename)
{

	CCSize winSize=CCDirector::sharedDirector()->getWinSize();

	bool ret = CCSprite::initWithFile(filename);

	m_shader = CCShaderCache::sharedShaderCache()->programForKey("Shader_Hue");    

	m_loc_hue = glGetUniformLocation(m_shader->getProgram(), "u_hue");

	this->scheduleUpdate();
	return ret;
}

void HueSprite::setHue(float hue)
{
	m_hue = hue;

	updateMatrix();
}

void HueSprite::updateMatrix()
{
	hueMatrix(m_mat, m_hue);
}

void HueSprite::draw()
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


	glUniformMatrix3fv(m_loc_hue, 1, GL_FALSE, (GLfloat*)&m_mat);

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