#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void GenRandomGraphs(int NOEdge, int NOVertex)
{
   int i, j, edge[NOEdge][2], count;
   i = 0;
   srand( (unsigned)time( NULL ) );
   //Assign random values to the number of vertex and edges
   //of the graph, Using rand().
   while(i < NOEdge)
   {
      edge[i][0] = rand()%NOVertex+1;
      edge[i][1] = rand()%NOVertex+1;
      //Print the connections of each vertex, irrespective of
      //the direction.
      if(edge[i][0] == edge[i][1])
         continue;
      else
      {
         for(j = 0; j < i; j++)
         {
            if((edge[i][0] == edge[j][0] &&
            edge[i][1] == edge[j][1]) || (edge[i][0] == edge[j][1] &&
            edge[i][1] == edge[j][0]))
            i--;
         }
      }i
      ++;
   }
   cout<<"\nThe generated random graph is: ";
   for(i = 0; i < NOVertex; i++)
   {
      count = 0;
      cout<<"\n\t"<<i+1<<"-> { ";
      for(j = 0; j < NOEdge; j++)
      {
         if(edge[j][0] == i+1)
         {
            cout<<edge[j][1]<<" ";
            count++;
         } else if(edge[j][1] == i+1)
         {
            cout<<edge[j][0]<<" ";
            count++;
         } else if(j== NOEdge-1 && count == 0)
         cout<<"Isolated Vertex!"; //Print “Isolated vertex” for the vertex having no degree.
      }
      cout<<" }";
   }
}
int main()
{
   int i, e, n;
   cout<<"Random graph generation: ";
   n= 50;
   cout<<"\nThe graph has "<<n<<" vertices";
   e = 245;
   cout<<"\nand has "<<e<<" edges.";
   GenRandomGraphs(e, n);
}
