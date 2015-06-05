#ifndef __FILESYSTEM_EXT_H__
#define __FILESYSTEM_EXT_H__

class FileSystem
{
public:

	static FileSystem* getInstance();

	const char* getFileData(const char *fullPath);
};

#endif // __FILESYSTEM_EXT_H__
