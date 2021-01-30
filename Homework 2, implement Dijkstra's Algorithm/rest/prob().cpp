#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

inline float prob()
{
    float result = (float)rand()/RAND_MAX;
    return result;
}

void displayAdjacencyMatrix(int n, bool** g)
    {
        cout << "\n\n Adjacency Matrix:";

        // displaying the 2D array
        for (int i = 0; i < n; ++i) {
            cout << "\n";
            for (int j = 0; j < n; ++j)
                cout << " " << g[i][j];
        }
    }

int main()
{
    int size = 10;
    srand(time(0));
    bool** graph;
    graph = new bool*[size];
    for (int i=0; i<size; ++i)
        graph[i] = new bool[size];

    for (int i=0; i<size; ++i)
    {
        for (int j=0; j<size; ++j)
        {
            if (i==j)
                graph[i][j] = false;
            else
                graph[i][j] = graph[j][i] = (prob()<0.2);
        }
    }

    displayAdjacencyMatrix(size, graph);

    //compute the number of edges
    int counter = 0;
    for (int i=0; i<size; ++i)
    {
        for (int j=0; j<size; ++j)
        {
            if (graph[i][j] == true)
                ++counter;
        }
    }

    //compute the graph density
    float density;
    density = (float)(counter/2)/45;
    cout << "\n\nDensity is: " << density << endl;

    /* float result;
    srand(time(0));
    for (int i=0; i<10; ++i)
    {
        result = (float)rand()/RAND_MAX;
        cout << result << endl;
    } */

    return 0;
}
