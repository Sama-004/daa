// Time complexity: O(v^3)
#include <stdio.h>

#define V 4       // Number of vertices in the graph
#define INF 99999 // A value to represent infinity

// Function to print the solution matrix
void printSolution(int dist[][V])
{
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Function to implement Warshall's algorithm
void floydWarshall(int graph[][V])
{
    int dist[V][V], i, j, k;

    // Initialize the solution matrix same as input graph matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Add all vertices one by one to the set of intermediate vertices
    for (k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the above-picked source
            for (j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[j][k] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[j][k];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

int main()
{
    /* Example graph represented as an adjacency matrix
       The graph has 4 vertices and the following edge weights:
       (0 to 1, 3), (0 to 3, 7), (1 to 2, 1), (2 to 0, 2), (2 to 3, 5), (3 to 2, 2)
       Note: Use INF to represent no edge between nodes */
    int graph[V][V] = {{0, 3, INF, 7},
                       {8, 0, 2, INF},
                       {5, INF, 0, 1},
                       {2, INF, INF, 0}};

    // Execute Warshall's algorithm
    floydWarshall(graph);

    return 0;
}
