//This program calculates and prints the minimum spanning tree of
//a graph given from the input file ("Sample Test Data.txt") using
//the prim's algorithm. It also prints the given graph in two ways:
//the first is like shown in the txt file and the second is a 2D
//matrix representation. Enjoy!

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

inline double prob() {return (static_cast<double>(rand())/RAND_MAX);}

class Graph {

private:
    bool** adjMatrix; //graph matrix
    int** cost; //cost matrix
    float density; //graph density

public:
    int size;
    Graph(int size) //constructor
    {
        adjMatrix = new bool*[size];
        cost = new int*[size];
        for (int i = 0; i < size; ++i) //create the 2D matrices
        {
            adjMatrix[i] = new bool[size];
            cost[i] = new int[size];
            for (int j=0; j<size; ++j)
            {
                adjMatrix[i][j] = false;
                cost[i][j] = 0;
            }
        }
    }

    void createGraph(float density)
    {
        this->density = density; //graph density

        srand(time(0));

        for (int i=0; i<size; ++i) //generate undirected edges
        {
            for (int j=i; j<size; ++j)
            {
                if (i==j)
                    adjMatrix[i][j] = false;
                else
                    adjMatrix[i][j] = adjMatrix[j][i] = (prob()<density);
            }
        }

        for (int i=0; i<size; ++i) //generate costs and color
        {
            for (int j=i; j<size; ++j)
            {
                if (adjMatrix[i][j])
                    cost[i][j] = cost[j][i] = prob()*30; //would be int from 0 to 29 (probably not 30)
            }
        }
    }

    int** inputGraphFromFile(const char filename[])
    {
        ifstream infile(filename);

        infile >> size; //first value of the file is the size
        int a, b, c;
        while (infile >> a >> b >> c) //second and third values are the vartices and third is the cost
        {
            adjMatrix[a][b] = adjMatrix[b][a] = true;
            cost[a][b] = cost[b][a] = c;
        }

        return cost;
    }

    void displayConnectedVertices()
    {
        cout << " Adjacency Matrix of size " << size << endl;

        cout << "Edges\t\tCost" << "\n";
        for (int i=0; i<size; ++i)
        {
            for (int j=0; j<size; ++j)
            {
                if (adjMatrix[i][j])
                    cout << i << "\t" << j << "\t" << cost[i][j] << "\n";
            }
        }
    }

    void displayMatrix()
    {
        cout << " Adjacency Matrix:";

        // displaying the 2D array
        for (int i = 0; i < size; ++i) {
            cout << endl;
            for (int j = 0; j < size; ++j)
                cout << cost[i][j] << " " ;
        } cout << endl;
    }

    ~Graph() //destructor
    {
        for (int i = 0; i < size; i++)
        {
            delete[] adjMatrix[i];
            delete[] cost[i];
        }
        delete[] adjMatrix;
        delete[] cost;
        cout << endl << "Destructor called" << endl;
    }
};

//Function that finds the vertex with minimum cost,
//from the set of vertices not yet included in minimum spanning tree
int minCost(int costs[], bool openSet[], int size)
{
    // Initialize min cost
    int min = INT_MAX, min_index;

    for (int v = 0; v < size; v++)
        if (openSet[v] == false && costs[v] < min)
            min = costs[v], min_index = v;

    return min_index;
}

//Function that prints the constructed minimum spanning tree
void printMinimumSpanningTree(int parent[], int** graph, int size)
{
    cout<<"\n\nParent-Edge \tCost\n";
    for (int i = 1; i < size; i++)
        cout<<parent[i]<<" - "<<i<<" \t\t"<<graph[i][parent[i]]<<" \n";
}

//Function that constructs and prints the Minimum Spanning Tree for
//a graph represented using adjacency matrix representation
void primMST(int** graph, int size)
{
    //Array to store constructed minimum spanning tree
    int parent[size];

    //values used to pick minimum cost
    int costs[size];

    //Represent set of vertices included in MST
    bool openSet[size];

    //Initialize all keys as INFINITE
    for (int i = 0; i < size; i++)
        costs[i] = INT_MAX, openSet[i] = false;

    //Make cost 0 so that this vertex is picked as first vertex.
    costs[0] = 0;
    parent[0] = -1;

    //The minimum spanning tree will have size vertices
    for (int count = 0; count < size - 1; count++)
    {
        //Pick the minimum cost vertex from the set of vertices
        //not yet included in the openSet
        int u = minCost(costs, openSet, size);

        //Add the picked vertex to the openSet
        openSet[u] = true;

        //Update cost and parent index of the adjacent vertices not yet included in the openSet
        for (int v = 0; v < size; v++)

            //Update the cost only for adjacent vertices, not yet inlcuded in the
            //open set and if graph[u][v] is smaller than costs[v]
            if (graph[u][v] && openSet[v] == false && graph[u][v] < costs[v])
                parent[v] = u, costs[v] = graph[u][v];
    }

    //print the constructed minimum spanning tree
    printMinimumSpanningTree(parent, graph, size);
}

int main()
{
    int size = 20;
    Graph graph1(size); //create object of class Graph
    int** graph1_Matrix_Representation; //declare the matrix representation

    //create the graph from the input file and return the adjacency matrix representation
    graph1_Matrix_Representation = graph1.inputGraphFromFile("Sample Test Data.txt");

    graph1.displayConnectedVertices(); //display the edges as in the txt file
    graph1.displayMatrix(); //display the 2D matrix

    primMST(graph1_Matrix_Representation, size); //create and print the prim's minimum spanning tree

    return 0;
}
