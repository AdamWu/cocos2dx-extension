#include "HttpRequestManager.h"
#include "CCLuaStack.h"
#include "CCLuaEngine.h"


HttpRequestManager * HttpRequestManager::getInstance()
{
	static HttpRequestManager instance;
	return &instance;
}

HttpRequestManager::HttpRequestManager()
{
	_requestList = CCArray::create();
	_requestList->retain();
}

HttpRequestManager::~HttpRequestManager()
{
	_requestList->release();
}

void HttpRequestManager::httpGet( const char *url, int scriptHandler )
{
	CCHttpRequest *request = new CCHttpRequest();
	request->setUrl(url);
    std::stringstream strs;
    strs << scriptHandler;
    request->setTag(strs.str().c_str());
	request->setRequestType(CCHttpRequest::kHttpGet);
	request->setResponseCallback(this, httpresponse_selector(HttpRequestManager::onHttpRequestCompleted));
	CCHttpClient::getInstance()->send(request);
	request->release();
}

void HttpRequestManager::httpPost( const char *url, const char *requestData, unsigned int dataLength, int scriptHandler )
{
	CCHttpRequest *request = new CCHttpRequest();
	request->setUrl(url);
    std::stringstream strs;
    strs << scriptHandler;
    request->setTag(strs.str().c_str());
	request->setRequestType(CCHttpRequest::kHttpPost);
	request->setResponseCallback(this, httpresponse_selector(HttpRequestManager::onHttpRequestCompleted));
	request->setRequestData(requestData, dataLength);
	CCHttpClient::getInstance()->send(request);
	request->release();
}

void HttpRequestManager::onHttpRequestCompleted( CCHttpClient* client, CCHttpResponse* response )
{
	int scriptHandler = atoi(response->getHttpRequest()->getTag());
	CCLuaStack *pStack = CCLuaEngine::defaultEngine()->getLuaStack();
	int respCode = response->getResponseCode();
	std::vector<char>* respData = response->getResponseData();

	CCLuaValueArray luaArray;
	for (int i = 0 ; i < respData->size(); i++) {
		CCLuaValue value = CCLuaValue::intValue((*respData)[i]);
		luaArray.push_back(value);
	}

	pStack->pushInt(respCode);
	pStack->pushCCLuaValueArray(luaArray);
	pStack->executeFunctionByHandler(scriptHandler, 2);
	pStack->clean();
	return;
}

