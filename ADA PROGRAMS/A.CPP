#include <iostream>
using namespace std;

const int INF = 9999; // Infinity value

int main()
{
    int graph[5][5] = {
        {0, 4, INF, 1, 1},
        {4, 0, 5, 2, 2},
        {INF, 5, 0, 3, INF},
        {1, 2, 3, 0, INF},
        {1, 2, INF, INF, 0}
    }; // Graph matrix

    int dist[5][5]; // Distance matrix
    int i, j, k;

    // Initialize the distance matrix with the values of the graph matrix
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Iterate through all vertices as intermediate nodes
    for (k = 0; k < 5; k++) {
        // Display current iteration
        cout << "Iteration " << k + 1 << ":" << endl;

        // Iterate through all pairs of vertices
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                // If vertex k is on the shortest path between i and j
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    // Update the distance between i and j
                    dist[i][j] = dist[i][k] + dist[k][j];
                }

                // Display the current values of the distance matrix
                cout << dist[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Display the shortest path from vertex 1 to vertex 5
    cout << "Shortest path from vertex 1 to vertex 5: " << dist[0][4] << endl;

    return 0;
}
