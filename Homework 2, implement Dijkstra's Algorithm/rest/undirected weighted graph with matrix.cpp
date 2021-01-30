// C++ program to add and remove nodes in Adjacency Matrix

#include <iostream>

using namespace std;

class Graph {
private:
    // number of nodes
    int n;

    // adjacency matrix
    int g[50][50];

public:
    // constructor
    Graph(int x)
    {
        n = x;

        // initializing each element of the adjacency matrix to zero
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                g[i][j] = 0;
    }

    void displayAdjacencyMatrix()
    {
        cout << "\n\n Adjacency Matrix:";

        // displaying the 2D array
        for (int i = 0; i < n; ++i) {
            cout << "\n";
            for (int j = 0; j < n; ++j)
                cout << " " << g[i][j];
        }
    }

    void addEdge(int x, int y, int w)
    {

        // checks if the node exists in the graph
        if ((x >= n) || (y > n))
            cout << "node does not exists!";

        // checks if the node is connecting to itself
        if (x == y)
            cout << "Same node!";

        else {
            // connecting the nodes
            g[y][x] = w;
            g[x][y] = w;
        }
    }

    void addNode()
    {
        // increasing the number of nodes
        n++;
        int i;

        // initializing the new elements to 0
        for (i = 0; i < n; ++i) {
            g[i][n - 1] = 0;
            g[n - 1][i] = 0;
        }
    }

    void removeNode(int x)
    {
        // checking if the node is present
        if (x > n) {
            cout << "\nVertex not present!";
            return;
        }
        else {
            int i;

            // removing the node
            while (x < n) {
                // shifting the rows to left side
                for (i = 0; i < n; ++i) {
                    g[i][x] = g[i][x + 1];
                }

                // shifting the columns upwards
                for (i = 0; i < n; ++i) {
                    g[x][i] = g[x + 1][i];
                }
                x++;
            }

            // decreasing the number of nodes
            n--;
        }
    }
};

int main()
{
    // creating objects of class Graph
    Graph obj(4);

    // calling methods
    obj.addEdge(0, 1, 3);
    obj.addEdge(0, 2, 5);
    obj.addEdge(1, 2, 1);
    obj.addEdge(2, 3, 4);
    // the adjacency matrix created
    obj.displayAdjacencyMatrix();

    // adding a node to the graph
    obj.addNode();
    // connecting that verex to other existing nodes
    obj.addEdge(4, 1, 8);
    obj.addEdge(4, 3, 7);
    // the adjacency matrix with a new node
    obj.displayAdjacencyMatrix();

    // removing an existing node in the graph
    obj.removeNode(1);
    // the adjacency matrix after removing a node
    obj.displayAdjacencyMatrix();

    return 0;
}
