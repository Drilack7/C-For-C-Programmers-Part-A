#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

inline double prob() {return (static_cast<double>(rand())/RAND_MAX);}

int main(void)
{
    int size = 15;
    double density;

    cout << "Graph size is" << endl;
    cin >> size;
    cout << "Graph density (0,1) is" << endl;
    cin >> density;

    bool** graph;
    int** color;
    int** cost;

    srand(time(0));

    graph = new bool*[size];
    color = new int*[size];
    cost = new int*[size];

    for (int i=0; i<size; ++i)
    {
        graph[i] = new bool[size];
        color[i] = new int[size];
        cost[i] = new int[size];
    }

    for (int i=0; i<size; ++i) //generate undirected edges
    {
        for (int j=i; j<size; ++j)
        {
            if (i==j)
                graph[i][j] = false;
            else
                graph[i][j] = graph[j][i] = (prob()<density);
        }
    }

    for (int i=0; i<size; ++i) //generate costs and color
    {
        for (int j=i; j<size; ++j)
        {
            if (graph[i][j])
            {
                color[i][j] = color[j][i] = rand()%3; //would be 0,1 or 2
                cost[i][j] = cost[j][i] = prob()*30; //would be int from 0 to 29 (probably not 30)
            }
        }
    }

    ofstream outp("graph_data.txt");
    outp << size << "\n";
    outp << "Edges\t\tCost\tColor" << "\n";
    for (int i=0; i<size; ++i)
    {
        for (int j=0; j<size; ++j)
        {
            if (graph[i][j])
                outp << i << "\t" << j << "\t" << cost[i][j] << "\t" << color[i][j] << "\n";
        }
    }

    for (int i = 0; i < size; ++i)
    {
        delete[] graph[i];
        delete[] color[i];
        delete[] cost[i];
    }
    delete[] graph;
    delete[] color;
    delete[] cost;
}
