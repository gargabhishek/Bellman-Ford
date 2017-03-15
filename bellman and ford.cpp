// Bellman-Ford Shortest path algorithm .. 

#include<iostream>
#include <stdlib.h>                			// malloc function .. 
using namespace std; 
											// Representing Edge of graph .. 
struct Edge
{
    int source, destination, weight;
};
 											// Representing Graph .. 
struct Graph
{
    int V, E;								// Graph vertices and edges .. 
    struct Edge* edge;
};
 
										// Createing graph with V vertices and E edges .. 
struct Graph* create(int v, int e)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
         
    graph->V = v;
    graph->E = e;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );

    return graph;
}
 
void PrintGraph(int dist[], int n)
{
    printf("Vertex(i) &&&  Distance(d) from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
void BellmanPath(struct Graph* graph, int source)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
               								// Initialisation -- O(|V|) ..
    for (int i = 0; i < V; i++)
        dist[i]   = 1000000;                   // taking as infinity.. 
    dist[source] = 0;
 													// Relaxation -- O(|V-1|*|E-1|)..
    for (int i = 1; i <= V-1; i++)
    {
        for (int j = 0; j <= E-1; j++)
        {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            if (dist[u] != 1000000 && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
 													// Checking Negative Cycle .. 
    for (int i = 0; i <= E-1; i++)
    {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        if (dist[u] != 1000000 && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle");
    }
 
    PrintGraph(dist, V);
 
    return;
}
 
int main()
{
    int v ;       				// Number of vertices in graph..
    int e ;  					// Number of edges in graph..
    cout<< "No of vertices in Graph"<<endl;
    cin>> v;
    cout<< "No of edges in Graph"<<endl;
    cin>> e;
    
    struct Graph* graph = create(v, e);      // Create the Graph..
 
     for(int i=0; i<e;i++)
     {
     	cout<< i<<"th edge source"<<endl;
     	cin>> graph->edge[i].source;
     	
     	cout<< i<<"th edge destinationination"<<endl;
     	cin>> graph->edge[i].destination;
		 
		cout<< i<<"th edge weight"<<endl;
     	cin>> graph->edge[i].weight;  
	 }
   
    BellmanPath(graph, 0);
 
    return 0;
}
