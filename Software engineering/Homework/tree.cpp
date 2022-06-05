/*
	Task: Tree
	Task description: http://olimps.lio.lv/uzdevumi.php?show=221
	Special requirements:
*/

#include <iostream>
#include <fstream>

using namespace std;

#define SIZE 1000

class Graph
{
	bool matchingMatrix[SIZE][SIZE];
	int vertices[SIZE];
	int verticesCount;

	int height(int vertex)
	{
		int currentHeight = 0;
		int newHeight = 0;

		for (int x = 0; x < verticesCount; x++)
		{
			if (vertices[x] == vertex)
			{
				for (int y = 0; y < verticesCount; y++)
				{
					if (matchingMatrix[x][y])
					{
						newHeight = height(vertices[y]);
						if (currentHeight < newHeight)
						{
							currentHeight = newHeight;
						}
					}
				}
				break;
			}
		}

		return 1 + currentHeight;
	}

	int allVerticesHaveAPathToRoot(int vertex)
	{
		int verticesFound = 0;

		for (int x = 0; x < verticesCount; x++)
		{
			if (vertices[x] == vertex)
			{
				for (int y = 0; y < verticesCount; y++)
				{
					if (matchingMatrix[x][y])
					{
						verticesFound += allVerticesHaveAPathToRoot(vertices[y]);
					}
				}
				break;
			}
		}

		return 1 + verticesFound;
	}

public:
	Graph()
	{
		for (int y = 0; y < SIZE; y++)
		{
			for (int x = 0; x < SIZE; x++)
			{
				matchingMatrix[y][x] = false;
			}
			vertices[y] = '\0';
		}
		verticesCount = 0;
	}

	bool isTree()
	{
		return root() != 0 && allVerticesHaveOnePathToRoot() && allVerticesHaveAPathToRoot();
	}

	/*
	We are looking through all columns in the matrix to
	find a vertex that has only 0s in the column.
	Column with only 0s == root vertex, because that means
	that no other vertices have an edge with that vertex.
	*/
	int root()
	{
		for (int y = 0; y < verticesCount; y++)
		{
			for (int x = 0; x < verticesCount; x++)
			{
				if (matchingMatrix[x][y])
				{
					break;
				}

				if (x == verticesCount - 1)
				{
					return vertices[y];
				}
			}
		}

		return 0;
	}

	/*
	We are looking through all columns in the matrix to
	make sure that every column has only one '1' in it,
	if there are multiple 1s, then the graph has multiple paths
	to a vertex
	*/
	bool allVerticesHaveOnePathToRoot()
	{
		int onesFound = 0;

		for (int y = 0; y < verticesCount; y++)
		{
			for (int x = 0; x < verticesCount; x++)
			{
				if (matchingMatrix[x][y])
				{
					onesFound++;
				}

				if (onesFound > 1)
				{
					return false;
				}
			}
			onesFound = 0;
		}

		return true;
	}

	bool allVerticesHaveAPathToRoot()
	{
		return allVerticesHaveAPathToRoot(root()) == verticesCount;
	}

	bool addVertex(int vertex)
	{
		if (verticesCount == SIZE)
		{
			return false;
		}

		for (int x = 0; x < verticesCount; x++)
		{
			if (vertices[x] == vertex)
			{
				return false;
			}
		}

		vertices[verticesCount] = vertex;
		verticesCount++;
		return true;
	}

	bool addDirectedEdge(int v1, int v2)
	{
		int x = -1;
		int y = -1;

		for (int z = 0; z < verticesCount; z++)
		{
			if (vertices[z] == v1)
			{
				y = z;
			}
			else if (vertices[z] == v2)
			{
				x = z;
			}
		}

		if (x != -1 && y != -1)
		{
			matchingMatrix[y][x] = true;
			return true;
		}

		return false;
	}

	int height()
	{
		return height(root()) - 1;
	}
};

int main()
{
	ifstream readFile("koks.dat");
	ofstream writeFile("koks.rez");

	int verticesCount;
	readFile >> verticesCount;

	int edgeCount;
	readFile >> edgeCount;

	Graph graph;

	int v1;
	int v2;

	if (verticesCount == 1)
	{
		graph.addVertex(1);
	}

	while (edgeCount != 0)
	{
		readFile >> v1;
		readFile >> v2;

		if (verticesCount != 0)
		{
			if (graph.addVertex(v1))
				verticesCount--;
			if (graph.addVertex(v2))
				verticesCount--;
		}

		graph.addDirectedEdge(v1, v2);
		edgeCount--;
	}

	if (graph.isTree())
	{
		writeFile << graph.root() << " " << graph.height();
	}
	else
	{
		writeFile << 0 << " " << 0;
	}

	readFile.close();
	writeFile.close();
}