#include <iostream>
#include <ctime>
#include <iomanip>
using std::cout;
using std::endl;

int main()
{
    float adjMatrix[5][5];
    for (int i=0; i<5; ++i)
    {
        for (int j=0; j<5; ++j)
            adjMatrix[i][j]=0.0;
    }

    int maxNumberOfEdges, numberOfEdges;
    maxNumberOfEdges = (5*(5-1))/2; //In undirected graph: total number of possible edges is |v|*|v-1|/2
    numberOfEdges = maxNumberOfEdges*0.4; //density = number of edges/total number of possible edges

    int counter=0, i,j;
    float distance;
    srand(time(0));
    while (counter < numberOfEdges)
    {
        distance = 1.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/9.0)); //random float number from 1 to 10
        i = rand() % 5;
        j = rand() % 5;

        if (i==j)
            continue;

        else if (adjMatrix[i][j]==0.0 && adjMatrix[j][i]==0.0)
        {
            adjMatrix[i][j] = distance;
            adjMatrix[j][i] = distance;
            ++counter;
        }
    }

    //display
    cout << " Adjacency Matrix:";
    for (int i = 0; i < 5; ++i) {
        cout << endl;
        for (int j = 0; j < 5; ++j)
            cout << " " << std::fixed << std::setprecision(1) << adjMatrix[i][j];
    } cout << endl;
}
