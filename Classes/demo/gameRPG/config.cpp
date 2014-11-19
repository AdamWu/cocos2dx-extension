#include <string>
#include "config.h"
#include "tinyxml2/tinyxml2.h"

Config::Config()
{

}

Config::~Config()
{
	std::map<int, BuildingInfo*>::iterator it;
	for (it = m_cfgBuilding.begin(); it != m_cfgBuilding.end(); ++it){
		CC_SAFE_DELETE(it->second);
	}
}

bool Config::init()
{
	tinyxml2::XMLDocument doc;  
	doc.LoadFile("rpg/buildings/building_info.xml");

	tinyxml2::XMLElement *root  = doc.RootElement();//plist  
	tinyxml2::XMLElement *dict = root->FirstChildElement();//dict 

	// read data
	tinyxml2::XMLElement *key = dict->FirstChildElement();
	while(key){
		dict = key->NextSiblingElement();
		if (dict == NULL) {
			// error
			printf("format error for key:%s", key->GetText());
			return false;
		}
		// 
		BuildingInfo *buildinfo = new BuildingInfo;
		buildinfo->id = atoi(key->GetText());

		key = dict->FirstChildElement();
		tinyxml2::XMLElement *value = NULL; 
		while (key){
			value = key->NextSiblingElement();
			if (value == NULL) {
				// error
				printf("format error for key:%s", key->GetText());
				CC_SAFE_DELETE(buildinfo);
				return false;
			}

			if (!strcmp(key->GetText(), "name")){
				buildinfo->name = value->GetText();
			}else if(!strcmp(key->GetText(), "size_map")){
				buildinfo->size_map = atoi(value->GetText());
			}else if(!strcmp(key->GetText(), "size_collide")){
				buildinfo->size_collide = atoi(value->GetText());
			}else if(!strcmp(key->GetText(), "anchor_x")){
				buildinfo->anchor_point.x = atof(value->GetText());
			}else if(!strcmp(key->GetText(), "anchor_y")){
				buildinfo->anchor_point.y = atof(value->GetText());
			}

			// next 
			key = value->NextSiblingElement();
		}
		m_cfgBuilding[buildinfo->id] = buildinfo;
		
		// next 
		key = dict->NextSiblingElement();
	} 

	return true;
}