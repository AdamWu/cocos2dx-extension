#include "AStar_Map.h"

#include <stdio.h>
#include <math.h>

// Set Start and goal states
void AStarMap::SetStartAndGoal(int startx, int starty, int goalx, int goaly)
{
	assert((m_Start != NULL && m_Goal != NULL));
		
	m_State = SEARCH_STATE_SEARCHING;
		
	// Initialise the AStar specific parts of the Start Node
	// The user only needs fill out the state information

	m_Start = getNode(startx, starty);
	m_Goal = getNode(goalx, goaly);

	// Push the start node on the Open list
	m_OpenList.push_back( m_Start );
	push_heap( m_OpenList.begin(), m_OpenList.end(), HeapCompare_f() );

	// Initialise counter for search steps
	m_Steps = 0;
}

// Advances search one step 
unsigned int AStarMap::SearchStep()
{	
	// Firstly break if the user has not initialised the search
	assert( (m_State > SEARCH_STATE_NOT_INITIALISED) &&
		(m_State < SEARCH_STATE_INVALID) );

	// Next I want it to be safe to do a searchstep once the search has succeeded...
	if( (m_State == SEARCH_STATE_SUCCEEDED) ||
		(m_State == SEARCH_STATE_FAILED) 
		)
	{
		return m_State; 
	}

	// New: Allow user abort
	if( m_OpenList.empty() )
	{
		m_State = SEARCH_STATE_FAILED;
		return m_State;
	}

	m_Steps ++;

	// Pop the best node (the one with the lowest f) 
	Node *open = m_OpenList.front(); // get pointer to the node
	open->state = STATE_CLOSE;
	pop_heap( m_OpenList.begin(), m_OpenList.end(), HeapCompare_f() );
	m_OpenList.pop_back();

	// Check for the goal, once we pop that we're done
	if( open == m_Goal ) {
		// success
		m_Goal->parent = open->parent;
		m_Goal->g = open->g;

		m_State = SEARCH_STATE_SUCCEEDED;

		return m_State;
	} else {

		int open_idx = getNodeIdx(open->x, open->y);

		// check arround 
		float f,g,h;
		for (int i = -1; i < 2; i ++){
			for (int j = -1 ; j < 2; j ++){
				int x = open->x + i;
				int y = open->y + j;

				if (getMap(x, y) > 0 ) continue;

				int idx = getNodeIdx(x, y);
				if (idx != open_idx) {
					Node* newNode = getNode(idx);
					getCost(open, x, y, f, g, h);

					if (newNode->state == STATE_NOT){
						// a new one, add to openlist
						newNode->parent = open;
						newNode->state = STATE_OPEN;
						newNode->f = f;
						newNode->g = g;
						newNode->h = h;
						m_OpenList.push_back(newNode);
						push_heap( m_OpenList.begin(), m_OpenList.end(), HeapCompare_f() );
					} else if (newNode->state == STATE_OPEN){
						// in openlist
						if (f < (newNode->f)) {
							// a better way then update
							newNode->parent = open;
							newNode->f = f;
							newNode->g = g;
							newNode->h = h;
							make_heap( m_OpenList.begin(), m_OpenList.end(), HeapCompare_f() );
						}
					}
				}
			}
		}
	}

	return m_State;
}

unsigned int AStarMap::Search(int startx, int starty, int goalx, int goaly)
{
	SetStartAndGoal(startx, starty, goalx, goaly);

	unsigned int state;
	do
	{
		state = SearchStep();
	} while( state == SEARCH_STATE_SEARCHING );


	if( state == SEARCH_STATE_SUCCEEDED )
	{
		m_result.clear();

		Node* pNode = m_Goal;
	
		while(pNode) {
			m_result.push_back(pNode);

			pNode = pNode->parent;
		}

		printf("Search found goal state\n");

	}
	else if( state == SEARCH_STATE_FAILED ) 
	{
		printf("Search terminated. Did not find goal state\n");

	}

	return state;
}

   
