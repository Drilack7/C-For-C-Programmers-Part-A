//This is my program for the Dijkstra's Algorithm Shortest
//path implementation. I used 2 classes, the Graph class
//for the random graph implementation and the ShortestPath class
//for the shortest path distances, route and average distance
//calculation. I didn't use the PriorityQueue class because the
//ShortestPath class was sufficient. For the graph representation
//I used the adjacency matrix approach. In the Graph class I used
//a pointer to pointer data type for the 2D matrix, using the new
//and delete operators for dynamic memory allocation and deallocation.
//The constructor creates a 2D matrix with zero values and the method
//"addEdgesRandomly" puts random values from a given range (from 0.0
// to 10.0) in the matrix, creating a randomly generated undirected
//weighted graph.For placing the edges I did not use the random
//probability function as suggested but I calculated the exact
//number of edges and placed them randomly in the graph.
//The "displayAdjacencyMatrix" method is not used in the main
//program but it is useful for printing the entire graph.
//For the ShortestPath calculation I used an "openSet" array for the
//nodes storage, a "dist" array for the shortest distances storage
//and a "parent" array that stores the parent connected node of each node
//during the shortest path calculation. In this class, the constructor uses
//4 methods: "minDistance" finds the node with minimum distance value, from
//the set of nodes not yet included in open set, "arrayAverage" returns the
//average value of an array, "printPath" prints the shortest path from the
//source to a certain node and "printSolution" prints the entire result,
//meaning the shortest distance from the source to each node, and the exact
//path.


#include <iostream>
#include <ctime>
#include <iomanip>
#include <climits>
using namespace std;
const int nodes=50;

class Graph {

private:
    float** adjMatrix; //graph matrix
    float density, distanceMin, distanceMax; //graph density

public:
    Graph(int nodes) //constructor
    {
        adjMatrix = new float*[nodes];
        for (int i = 0; i < nodes; i++) //initializing each element of the adjacency matrix to zero
        {
            adjMatrix[i] = new float[nodes];
            for (int j = 0; j < nodes; j++)
                adjMatrix[i][j] = 0.0;
        }
    }

    float** addEdgesRandomly(float density, float distanceMin, float distanceMax)
    {
        this->density = density; //graph density
        this->distanceMin = distanceMin;
        this->distanceMax = distanceMax;

        int maxNumberOfEdges, numberOfEdges;
        maxNumberOfEdges = (nodes*(nodes-1))/2; //In undirected graph: total number of possible edges is |v|*|v-1|/2
        numberOfEdges = maxNumberOfEdges*density; //density = number of edges/total number of possible edges

        int counter=0, i,j;
        float distance;
        srand(time(0));
        while (counter < numberOfEdges)
        {
            distance = distanceMin + static_cast <float> (rand()) / (static_cast <float>
            (RAND_MAX/(distanceMax-distanceMin))); //random float number from distanceMin to distanceMax
            i = rand() % nodes;
            j = rand() % nodes;
            if (i==j)
                continue; //avoid filling the diagonal elements
            else if (adjMatrix[i][j]==0.0 && adjMatrix[j][i]==0.0) //fill only the empty (zero) elements
            {
                adjMatrix[i][j] = distance;
                adjMatrix[j][i] = distance;
                ++counter;
            }
        }
        return adjMatrix;
    }

    void displayAdjacencyMatrix()
    {
        cout << " Adjacency Matrix:";

        // displaying the 2D array
        for (int i = 0; i < nodes; ++i) {
            cout << endl;
            for (int j = 0; j < nodes; ++j)
                cout << " " << fixed << setprecision(1) << adjMatrix[i][j];
        } cout << endl;
        cout << endl;
    }

