#include <iostream>
#include <climits>

#define V 5

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Initialize the dist matrix with the given graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Update the dist matrix by considering all intermediate vertices
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            std::cout << "Shortest path from " << i << " to " << j << " is " << dist[i][j] << std::endl;
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 4, INT_MAX, 10, INT_MAX},
        {INT_MAX, 0, 3, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 0, 1, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 0, 2},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}
    };

    floydWarshall(graph);

    return 0;
}
