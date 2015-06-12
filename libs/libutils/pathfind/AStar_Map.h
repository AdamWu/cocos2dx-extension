#ifndef __ASTAR_MAP_H__
#define __ASTAR_MAP_H__

#include <assert.h>
#include <math.h>

// stl includes
#include <algorithm>
#include <set>
#include <vector>
#include <cfloat>

using namespace std;

// disable warning that debugging information has lines that are truncated
// occurs in stl headers
#if defined(WIN32) && defined(_WINDOWS)
#pragma warning( disable : 4786 )
#endif

class AStarMap
{

public: // data

	enum
	{
		SEARCH_STATE_NOT_INITIALISED,
		SEARCH_STATE_SEARCHING,
		SEARCH_STATE_SUCCEEDED,
		SEARCH_STATE_FAILED,
		SEARCH_STATE_OUT_OF_MEMORY,
		SEARCH_STATE_INVALID
	};

	enum
	{
		STATE_NOT,
		STATE_OPEN,
		STATE_CLOSE,
	};


	// A node represents a possible state in the search
	// The user provided state type is included inside this type

	public:

	class Node
	{
		public:

			Node *parent; // used during the search to record the parent of successor nodes
			Node *child; // used after the search for the application to view the search in reverse
			
			int x;
			int y;

			float g; // cost of this node + it's predecessors
			float h; // heuristic estimate of distance to goal
			float f; // sum of cumulative cost of predecessors and self and heuristic

			unsigned int state;

			Node(int _x, int _y) :
				x(_x),
				y(_y),
				parent( 0 ),
				child( 0 ),
				g( 0.0f ),
				h( 0.0f ),
				f( 0.0f ),
				state(STATE_NOT)
			{			
			}
	};


	// For sorting the heap the STL needs compare function that lets us compare
	// the f value of two nodes

	class HeapCompare_f 
	{
		public:

			bool operator() ( const Node *x, const Node *y ) const
			{
				return x->f > y->f;
			}
	};


public: // methods


	// constructor just initializes private data
	AStarMap(int width, int height) :
		m_State( SEARCH_STATE_NOT_INITIALISED ),
		m_width(width),
		m_height(height),
		m_map(NULL)
	{
		m_map = new int[m_width*m_height];
		memset(m_map, 0, m_width*m_height);
	}

	void release()
	{
		delete(m_map);
		m_map = NULL;
		
		vector<Node*>::iterator it;
		for (it = m_nodes.begin(); it != m_nodes.end(); it ++){
			delete(*it);
		}
		m_nodes.clear();
	}
	

	void initMap(int x, int y, int value)
	{
		m_map[x*m_width+y] = value;
	}

	void initNode()
	{
		for (int i = 0; i < m_height; i ++) {
			for (int j = 0; j < m_width; j ++) {
				m_nodes.push_back(new Node(j, i));
			}
		}
	}

	int getNodeIdx(int x, int y)
	{
		return y * m_height + x;
	}

	Node* getNode(int x, int y)
	{
		return m_nodes[getNodeIdx(x, y)];
	}

	Node* getNode(int idx)
	{
		return m_nodes[idx];
	}

	int getMap(int x, int y)
	{
		if( x < 0 || x >= m_width || y < 0 || y >= m_height)
		{
			return 1;	 
		}

		return m_map[(x*m_width)+y];
	}

	void getCost(Node* father, int x, int y, float &f, float &g, float &h)
	{
		if (father->x != x && father->y != y){
			g = father->g + 1.f;
		} else {
			g = father->g + 1.4f;
		}

		h = fabsf(x - father->x) + fabsf(y - father->y);

		f = g + h;
	}

	// Set Start and goal states
	void SetStartAndGoal(int startx, int starty, int goalx, int goaly);

	// Advances search one step 
	unsigned int SearchStep();

	unsigned int Search(int startx, int starty, int goalx, int goaly);


	// Get final cost of solution
	// Returns FLT_MAX if goal is not defined or there is no solution
	float GetSolutionCost()
	{
		if(m_State == SEARCH_STATE_SUCCEEDED )
		{
			return m_Goal->g;
		}
		else
		{
			return FLT_MAX;
		}
	}

	// Get the number of steps

	int GetStepCount() { return m_Steps; }


	int getResultSteps() {return m_result.size();};
	int getResultNodeX(unsigned int step) {return (m_result[step])->x;};
	int getResultNodeY(unsigned int step) {return (m_result[step])->y;};

private: // data

	// Heap (simple vector but used as a heap, cf. Steve Rabin's game gems article)
	vector< Node *> m_OpenList;

	// Start and goal state pointers
	Node *m_Start;
	Node *m_Goal;

	int			m_width;
	int			m_height;
	int*		m_map;
	vector<Node*>  m_nodes;
	
	// State
	unsigned int m_State;

	// Counts steps
	int m_Steps;

	vector<Node*>	m_result;
};

#endif

   
