#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <vector>
using namespace std;

inline double prob() {return (static_cast<double>(rand())/RAND_MAX);}

int size = 20;

class Graph {

private:
    bool** adjMatrix; //graph matrix
    int** cost; //cost matrix
    float density; //graph density

public:
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

        infile >> size;
        int a, b, c;
        while (infile >> a >> b >> c)
        {
            adjMatrix[a][b] = adjMatrix[b][a] = true;
            cost[a][b] = cost[b][a] = c;
        }

        return cost;
    }

    void displayGraph()
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

    void displayGraph2()
    {
        cout << " Adjacency Matrix:";

        // displaying the 2D array
        for (int i = 0; i < size; ++i) {
            cout << endl;
            for (int j = 0; j < size; ++j)
                cout << cost[i][j] << "\t" ;
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

int main()
{
    // creating objects of class Graph
    Graph graph1(20);
    int** graph2;

    graph2 = graph1.inputGraphFromFile("Sample Test Data.txt");
    graph1.displayGraph();
    graph1.displayGraph2();

    return 0;
}
