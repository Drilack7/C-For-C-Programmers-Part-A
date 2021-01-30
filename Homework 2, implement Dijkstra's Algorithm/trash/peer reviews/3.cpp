#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <ctime>

using namespace std;

inline int INFINITY() { return 1000; };

template <class val>
// implement graph via adjacent matrix
class Graph
{
   public :
      Graph() {}
      Graph(val totalVertexNum, int range, float density);
      val vertex () const { return totalVertexNum; } // returns the number of vertices in the graph
      val edges () { return edgeNum; }// returns the number of edges in the graph
      bool adjacent (const val x, const val y) { return (adjMatrix[x][y] > 0); } // tests whether there is an edge from node x to node y.
      vector<val> neighbors (const val x) const; // lists all nodes y such that there is an edge from x to y.
      bool add_edge (const val x, const val y, val cost); // adds to G the edge from x to y, if it is not there.
      bool delete_edge (const val x, const val y); // removes the edge from x to y, if it is there.
      //val get_node_value (val x); // returns the value associated with the node x.
      //void set_node_value( val x, val a); // sets the value associated with the node x to a.
      val get_edge_value( const val x, const val y) const { return adjMatrix[x][y]; } // returns the value associated to the edge (x,y).
      void set_edge_value (const val x, const val y, val cost); // sets the value associated to the edge (x,y) to v.
      vector<val> get_vertices(); // gets all the vertices in the graph
      void printGraph();
   private :
      val totalVertexNum;
      val edgeNum;
      vector<vector<val> > adjMatrix;
};

/* Graph Constructor */
template <class val> Graph<val>::Graph(val totalVertexNum, int range, float density)
{
   if (totalVertexNum <= 0)
   {
      this->totalVertexNum = 0;
      return;
   }

   this->totalVertexNum = totalVertexNum;
   adjMatrix = vector<vector<val> >(totalVertexNum, vector<val>(totalVertexNum));
   this->edgeNum = 0;

   srand(time(0));
   // Adjacency Matrix
   /*    0 1 2 ...... v
       ------------------
     0 | 0 x x ...... x |
     1 | x 0 x ...... x |
     2 | x x 0 ...... x |
     . | x x x ...... x |
     . | x x x ...... x |
     v | x x x ...... 0 |
       ------------------
   */
   for (int i=0; i<totalVertexNum; i++) /* Loop from 0 to v-1 */
   {
      for (int j=i; j<totalVertexNum; j++) /* Loop from 0 to v-1 */
      {
         if (i == j)
            continue;

         float prob = rand() % 100 / 100.0;

         if (prob < density)
         {
            int cost = (rand() % (range+1));
            add_edge(i, j, cost);
            if (cost)
               ++edgeNum;
         }
      }
   }
}

template <class val> vector<val> Graph<val>::neighbors( const val x) const
{
   vector<int> list;
   for (int i=0; i<totalVertexNum; i++)
   {
      if (adjMatrix[x][i] > 0)
         list.push_back(i);
   }

   return list;
}

template <class val> vector<val> Graph<val>::get_vertices()
{
   vector<int> vertices;

   for (int i=0; i<totalVertexNum; i++)
      vertices.push_back(i);

   return vertices;
}

template <class val> bool Graph<val>::add_edge(const val x, const val y, val cost)
{
   if (adjMatrix[x][y] > 0)
      return false;

   adjMatrix[x][y] = cost;
   adjMatrix[y][x] = cost;

   return true;
}

template <class val> bool Graph<val>::delete_edge(const val x, const val y)
{
   if (adjMatrix[x][y] > 0)
   {
      adjMatrix[x][y] = 0;
      adjMatrix[y][x] = 0;
      return true;
   }

   return false;
}

template <class val> void Graph<val>::printGraph()
{
   // print out the generated cost matrix
   cout << "The randomly generated adjacency matrix is" << endl << endl;
   for (int i = 0; i < totalVertexNum; i++) {
      for (int j = 0; j < totalVertexNum; j++) {
         cout << adjMatrix[i][j] << " ";
      }
      cout << endl;
   }
}

template <class val> void Graph<val>::set_edge_value(const val x, const val y, val cost)
{
   adjMatrix[x][y] = cost;
   adjMatrix[y][x] = cost;
}

struct Node
{
   int value;
   int cost;
   int prevNode;

   Node(int value=0, int cost=INFINITY(), int prevNode=0) : value(value), cost(cost), prevNode(prevNode) {}
};

template <class val>
// an indexed priority queue implemented via minHeap
class PriorityQueue
{
   public :
      PriorityQueue() {}
      ~PriorityQueue() {}
      void chgPriority(const Node &node); // changes the priority (node value) of queue element.
      void minPriority(); // removes the top element of the queue.
      bool contains(const Node &node); // does the queue contain queue_element.
      void minHeapfy(val child); // minHeapfy the Heap
      bool insert(const Node &node); // insert queue_element into queue
      Node& top(); // returns the top element of the queue.
      val size() { return minHeap.size(); } // return the number of queue_elements.
   private :
      // swap corresponding nodes and indices
      inline void swap(val i, val j);
      vector< Node > minHeap;
};

