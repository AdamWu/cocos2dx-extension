#include "shader_manager.h"

ShaderManager *gShaderManager =  NULL;

ShaderManager* ShaderManager::getInstance()
{
	if (gShaderManager == NULL)
	{
		gShaderManager = new ShaderManager();
	}
	return gShaderManager;
}

ShaderManager::ShaderManager()
{
	loadShaderAll();
	CCNotificationCenter::sharedNotificationCenter()->addObserver(this,
		callfuncO_selector(ShaderManager::comeToForeground),
		"event_come_to_foreground",
		NULL);
}

ShaderManager::~ShaderManager()
{

}

void ShaderManager::loadShaderAll()
{ 
	const char* fs = CCString::createWithContentsOfFile("shader/efx_color.fsh")->getCString();
	loadShader("Shader_Color",ccPositionTextureColor_vert, (const GLchar*)fs);

	fs = CCString::createWithContentsOfFile("shader/efx_gray.fsh")->getCString();
	loadShader("Shader_Gray",ccPositionTextureColor_vert, (const GLchar*)fs);

	fs = CCString::createWithContentsOfFile("shader/efx_brightness.fsh")->getCString();
	loadShader("Shader_Brightness",ccPositionTextureColor_vert, (const GLchar*)fs);

	fs = CCString::createWithContentsOfFile("shader/efx_stream.fsh")->getCString();
	loadShader("Shader_Stream",ccPositionTextureColor_vert, (const GLchar*)fs);

	fs = CCString::createWithContentsOfFile("shader/efx_blur.fsh")->getCString();
	loadShader("Shader_Blur",ccPositionTextureColor_vert, (const GLchar*)fs);

	fs = CCString::createWithContentsOfFile("shader/efx_frost.fsh")->getCString();
	loadShader("Shader_Frost",ccPositionTextureColor_vert, (const GLchar*)fs);

	fs = CCString::createWithContentsOfFile("shader/efx_blind.fsh")->getCString();
	loadShader("Shader_Blind",ccPositionTextureColor_vert, (const GLchar*)fs);

	fs = CCString::createWithContentsOfFile("shader/efx_normal.fsh")->getCString();
	loadShader("Shader_Normal",ccPositionTextureColor_vert, (const GLchar*)fs);

	fs = CCString::createWithContentsOfFile("shader/efx_ripple.fsh")->getCString();
	loadShader("Shader_Ripple",ccPositionTextureColor_vert, (const GLchar*)fs);

	fs = CCString::createWithContentsOfFile("shader/efx_hue.fsh")->getCString();
	loadShader("Shader_Hue",ccPositionTextureColor_vert, (const GLchar*)fs);

	fs = CCString::createWithContentsOfFile("shader/efx_laser.fsh")->getCString();
	loadShader("Shader_Laser",ccPositionTextureColor_vert, (const GLchar*)fs);
}

void ShaderManager::loadShader(const char* key, const GLchar* vertexShader, const GLchar* fragShader)
{
	CCGLProgram * ccProgram = CCShaderCache::sharedShaderCache()->programForKey(key);
	if (ccProgram == NULL)
	{
		ccProgram = new CCGLProgram();
		ccProgram->autorelease();
		CCShaderCache::sharedShaderCache()->addProgram(ccProgram, key);
	}
	else
	{
		ccProgram->reset();
	}
	ccProgram->initWithVertexShaderByteArray(vertexShader, fragShader);
	CHECK_GL_ERROR_DEBUG();

	ccProgram->addAttribute(kCCAttributeNamePosition, kCCVertexAttrib_Position);  
	ccProgram->addAttribute(kCCAttributeNameColor, kCCVertexAttrib_Color);  
	ccProgram->addAttribute(kCCAttributeNameTexCoord, kCCVertexAttrib_TexCoords);
	CHECK_GL_ERROR_DEBUG();  

	// 自定义着色器链接  
	ccProgram->link();  
	CHECK_GL_ERROR_DEBUG();  

	// 设置移动、缩放、旋转矩阵  
	ccProgram->updateUniforms();
	CHECK_GL_ERROR_DEBUG();
}

void ShaderManager::comeToForeground( CCObject * obj )
{
	loadShaderAll();
}