    ~Graph() //destructor
    {
        for (int i = 0; i < nodes; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

class ShortestPath  {

public:

    // Method that implements Dijkstra's single source shortest path algorithm
    // for a graph represented using adjacency matrix representation
    ShortestPath(float** graph, int src)
    {
        float dist[nodes]; // The output array.  dist[i] will hold the shortest
        // distance from src to i
        bool openSet[nodes]; // openSet[i] will be true if node i is included in shortest
        // path tree or shortest distance from src to i is finalized
        int parent[nodes];  // Parent array to store shortest path tree
        parent[src] = -1; //Initialize the source parent node as -1

        // Initialize all distances as INFINITE and stpSet[] as false
        for (int i = 0; i < nodes; i++)
            dist[i] = static_cast<float>(INT_MAX), openSet[i] = false;

        // Distance of source node from itself is always 0
        dist[src] = 0.0;

        // Find shortest path for all vertices
        for (int count = 0; count < nodes - 1; count++) {
            // Pick the minimum distance node from the set of vertices not
            // yet processed. u is always equal to src in the first iteration.
            int u = minDistance(dist, openSet);

            // Mark the picked node as processed
            openSet[u] = true;

            // Update dist value of the adjacent vertices of the picked node.
            for (int v = 0; v < nodes; v++) {
                // Update dist[v] only if is not in openSet, there is an edge from
                // u to v, and total weight of path from src to  v through u is
                // smaller than current value of dist[v]
                if (!openSet[v] && graph[u][v] && dist[u] != INT_MAX
                    && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }

        // print the constructed distance array
        printSolution(dist, src, parent);
    }

    // A utility method to find the node with minimum distance value, from
    // the set of nodes not yet included in open set
    int minDistance(float dist[], bool openSet[])
    {
        // Initialize min value
        float min = static_cast<float>(INT_MAX);
        int min_index;

        for (int v = 0; v < nodes; ++v)
            if (openSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;

        return min_index;
    }

    float arrayAverage(float data[]) //returns the average value of an array
    {
        float sum=0.0, avg;
        int counter=0;
        for (int i=0; i<nodes; ++i)
        {
            if (data[i] == static_cast<float>(INT_MAX)) //exclude the no-path values
                continue;
            sum += data[i];
            counter++;
        }
        avg = static_cast<float>(sum/(static_cast<float>(counter-1)));
        return avg;
    }

    // Method to print shortest path from source to j
    // using parent array
    void printPath(int parent[], int j)
    {

        // Base Case : If j is source
        if (parent[j] == - 1)
            return;

        printPath(parent, parent[j]);

        cout << j+1 << "-";
    }

    // A utility method to print the constructed distance array
    void printSolution(float dist[], int source, int parent[])
    {
        cout << "Node \t\t Shortest distance from " << source+1 << "\t Path\n";
        for (int i = 0; i < nodes; i++)
        {
            if (dist[i] == static_cast<float>(INT_MAX)) //no connection with source
                cout << i+1 << " \t\t - \t\t -\n";
            else
            {
                cout << i+1 << " \t\t " << fixed << setprecision(1) << dist[i]
                << " \t\t\t\t " << source+1 << "-";
                printPath(parent, i);
                cout << endl;
            }
        }
    cout << endl << "The average path distance is " << fixed << setprecision(1)
    << arrayAverage(dist) << endl;
    }
};

int main()
{
    // creating objects of class Graph
    Graph graph1(nodes), graph2(nodes);
    float** graph1_matrix_representation;
    float** graph2_matrix_representation;

    graph1_matrix_representation = graph1.addEdgesRandomly(0.2, 1.0, 10.0);
    //graph1.displayAdjacencyMatrix(); for printing the entire matrix
    cout << "For a random graph of 50 nodes and 20% density, we have:" << endl;
    ShortestPath path1(graph1_matrix_representation, 0);

    graph2_matrix_representation = graph2.addEdgesRandomly(0.4, 1.0, 10.0);
    //graph2.displayAdjacencyMatrix(); for printing the entire matrix
    cout << "\n\nFor a random graph of 50 nodes and 40% density, we have:" << endl;
    ShortestPath path2(graph2_matrix_representation, 0);

    return 0;
}
