#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

const int nodes=10;

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

    void addEdgesRandomly(float density, float distanceMin, float distanceMax)
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
            distance = distanceMin + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(distanceMax-distanceMin))); //random float number from distanceMin to distanceMax
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
    }

    void displayAdjacencyMatrix()
    {
        cout << " Adjacency Matrix:";

        // displaying the 2D array
        for (int i = 0; i < nodes; ++i) {
            cout << endl;
            for (int j = 0; j < nodes; ++j)
                cout << " " << std::fixed << std::setprecision(1) << adjMatrix[i][j];
        } cout << endl;
    }

    ~Graph() //destructor
    {
        for (int i = 0; i < nodes; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
        cout << endl << "Destructor called" << endl;
    }
};

int main()
{
    // creating objects of class Graph
    Graph graph1(nodes);
    graph1.addEdgesRandomly(0.4, 1.0, 10.0);
    graph1.displayAdjacencyMatrix();

    return 0;
}
