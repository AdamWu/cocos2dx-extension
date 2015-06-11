////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// STL A* Search implementation
// (C)2001 Justin Heyes-Jones
//
// Finding a path on a simple grid maze
// This shows how to do shortest path finding using A*

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "MapSearch.h"

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

bool MapSearchNode::IsSameState( MapSearchNode &rhs )
{
	// same state in a maze search is simply when (x,y) are the same
	if( (x == rhs.x) && (y == rhs.y) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MapSearchNode::PrintNodeInfo()
{
	char str[100];
	sprintf( str, "Node position : (%d,%d)\n", x,y );
	cout << str;
}

// Here's the heuristic function that estimates the distance from a Node
// to the Goal. 

float MapSearchNode::GoalDistanceEstimate( MapSearchNode &nodeGoal )
{
	return fabsf(x - nodeGoal.x) + fabsf(y - nodeGoal.y);	
}

bool MapSearchNode::IsGoal( MapSearchNode &nodeGoal )
{
	if( (x == nodeGoal.x) &&
		(y == nodeGoal.y) )
	{
		return true;
	}

	return false;
}

// This generates the successors to the given Node. It uses a helper function called
// AddSuccessor to give the successors to the AStar class. The A* specific initialisation
// is done for each node internally, so here you just set the state information that
// is specific to the application
bool MapSearchNode::GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node )
{
	int parent_x = -1; 
	int parent_y = -1; 

	if( parent_node )
	{
		parent_x = parent_node->x;
		parent_y = parent_node->y;
	}
	
	MapSearchNode NewNode;

	// push each possible move except allowing the search to go backwards

	if( (MapSearch::getInstance()->getMap(x-1, y ) <= 0) 
		&& !((parent_x == x-1) && (parent_y == y))
	  ) 
	{
		NewNode = MapSearchNode( x-1, y );
		astarsearch->AddSuccessor( NewNode );
	}	

	if( (MapSearch::getInstance()->getMap( x, y-1 ) <= 0) 
		&& !((parent_x == x) && (parent_y == y-1))
	  ) 
	{
		NewNode = MapSearchNode( x, y-1 );
		astarsearch->AddSuccessor( NewNode );
	}	

	if( (MapSearch::getInstance()->getMap( x+1, y ) <= 0)
		&& !((parent_x == x+1) && (parent_y == y))
	  ) 
	{
		NewNode = MapSearchNode( x+1, y );
		astarsearch->AddSuccessor( NewNode );
	}	


	if( (MapSearch::getInstance()->getMap( x, y+1 ) <= 0) 
		&& !((parent_x == x) && (parent_y == y+1))
		)
	{
		NewNode = MapSearchNode( x, y+1 );
		astarsearch->AddSuccessor( NewNode );
	}	


	// ¶Ô½ÇÏß

	if( (MapSearch::getInstance()->getMap(x-1, y-1 ) <= 0) 
		&& !((parent_x == x-1) && (parent_y == y-1))
		) 
	{
		NewNode = MapSearchNode( x-1, y-1 );
		astarsearch->AddSuccessor( NewNode );
	}	

	if( (MapSearch::getInstance()->getMap( x+1, y-1 ) <= 0) 
		&& !((parent_x == x+1) && (parent_y == y-1))
		) 
	{
		NewNode = MapSearchNode( x+1, y-1 );
		astarsearch->AddSuccessor( NewNode );
	}	

	if( (MapSearch::getInstance()->getMap( x+1, y-1 ) <= 0)
		&& !((parent_x == x+1) && (parent_y == y-1))
		) 
	{
		NewNode = MapSearchNode( x+1, y-1 );
		astarsearch->AddSuccessor( NewNode );
	}	


	if( (MapSearch::getInstance()->getMap( x-1, y+1 ) <= 0) 
		&& !((parent_x == x-1) && (parent_y == y+1))
		)
	{
		NewNode = MapSearchNode( x-1, y+1 );
		astarsearch->AddSuccessor( NewNode );
	}

	return true;
}

// given this node, what does it cost to move to successor. In the case
// of our map the answer is the map terrain value at this node since that is 
// conceptually where we're moving

float MapSearchNode::GetCost( MapSearchNode &successor )
{
	if (this->x != successor.x && this->y != successor.y) {
		return 1.41f;
	} else {
		return 1.f;
	}
}

//////////////////////////////////////////////////////////////////////////
//	search path 
//////////////////////////////////////////////////////////////////////////

MapSearch* MapSearch::s_instance = NULL;

void MapSearch::search(int startx, int starty, int endx, int endy)
{
	m_searchResult.clear();

	// Create a start state
	MapSearchNode nodeStart;
	nodeStart.x = startx;
	nodeStart.y = starty; 

	// Define the goal state
	MapSearchNode nodeEnd;
	nodeEnd.x = endx;						
	nodeEnd.y = endy;

	astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );

	do
	{
		m_searchState = astarsearch.SearchStep();
		m_searchSteps++;
	} while( m_searchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );


	if( m_searchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED )
	{
		cout << "Search found goal state\n";

		MapSearchNode *node = astarsearch.GetSolutionEnd();

		int steps = 0;

		m_searchResult.push_back(node);

		//node->PrintNodeInfo();
		for( ;; )
		{
			node = astarsearch.GetSolutionPrev();

			if( !node ) break;

			m_searchResult.push_back(node);

			//node->PrintNodeInfo();
			steps ++;
		};

		cout << "Solution steps " << steps << endl;

		// Once you're done with the solution you can free the nodes up
		astarsearch.FreeSolutionNodes();

	}
	else if( m_searchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED ) 
	{
		cout << "Search terminated. Did not find goal state\n";

	}

	// Display the number of loops the search went through
	cout << "SearchSteps : " << m_searchSteps << "\n";

	astarsearch.EnsureMemoryFreed();

}