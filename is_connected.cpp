#include <iostream>

bool is_connected(bool* graph[], int size)
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

        if (c_size == size)
            return true; //connected
        if (old_size == c_size)
            return false; //unconnected
    }
}

int main()
{
    return 0;
}
