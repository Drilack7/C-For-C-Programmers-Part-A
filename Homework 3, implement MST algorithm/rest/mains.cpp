/*
Author: Moarales, Dexter Paul E.
12-21-2020
*/
#include <iostream>
#include <math.h>

#define INFINITY 999

using namespace std;

class Dijkstra{

private:
	int adjMatrix[50][50];    //initially set to 50 (maximum)
	int predecessor[50], distance[50];
	bool mark[50];    //keep track of visited node
	int source;
	int numOfVertices;
	int density;
	int densityArray[30];    //initially set to %(100 - 40) of maximum (50)

public:
	void read();

	void initialize();

	int getClosestUnmarkedNode();
	
	void calculateDistance();
	
	void output();
	void printPath(int);
};


void Dijkstra::read(){
	cout << "Enter the number of vertices of the graph (should be (0 - 50] ):\n";
	cin >> numOfVertices;
	while ((numOfVertices <= 0) | (numOfVertices > 50)) {
		cout << "Enter the number of vertices of the graph (should be (0 - 50] ):\n";
		cin >> numOfVertices;
	}

	// get the density of the graph as an input (either %20 or %40)
	cout << "\nEnter the amount of node density (enter 20 for %20 and 40 for %40):\n";
	cin >> density;
	while ((density != 20) & (density != 40)) {
		cout << "Enter the amount of node density (enter 20 for %20 and 40 for %40):\n";
		cin >> density;
	}

	// randomly choose coordinates where the adjacency matrix value will be inf (according to the density)
	for (int i = 0; i < (int)round(numOfVertices * density / 100); i++) {
		densityArray[i] = rand() % numOfVertices;
	}

	// calculate the costs for the adjacency matrix for the graph (between [0 - 10])
	cout << "\nThe costs for Edges are being generated randomly for a graph with " << numOfVertices << " nodes.\n";
	for (int i = 0; i < numOfVertices; i++) {
		for (int j = 0; j < numOfVertices; j++) {
			adjMatrix[i][j] = rand() % 10; //INFINITY;
			adjMatrix[j][i] = adjMatrix[i][j];

			if (*find(densityArray, densityArray + (int)round(numOfVertices * density / 100), j) == j) {
				adjMatrix[i][j] = INFINITY;
				adjMatrix[j][i] = adjMatrix[i][j];
			}

			if (i == j) {
				adjMatrix[i][j] = 0;
			}
		}
	}

	// print out the generated cost matrix
	cout << "\nThe randomly generated edge cost matrix is:\n\n";
	for (int i = 0; i < numOfVertices; i++) {
		for (int j = 0; j < numOfVertices; j++) {
			cout << adjMatrix[i][j] << " ";
		}
		cout << endl;
	}

	// get the source vertex as input from the user
	cout << "\nEnter the source vertex (must be within [0 - " << numOfVertices << ") ):\n";
	cin >> source;
	cout << endl;

	while ((source < 0) | (source > numOfVertices - 1)) {
		cout << "Source vertex should be between 0 and " << numOfVertices - 1 << endl;
		cout << "Enter the source vertex again\n";
		cin >> source;
		cout << endl;
	}

	cout << "The shortest paths (if existing) from the selected source to all other nodes are:\n";
	cout << "==========================================\n";
	cout << "Source" << "..Path" << "..Destination" << "->Total path cost\n";
	cout << "==========================================\n";
}


void Dijkstra::initialize(){

	for (int i = 0; i<numOfVertices; i++) {
		mark[i] = false;
		predecessor[i] = -1;
		distance[i] = INFINITY;
	}
	distance[source] = 0;
}


int Dijkstra::getClosestUnmarkedNode(){

	int minDistance = INFINITY;
	int closestUnmarkedNode;
	for (int i = 0; i<numOfVertices; i++) {
		if ((!mark[i]) & (minDistance >= distance[i])) {
			minDistance = distance[i];
			closestUnmarkedNode = i;
		}
	}
	return closestUnmarkedNode;
}


void Dijkstra::calculateDistance(){
	initialize();
	int minDistance = INFINITY;
	int closestUnmarkedNode;
	int count = 0;
	while (count < numOfVertices) {
		closestUnmarkedNode = getClosestUnmarkedNode();
		mark[closestUnmarkedNode] = true;
		for (int i = 0; i<numOfVertices; i++) {
			if ((!mark[i]) & (adjMatrix[closestUnmarkedNode][i]>0)) {
				if (distance[i] > distance[closestUnmarkedNode] + adjMatrix[closestUnmarkedNode][i]) {
					distance[i] = distance[closestUnmarkedNode] + adjMatrix[closestUnmarkedNode][i];
					predecessor[i] = closestUnmarkedNode;
				}
			}
		}
		count++;
	}
}


void Dijkstra::printPath(int node){
	//
	// Function printPath prints the results (path).
	//

	if (node == source)
		cout << node << "..";
	else if (predecessor[node] == -1)
		cout << "No path from source to " << node << " ";
	else {
		printPath(predecessor[node]);
		cout << node << "..";
	}
}


void Dijkstra::output(){

	for (int i = 0; i<numOfVertices; i++) {
		if (i == source)
			cout << source << ".." << source;
		else
			printPath(i);
		cout << "->" << distance[i] << endl;
	}
}


int main(){
	// initialize a graph
	Dijkstra G;
	G.read();
	G.calculateDistance();
	G.output();
	cin.get();

	cin.get();

	return 0;
}

