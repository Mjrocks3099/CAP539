#include <iostream>
#include <climits>

#define V 5
#define inf 99999

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Initialize the dist matrix with the given graph

    for (int i = 1; i < V; i++) {
        for (int j = 1; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Update the dist matrix by considering all intermediate vertices
    for (int k = 1; k < V; k++) {
        for (int i = 1; i < V; i++) {
            for (int j = 1; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    for (int i = 1; i < V; i++) {
        for (int j = 1; j < V; j++) {
            std::cout << "Shortest path from " << i << " to " << j << " is " << dist[i][j] << std::endl;
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 4,inf, 1, 1},
        {4, 0, 5, 2, 2},
        {inf, 5, 0, 3,inf},
        {1, 2, 3, 0, inf},
        {1, 2, inf, inf, 0},
    };


    floydWarshall(graph);

    return 0;
}
