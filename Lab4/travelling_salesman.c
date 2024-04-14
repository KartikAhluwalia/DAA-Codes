#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices

int graph[V][V] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int min(int x, int y) {
    return (x < y) ? x : y;
}

// Function to find the minimum distance path using brute force
int tsp(int cities[], int visited[], int n, int current, int count) {
    if (count == n && graph[current][0]) // If all cities are visited and a path exists back to the starting city
        return graph[current][0];

    int min_dist = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[current][i]) { // If the city is not visited and there is a path to it
            visited[i] = 1; // Mark the city as visited
            int dist = graph[current][i] + tsp(cities, visited, n, i, count + 1); // Calculate the distance for the current path
            min_dist = min(min_dist, dist); // Update the minimum distance
            visited[i] = 0; // Backtrack
        }
    }

    return min_dist;
}

int main() {
    int cities[V]; // Array to store the permutation of cities
    int visited[V] = {0}; // Array to track visited cities

    for (int i = 0; i < V; i++)
        cities[i] = i;

    visited[0] = 1; // Start from city 0

    int min_distance = tsp(cities, visited, V, 0, 1); // Start from city 0

    printf("Minimum distance: %d\n", min_distance);

    return 0;
}
