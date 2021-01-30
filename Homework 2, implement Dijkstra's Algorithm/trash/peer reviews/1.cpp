/*
what you learned

- Learned how to run C++ program
- Learned how to include different header
- Learned how to use namespace
- Learned different operators in C++
- Learned how to assign different classes to variables
-Learned how control flow in C++

*/

#include <iostream>
#include <stdlib.h> //for rand()
#include <math.h>   //for function INFINITY

using namespace std;

class Dijkstra {

public:
	void read();
	int getNode();
	void Distance(int source);
	void printDistance(int source);

private:
	int graphMatrix[50][50];
	int nnodes;
	int density;
	int distance[50];
	int predecessor[50];
	bool recorded[50];    		//keep record of node

};

void Dijkstra::read(){

	// Number of nodes in the graph
	cout << "Enter the number of nodes (1 - 50]:\n";
	cin >> nnodes;

	// Density of the graph
	cout << "\nEnter the amount of node density:\n";
	cin >> density;

	// Costs for the graph
	for (int i = 0; i < nnodes; i++) {
		graphMatrix[i][i] = 0; //0 distance for the same node

		for (int j = 0; j < i; j++) {

			//randomly select path
			if (rand()%100 < density){
				//randomly fill in costs from 1-10
				graphMatrix[i][j] = (rand()%10) + 1;
				graphMatrix[j][i] = graphMatrix[i][j];
			} else {
				//For unconnected nodes, we give the cost of 0
				graphMatrix[i][j] = 0;
				graphMatrix[j][i] = graphMatrix[i][j];
			}
		}
	}

	// print out the generated cost matrix
	cout << "\nThe randomly generated edge cost matrix is:\n\n";
	for (int i = 0; i < nnodes; i++) {
		for (int j = 0; j < nnodes; j++) {
			cout << graphMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

int Dijkstra::getNode(){

	//return the nearest unrecorded node

	int minDistance = INFINITY;
	int closestNode;
	for (int i = 0; i<nnodes; i++) {
		if ((!recorded[i]) & (minDistance >= distance[i])) {
			minDistance = distance[i];
			closestNode = i;
		}
	}
	return closestNode;
}

void Dijkstra::Distance(int source){
	// initialize the initial value
	for (int i = 0; i<nnodes; i++) {
		recorded[i] = false;
		predecessor[i] = -1;
		distance[i] = INFINITY;
	}
	distance[source] = 0;

	// calculates the minimum distances from the source node to Other nodes.
	int minDistance = INFINITY;
	int closestNode;
	int count = 0;
	while (count < nnodes) {
		closestNode = getNode();
		recorded[closestNode] = true;
		for (int i = 0; i<nnodes; i++) {
			if ((!recorded[i]) & (graphMatrix[closestNode][i]>0)) {
				if (distance[i] > distance[closestNode] + graphMatrix[closestNode][i]) {
					distance[i] = distance[closestNode] + graphMatrix[closestNode][i];
					predecessor[i] = closestNode;
				}
			}
		}
		count++;
	}
}

int main()
{
    Dijkstra obj;
    obj.Distance(0);
    return 0;
}
