#include <iostream>
using namespace std;

bool is_connected(bool* graph[5][5], int size)
{
    int old_size = 0, c_size = 0;
    bool* close = new bool[size];
    bool* open = new bool[size];
    for (int i=0; i<size; ++i)
        open[i] = close[i] = false;
    open[0] = true;

    while (c_size<size)
    {
        for (int i=0; i<size; ++i)
        {
            old_size = c_size;
            if (open[i] && (close[i] == false))
            {
                close[i] = true;
                c_size++;

                for (int j=0; j<size; ++j)
                open[j] = open[j] || graph[i][j]; //graph[i][j] is true if there is an edge (i,j)
            }
        }

    }

    if (c_size == size)
        delete open; delete close;
        cout << "destructor called" << endl;
        return true; //connected
    if (old_size == c_size)
        delete open; delete close;
        cout << "destructor called" << endl;
        return false; //unconnected
}

int main()
{
    bool* matrix[5][5];
    int s=5;
    for (int i=0; i<s; ++i)
        for (int j=0; j<s; ++j)
            *matrix[i][j] = true;

    if ( is_connected(matrix, s) == true)
        cout << "The graph is connected";
    else
        cout << "The graph is unconnected";

    cout<<"\n Two Dimensional Array is : \n";
    for(int i=0; i<s; i++)
    {
        for(int j=0; j<s; j++)
        {
                cout<<" "<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
