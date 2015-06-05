#ifndef __HTTP_REQUEST_MANAGER_H_
#define __HTTP_REQUEST_MANAGER_H_

#include "cocos2d.h"
#include "cocos-ext.h"
//#include "HttpClient.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class HttpRequestManager : public CCObject
{
public:

	static HttpRequestManager* getInstance();

	void httpGet(const char *url, int scriptHandler);

	void httpPost(const char *url, const char *requestData, unsigned int dataLength, int scriptHandler);

private:

	HttpRequestManager();
	~HttpRequestManager();

	void onHttpRequestCompleted(CCHttpClient* client, CCHttpResponse* response);

private:

	CCArray *_requestList;

};

#endif