template <class val> Node& PriorityQueue<val>::top()
{
   cout << "Value of top element : " << minHeap[0].value << endl;
   return minHeap[0];
}

template <class val> void PriorityQueue<val>::minPriority()
{
   if ( minHeap.size() != 0)
      minHeap.erase( minHeap.begin() + 0);
}

template <class val> void PriorityQueue<val>::chgPriority(const Node &node)
{
   minHeap[node.value].cost = node.cost;
   minHeapfy(node.value);
}

template <class val> bool PriorityQueue<val>::contains(const Node &node)
{
   if ( minHeap.size() == 0)
      return false;

   for( int i=0; i< minHeap.size(); i++)
   {
      if (minHeap[i].value == node.value)
         return true;
   }

   return false;
}

template <class val> bool PriorityQueue<val>::insert(const Node &node)
{
   if ((node.value < 0) || contains(node))
         return false;

   cout << "Added Node Value : " << node.value << endl;
   minHeap.push_back(node);
   minHeapfy(minHeap.size()-1);
   return true;
}

template <class val> void PriorityQueue<val>::swap(val i, val j)
{
   int val1 = minHeap[i].value;

   // swap nodes
   minHeap[i].value = minHeap[j].value;
   minHeap[j].value = val1;
   int temp = minHeap[i].cost;
   minHeap[i].cost = minHeap[j].cost;
   minHeap[j].cost = temp;
}

template <class val> void PriorityQueue<val>::minHeapfy(val child)
{
   if (child <= 0)
      return;

   int parent = (child - 1) / 2;

   if (minHeap[parent].cost > minHeap[child].cost)
   {
      swap(parent, child);
      minHeapfy(parent);
   }
}

/* Shortest Path Algo */
template <class val>
class ShortestPath
{
   public:
      void vertices(list<val> List); // list of vertices in G(V,E).
      vector<val> path(const Graph<val>& G, val u, val w);  // find shortest path between u-w and returns the sequence of vertices representing shorest path u-v1-v2-...-vn-w.
      val path_size(const Graph<val>& G, val u, val w);  // return the path cost associated with the shortest path.
   private:
      val dijkstra(const Graph<val>& G, val u, val w);
};

template <class val> val ShortestPath<val>::path_size(const Graph<val>& G, val u, val w)
{
   return dijkstra(G, u, w);
}

template <class val> val ShortestPath<val>::dijkstra(const Graph<val>& G, val u, val w)
{
   val size = G.vertex(); /* Get the number of vertex */

   int pathDist = 0;
   PriorityQueue<val> pq;
   cout << "Start Node Value : " << u << endl;
   pq.insert(Node(u, 0));

   cout << "First Node Added " << u << " size of PQ is : " << pq.size() << endl;
   while (pq.size() > 0)
   {
      Node top = pq.top();
      pq.minPriority();

      if (top.cost == INFINITY())
         return INFINITY();

      if (top.value == w) // Return when destination node reached
         return top.cost;

      // find neighbours
      vector<val> neighbors = G.neighbors(top.value);
      cout << "Total Neighbour's for Top Node : " << top.value << " is : " <<  neighbors.size() << endl;
      Node node;
      for (int i=0; i<neighbors.size(); i++)
      {
         node.value = neighbors[i];
         if (node.value == u || (node.value == top.prevNode) )
            continue;
         node.cost = G.get_edge_value(top.value, node.value);
         cout << "Neighbour Node Value : " << node.value << " and Cost : " << node.cost << endl;
         if (pq.contains(node)) // Update cost if Node already present
         {
            val edge = G.get_edge_value(top.value, node.value);
            if (node.cost > edge + top.cost)
            {
               node.prevNode = top.value;
               node.cost = edge + top.cost;
               cout << "Shorter Path Cost updated for Neighbour " << node.value << " to " << node.cost << endl;
               pq.chgPriority(node);
            }
         }
         else // Insert new Node in PQ if node not present
         {
            node.prevNode = top.value;
            node.cost += top.cost;
            pq.insert( node );
         }
      }
   }

   return INFINITY();
}

int main()
{
   int numVertex = 0;
   cout << "Enter expected Max number of Vertex  ( till 20 ): ";
   cin >> numVertex;

   /* Initializing and creating matrix */
   float density = 0.4; /* It should be less than 1 */
   int range = 10;
   srand(time(0)); //rand seed
   int vertexNum = rand() % numVertex; /* Selecting vertices from 0 to 50 */
   cout << "Number of vertices generated : " << vertexNum << endl << endl;
   Graph<int> G(vertexNum, range, density);
   G.printGraph();

   if (!vertexNum)
   {
      cout << "Not enough number of vertices generated" << endl;
      return 0;
   }

   ShortestPath<int> sp;
   int startNode = 0;
   int endNode = rand() % (vertexNum-1);
   cout << "Start Node " << startNode << " End Node " << endNode << endl;

   int pathVal = sp.path_size(G, 0, endNode);

   if ((pathVal == INFINITY()) || (pathVal == 0))
      cout << "No path possible between " << startNode << " and " << endNode << endl;
   else
      cout << "Shortest Path between " << startNode << " and " << endNode << " is " << pathVal << endl;

   return 0;

}
