#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
using namespace std;

int main(void)
{
    int size;
    int** cost;

    ifstream infile("Sample Test Data.txt");

    infile >> size;
    cost = new int*[size];
    for (int i = 0; i < size; ++i) //create the 2D matrices
    {
        cost[i] = new int[size];
        for (int j=0; j<size; ++j)
            cost[i][j] = 0;
    }

    int a, b, c;
    while (infile >> a >> b >> c)
        cost[a][b] = cost[b][a] = c;

    /* for (it=data.begin(); it != data.end(); ++it)
    {
        cost[0][0] = *it;
    } */

    cout << " Adjacency Matrix:";

    // displaying the 2D array
    for (int i = 0; i < size; ++i) {
        cout << endl;
        for (int j = 0; j < size; ++j)
            cout << cost[i][j] << " " ;
    } cout << endl;

    return 0;
}
