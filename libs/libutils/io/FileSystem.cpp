#include "FileSystem.h"

#include "cocos2d.h"

USING_NS_CC;

FileSystem* FileSystem::getInstance()
{
	static FileSystem instance;
	return &instance;
}

const char* FileSystem::getFileData( const char *fullPath)
{
	unsigned long len = 0;
	unsigned char *data = CCFileUtils::sharedFileUtils()->getFileData(fullPath, "r", &len);
	CCString *ret = CCString::createWithData(data, len);
	delete[] data;
	return ret->getCString();
}


