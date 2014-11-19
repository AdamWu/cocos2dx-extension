#ifndef __GAME_CONTROLLER_H__
#define __GAME_CONTROLLER_H__

#include <string>
#include "singleton.h"

using namespace std;

USING_NS_CC;

class GameBgLayer;
class GameUILayer;
class GameController : public Singleton<GameController>
{
public:
	GameController();
	~GameController();

	bool init();
	
	// bg layer
	void setBgLayer(GameBgLayer *layer){m_bgLayer=layer;};
	GameBgLayer* getBgLayer() {return m_bgLayer;};
	
	// ui layer
	void setUILayer(GameUILayer *layer){m_uiLayer=layer;};
	GameUILayer* getUILayer(){return m_uiLayer;};
private:
	GameBgLayer	*m_bgLayer;
	GameUILayer	*m_uiLayer;
};

#endif // __GAME_CONTROLLER_H__
