// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

#include <limits.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 10

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(float dist[], bool sptSet[])
{
    // Initialize min value
    float min = static_cast<float>(INT_MAX);
    int min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
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

    printf("%d-", (j+1));
}

// A utility function to print the constructed distance array
void printSolution(float dist[], int source, int parent[])
{
    printf("Vertex \t\t Distance from Source \t\t Path\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d \t\t %f \t\t %d-", (i+1), dist[i], (source+1));
        printPath(parent, i);
        printf("\n");
    }
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(float graph[V][V], int src)
{
    float dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    int parent[V];  // Parent array to store shortest path tree
    parent[src] = -1;

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = static_cast<float>(INT_MAX), sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0.0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
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
    float graph[V][V] = { { 0.0, 5.7, 4.9, 0.0, 4.8, 6.8, 0.0, 0.0, 0.0, 2.2 },
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
