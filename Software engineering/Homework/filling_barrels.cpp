/*
	Task: Filling barrels
	Task description: http://olimps.lio.lv/uzdevumi.php?show=258
	Special requirements:
*/

#include <iostream>
#include <fstream>

using namespace std;

#define SIZE 100

class Graph
{
	struct Barrel
	{
		int index;
		int maxFluid;
		double fluid;
		Barrel *next;

		Barrel(int index)
		{
			this->index = index;
			this->maxFluid = 100;
			this->fluid = 0;
			this->next = NULL;
		}

		bool barrelHasConnectionWith(int index)
		{
			Barrel *currNode = this->next;
			while (currNode != NULL)
			{
				if (currNode->index == index)
				{
					return true;
				}
				currNode = currNode->next;
			}
			return false;
		}

		bool openValve(int index)
		{
			if (barrelHasConnectionWith(index))
			{
				return false;
			}

			Barrel *currNode = this;
			while (currNode->next != NULL)
			{
				currNode = currNode->next;
			}

			currNode->next = new Barrel(index);
			return true;
		}

		bool closeValve(int index)
		{
			Barrel *prevNode = this;
			Barrel *currNode = this->next;

			while (currNode != NULL)
			{
				if (currNode->index == index)
				{
					prevNode->next = currNode->next;
					delete currNode;
					return true;
				}

				prevNode = currNode;
				currNode = currNode->next;
			}
			return false;
		}

		bool fluidHasSpilled()
		{
			return fluid > maxFluid;
		}
	};

	Barrel *barrels[SIZE];
	int barrelCount;

	bool connectedBarrels[SIZE];
	int connectedBarrelCount;

	void initConnectedBarrels()
	{
		for (int x = 0; x < SIZE; x++)
		{
			this->connectedBarrels[x] = false;
		}

		this->connectedBarrelCount = 0;
	}

	void initBarrels(int barrelCount)
	{
		for (int x = 0; x < barrelCount; x++)
		{
			this->barrels[x] = new Barrel(x);
		}
		this->barrelCount = barrelCount;
	}

	void visitBarrels(int barrel)
	{
		Barrel *currNode = barrels[barrel];
		while (currNode != NULL)
		{
			if (!connectedBarrels[currNode->index])
			{
				connectedBarrels[currNode->index] = true;
				connectedBarrelCount++;
			}

			currNode = currNode->next;

			if (currNode != NULL && !connectedBarrels[currNode->index])
			{
				visitBarrels(currNode->index);
			}
		}
	}

	void findConnectedBarrels(int barrel)
	{
		initConnectedBarrels();
		visitBarrels(barrel);
	}

	double connectedBarrelTotalFluid()
	{
		double totalFluid = 0;

		for (int y = 0; y < SIZE; y++)
		{
			if (connectedBarrels[y])
			{
				totalFluid += barrels[y]->fluid;
			}
		}

		return totalFluid;
	}

public:
	Graph(int barrelCount)
	{
		initBarrels(barrelCount);
		initConnectedBarrels();
	}

	bool toggleValve(int vertexOne, int vertexTwo)
	{
		Barrel *v1Node = barrels[vertexOne];
		Barrel *v2Node = barrels[vertexTwo];

		if (v1Node->closeValve(vertexTwo) && v2Node->closeValve(vertexOne))
		{
			return false;
		}

		double totalFluid = 0;
		int totalConnectedBarrels = 0;

		findConnectedBarrels(vertexOne);
		totalFluid += connectedBarrelTotalFluid();
		totalConnectedBarrels += connectedBarrelCount;

		findConnectedBarrels(vertexTwo);
		totalFluid += connectedBarrelTotalFluid();
		totalConnectedBarrels += connectedBarrelCount;

		v1Node->openValve(vertexTwo);
		v2Node->openValve(vertexOne);

		findConnectedBarrels(vertexOne);
		double fluidPerBarrel = totalFluid / totalConnectedBarrels;

		for (int y = 0; y < SIZE; y++)
		{
			if (connectedBarrels[y])
			{
				barrels[y]->fluid = fluidPerBarrel;
			}
		}

		return true;
	}

	void addFluid(int index, int fluidAmount)
	{
		findConnectedBarrels(index);

		double fluidPerBarrel = (double)fluidAmount / connectedBarrelCount;
		for (int y = 0; y < SIZE; y++)
		{
			if (connectedBarrels[y])
			{
				barrels[y]->fluid += fluidPerBarrel;
			}
		}
	}

	bool fluidHasSpilled()
	{
		for (int x = 0; x < barrelCount; x++)
		{
			if (barrels[x]->fluidHasSpilled())
			{
				return true;
			}
		}

		return false;
	}
};

int main()
{
	ifstream readFile("mucas.dat");
	ofstream writeFile("mucas.rez");

	int barrelCount;
	readFile >> barrelCount;

	Graph graph(barrelCount);

	int currentOperationCount = 0;
	int totalOperationCount;
	readFile >> totalOperationCount;

	char operation;
	int inputOne;
	int inputTwo;

	while (!graph.fluidHasSpilled())
	{
		readFile >> operation;
		readFile >> inputOne;
		readFile >> inputTwo;

		switch (operation)
		{
		case 'P':
			graph.addFluid(inputOne - 1, inputTwo);
			break;
		case 'V':
			graph.toggleValve(inputOne - 1, inputTwo - 1);
			break;
		}

		currentOperationCount++;
	}

	writeFile << currentOperationCount;

	readFile.close();
	writeFile.close();
}