#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 4 // Number of workers and jobs

// Function to find the minimum cost assignment using Hungarian Algorithm
void findMinCost(int costMatrix[N][N]) {
    int minCost = 0;
    int assignment[N]; // To store the assigned jobs

    // Initialize all jobs as unassigned
    for (int i = 0; i < N; i++)
        assignment[i] = -1;

    // Track which jobs are assigned to workers
    bool assigned[N] = {false};

    // Iterate through each worker
    for (int worker = 0; worker < N; worker++) {
        // Find the minimum cost job that the worker can perform
        int minCostJob = INT_MAX;
        int minJobIdx = -1;

        for (int job = 0; job < N; job++) {
            if (!assigned[job] && costMatrix[worker][job] < minCostJob) {
                minCostJob = costMatrix[worker][job];
                minJobIdx = job;
            }
        }

        // Update assignment and mark job as assigned
        assignment[minJobIdx] = worker;
        assigned[minJobIdx] = true;
        minCost += minCostJob;
    }

    // Print the assignments
    printf("Worker\tJob\n");
    for (int i = 0; i < N; i++) {
        printf("%d\t%d\n", assignment[i], i);
    }
    printf("Minimum Cost: %d\n", minCost);
}

int main() {
    // Cost matrix representing the cost of each worker performing each job
    int costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    findMinCost(costMatrix);

    return 0;
}
