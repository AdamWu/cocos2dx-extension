#ifndef __RPG_CONFIG_H__
#define __RPG_CONFIG_H__

#include <string>
#include "singleton.h"

using namespace std;
USING_NS_CC;

// building cfg
typedef struct{
	int id;
	string name;
	int size_map;
	int size_collide;
	CCPoint anchor_point;
}BuildingInfo;

class Config : public Singleton<Config>
{
public:
	Config();
	~Config();

	bool init();

	BuildingInfo* getBuildingInfo(int buildid) {return m_cfgBuilding[buildid];};
private:
	
	std::map<int, BuildingInfo*>	m_cfgBuilding;
};

#endif // __RPG_CONFIG_H__
