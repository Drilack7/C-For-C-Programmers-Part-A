#include <climits>
#include <iostream>
using namespace std;

// Number of nodes in the graph
const int nodes=10;

// A utility function to find the node with minimum distance value, from
// the set of nodes not yet included in open set
int minDistance(float dist[], bool openSet[])
{
    // Initialize min value
    float min = static_cast<float>(INT_MAX);
    int min_index;

    for (int v = 0; v < nodes; ++v)
        if (openSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print shortest
// path from source to j
// using parent array
void printPath(int parent[], int j)
{

    // Base Case : If j is source
    if (parent[j] == - 1)
        return;

    printPath(parent, parent[j]);

    cout << j << "-";
}

// A utility function to print the constructed distance array
void printSolution(float dist[], int source, int parent[])
{
    cout << "Node \t\t Distance from Source \t\t Path\n";
    for (int i = 0; i < nodes; i++)
    {
        if (dist[i] == static_cast<float>(INT_MAX))
            cout << i << " \t\t - \t\t -\n";
        else
        {
            cout << i << " \t\t " << dist[i] << " \t\t\t\t " << source << "-";
            printPath(parent, i);
            cout << endl;
        }
    }
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(float graph[nodes][nodes], int src)
{
    float dist[nodes]; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool openSet[nodes]; // openSet[i] will be true if node i is included in shortest
    // path tree or shortest distance from src to i is finalized

    int parent[nodes];  // Parent array to store shortest path tree
    parent[src] = -1;

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < nodes; i++)
        dist[i] = static_cast<float>(INT_MAX), openSet[i] = false;

    // Distance of source node from itself is always 0
    dist[src] = 0.0;

    // Find shortest path for all vertices
    for (int count = 0; count < nodes - 1; count++) {
        // Pick the minimum distance node from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, openSet);

        // Mark the picked node as processed
        openSet[u] = true;

        // Update dist value of the adjacent vertices of the picked node.
        for (int v = 0; v < nodes; v++) {
            // Update dist[v] only if is not in openSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!openSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // print the constructed distance array
    printSolution(dist, src, parent);
}

// driver program to test above function
int main()
{
    /* Let us create the example graph discussed above */
    float graph[nodes][nodes] = { { 0.0, 5.7, 4.9, 0.0, 4.8, 6.8, 0.0, 0.0, 0.0, 2.2 },
                                { 5.7, 0.0, 0.0, 0.0, 0.0, 0.0, 1.1, 2.8, 0.0, 6.0 },
                                { 4.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0 },
                                { 0.0, 0.0, 0.0, 0.0, 4.9, 0.0, 0.0, 6.3, 9.3, 2.9 },
                                { 4.8, 0.0, 0.0, 4.9, 0.0, 0.0, 8.2, 0.0, 8.1, 0.0 },
                                { 6.8, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
                                { 0.0, 1.1, 0.0, 0.0, 8.2, 0.0, 0.0, 7.1, 0.0, 0.0 },
                                { 0.0, 2.8, 2.0, 6.3, 0.0, 0.0, 7.1, 0.0, 2.1, 0.0 },
                                { 0.0, 0.0, 0.0, 9.3, 8.1, 0.0, 0.0, 2.1, 0.0, 4.7 },
                                { 2.2, 6.0, 0.0, 2.9, 0.0, 0.0, 0.0, 0.0, 4.7, 0.0 } };

    dijkstra(graph, 6);

    return 0;
}
