#ifndef __SHADER_MANAGER_H__
#define __SHADER_MANAGER_H__

#include "cocos2d.h"

USING_NS_CC;

class ShaderManager :public CCObject
{

public:
	ShaderManager();
	~ShaderManager();
    static ShaderManager* getInstance();

private:
	void loadShader(const char* key, const char* vertexShader, const char* fragShader);
	void loadShaderAll();
	void comeToForeground(CCObject * obj);
};

#endif // __SHADER_MANAGER_H__