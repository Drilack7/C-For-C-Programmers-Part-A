#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
using namespace std;

int main(void)
{
    int size;
    int** cost;

    ifstream data_file("Sample Test Data.txt");
    istream_iterator<int> start(data_file), end;
    vector<int> data(start, end);

    size = 20;

    cost = new int*[size];
    for (int i = 0; i < size; ++i) //create the 2D matrices
    {
        cost[i] = new int[size];
        for (int j=0; j<size; ++j)
            cost[i][j] = 0;
    }

    for (auto it = data.begin(); (it+2) != data.end(); ++it)
    {
        cost[*it][*(it+1)] = *(it+2);
    }

    /* for (it=data.begin(); it != data.end(); ++it)
    {
        cost[0][0] = *it;
    } */

    cout << " Adjacency Matrix:";

    // displaying the 2D array
    for (int i = 0; i < size; ++i) {
        cout << endl;
        for (int j = 0; j < size; ++j)
            cout << cost[i][j] << "\t" ;
    } cout << endl;

    return 0;
}
