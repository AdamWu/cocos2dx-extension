////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// STL A* Search implementation
// (C)2001 Justin Heyes-Jones
//
// Finding a path on a simple grid maze
// This shows how to do shortest path finding using A*

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __MAP_SEARCH_H__
#define __MAP_SEARCH_H__

#include "AStar.h"

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

// Definitions
class MapSearchNode
{
public:
	int x;	 // the (x,y) positions of the node
	int y;	
	
	MapSearchNode() { x = y = 0; }
	MapSearchNode( int px, int py ) { x=px; y=py; }

	float GoalDistanceEstimate( MapSearchNode &nodeGoal );
	bool IsGoal( MapSearchNode &nodeGoal );
	bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
	float GetCost( MapSearchNode &successor );
	bool IsSameState( MapSearchNode &rhs );

	void PrintNodeInfo();
};


class MapSearch
{
public:
	static MapSearch* getInstance(){
		if(!s_instance)
		{
			s_instance = new MapSearch;
		}
		return s_instance;
	}
public:
	MapSearch() {m_searchSteps=0;};
	~MapSearch(){};

	void init(int width, int height, int *mapdata){
		m_width = width;
		m_height = height;
		//m_worldmap = mapdata;
		m_worldmap = new int[m_width*m_height];
		memset(m_worldmap, 0, m_width*m_height);
	}

	void initMap(int x, int y, int value){
		m_worldmap[x*m_width+y] = value;
	}

	int getMap(int x, int y)
	{
		if( x < 0 || x >= m_width || y < 0 || y >= m_height)
		{
			return 1;	 
		}

		return m_worldmap[(x*m_width)+y];
	}

	void search(int startx, int starty, int endx, int endy);
	
	unsigned int getSearchState() {return m_searchState;}
	
	int getSearchSteps() {return m_searchResult.size();};
	int getSearchNodeX(unsigned int step) {return (m_searchResult[step])->x;};
	int getSearchNodeY(unsigned int step) {return (m_searchResult[step])->y;};
protected:
	static MapSearch *s_instance;

private:
	int*	m_worldmap;
	int		m_width;
	int		m_height;	
	
	AStarSearch<MapSearchNode> astarsearch;

	unsigned int				m_searchState;
	unsigned int				m_searchSteps;
	vector<MapSearchNode*>		m_searchResult;
};

#endif // __MAP_SEARCH_H__