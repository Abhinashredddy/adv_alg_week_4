#include <iostream>
#include <limits.h>
#include <stdio.h>

#define V 9

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    std::cout << j << " ";
}

void printSolution(int dist[], int parent[], int end)
{
    std::cout << "Vertex\t Distance\tPath";
    printPath(parent, end);
    std::cout << "\n"
              << 0 << " -> " << end << "\t\t" << dist[end] << "\t\t0 ";
}

void dijkstra(int graph[V][V], int src, int end)
{
    int dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    printSolution(dist, parent, end);
}

int main()
{
    int graph[V][V] = {{0, 3, 0, 0, 0, 0, 0, 7, 0},
                       {3, 0, 5, 0, 0, 0, 0, 2, 0},
                       {0, 5, 0, 2, 0, 1, 0, 0, 4},
                       {0, 0, 2, 0, 6, 0, 0, 0, 0},
                       {0, 0, 0, 6, 0, 4, 0, 0, 0},
                       {0, 0, 1, 0, 4, 0, 8, 0, 0},
                       {0, 0, 0, 0, 0, 8, 0, 1, 0},
                       {7, 2, 0, 0, 0, 0, 1, 0, 6},
                       {0, 0, 4, 0, 0, 0, 0, 6, 0}};

    int start, end;
    std::cout << "Enter the starting node: ";
    std::cin >> start;
    std::cout << "Enter the ending node: ";
    std::cin >> end;

    dijkstra(graph, start, end);

    return 0;
}
