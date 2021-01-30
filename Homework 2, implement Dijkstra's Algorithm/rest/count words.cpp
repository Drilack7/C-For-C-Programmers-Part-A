/* C++ program to count no of words
from given input string. */
#include <bits/stdc++.h>
using namespace std;

#define OUT 0
#define IN 1

// returns number of words in str
unsigned countWords(char *str)
{
    int state = OUT;
    unsigned wc = 0; // word count

    // Scan all characters one by one
    while (*str)
    {
        // If next character is a separator, set the
        // state as OUT
        if (*str == ' ' || *str == '\n' || *str == '\t' || *str == '//')
            state = OUT;

        // If next character is not a word separator and
        // state is OUT, then set the state as IN and
        // increment word count
        else if (state == OUT)
        {
            state = IN;
            ++wc;
        }

        // Move to next character
        ++str;
    }

    return wc;
}

// Driver code
int main(void)
{
    char str[] = "This is my program for the Dijkstra's Algorithm Shortest path implementation. I used 2 classes, the Graph class for the random graph implementation and the ShortestPath class for the shortest path distances, route and average distance calculation. I didn't use the PriorityQueue class because the ShortestPath class was sufficient. For the graph representaion I used the adjacency matrix approach. In the Graph class I used a pointer to pointer data type for the 2D matrix, using the new and delete operators for dynamic memory allocation and deallocation. The constructor creates a 2D matrix with zero values and the method addEdgesRandomly puts random values from a given range (from 0.0  to 10.0) in the matrix, creating a randomly generated undirected weighted graph.For placing the edges I did not use the random probability function as suggested but I calculated the exact number of edges and placed them randomly in the graph. The displayAdjacencyMatrix method is not used in the main program but it is useful for printing the entire graph. For the ShortestPath calculation I used an openSet array for the nodes storage, a dist array for the shortest distances storage and a parent array that stores the parent connected node of each node during the shortest path calculation. In this class, the constructor uses 4 methods: minDistance finds the node with minimum distance value, from the set of nodes not yet included in open set, arrayAverage returns the average value of an array, printPath prints the shortest path from the source to a certain node and printSolution prints the entire result, meaning the shortest distance from the source to each node, and the exact path. ";
    cout<<"No of words : "<< endl << countWords(str);
    return 0;
}

// This is code is contributed by rathbhupendra
