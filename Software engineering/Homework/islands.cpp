/*
	Task: Islands
	Task description: http://olimps.lio.lv/uzdevumi.php?show=109
	Special requirements:
*/

#include <iostream>
#include <fstream>
#include <limits.h>

using namespace std;

#define SIZE 50

class Graph
{
	struct Island
	{
		int index;
		int timeToNextIsland;
		Island *next;

		Island(int index)
		{
			this->index = index;
			this->timeToNextIsland = -1;
			this->next = NULL;
		}

		void addNewIsland(int island, int timeToIsland)
		{
			Island *currentNode = this;
			while (currentNode->next != NULL)
			{
				currentNode = currentNode->next;
			}
			currentNode->next = new Island(island);
			currentNode->timeToNextIsland = timeToIsland;
		}

		int getIndex()
		{
			return index - 1;
		}
	};

	Island *islands[SIZE];
	int islandCount;

	void dijkstra(int sourceIsland, ofstream &writeFile)
	{
		int distancesFromIsland[SIZE];
		bool foundShortestPathsToIslands[SIZE];

		for (int x = 0; x < islandCount; x++)
		{
			distancesFromIsland[x] = INT_MAX;
			foundShortestPathsToIslands[x] = false;
		}
		distancesFromIsland[sourceIsland] = 0;

		int minDistance = INT_MAX;
		int minDistanceIndex = 0;

		int islandIndex = 0;
		int distanceSum = 0;

		int islandsChecked = 0;
		while (islandsChecked != islandCount)
		{
			for (int y = 0; y < islandCount; y++)
			{
				if (!foundShortestPathsToIslands[y] && minDistance >= distancesFromIsland[y])
				{
					minDistance = distancesFromIsland[y];
					minDistanceIndex = y;
				}
			}

			foundShortestPathsToIslands[minDistanceIndex] = true;

			Island *currentIsland = islands[minDistanceIndex];
			while (currentIsland->next != NULL)
			{
				islandIndex = currentIsland->next->getIndex();
				distanceSum = distancesFromIsland[minDistanceIndex] + currentIsland->timeToNextIsland;

				if (!foundShortestPathsToIslands[islandIndex] &&
					distancesFromIsland[minDistanceIndex] != INT_MAX &&
					distanceSum < distancesFromIsland[islandIndex])
				{
					distancesFromIsland[islandIndex] = distanceSum;
				}

				currentIsland = currentIsland->next;
			}

			minDistance = INT_MAX;
			minDistanceIndex = 0;
			islandsChecked++;
		}

		for (int z = 0; z < islandCount; z++)
		{
			writeFile << distancesFromIsland[z] << " ";
		}
		writeFile << "\n";
	}

public:
	Graph(int islandCount)
	{
		for (int x = 0; x < islandCount; x++)
		{
			this->islands[x] = new Island(x);
		}
		this->islandCount = islandCount;
	}

	void addPath(int sourceIsland, int destinationIsland, int timeToNextIsland)
	{
		islands[sourceIsland - 1]->addNewIsland(destinationIsland, timeToNextIsland);
		islands[destinationIsland - 1]->addNewIsland(sourceIsland, timeToNextIsland);
	}

	void printDijkstra(ofstream &writeFile)
	{
		for (int x = 0; x < islandCount; x++)
		{
			dijkstra(x, writeFile);
		}
	}
};

int main()
{
	ifstream readFile("salas.in");
	ofstream writeFile("salas.out");

	int islandCount;
	readFile >> islandCount;

	Graph graph(islandCount);

	int pathCount;
	readFile >> pathCount;

	int islandOne;
	int islandTwo;
	int pathTime;

	while (pathCount != 0)
	{
		readFile >> islandOne;
		readFile >> islandTwo;
		readFile >> pathTime;

		graph.addPath(islandOne, islandTwo, pathTime);

		pathCount--;
	}

	graph.printDijkstra(writeFile);

	readFile.close();
	writeFile.close();
}