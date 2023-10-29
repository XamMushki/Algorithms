/*
Algrithm AllPairsShortestPath(cost, A, n)
// Shortest path from every vertex to every other vertex.
// cost[1:n, 1:n] is the cost adjacency matrix of a graph with n vertice:
// A[i,j] is the cost of the shortest path from vertex i to vertex j.
// cost[i,i] := 0.0
{
    for i := 1 to n do{
        for j := 1 to n do{
            A[i,j] := cost[i,j];
        }
    }
    for k := 1 to n do{
        for i := 1 to n do{
            for j := 1 to n do{
                A[i,j] := min(A[i,j], A[i,k]+A[k,j]);
            }
        }
    }
}
*/
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int n = 3;  // where n is the number vertices in the given graph
    double cost[n][n] = {{0, 4, 11},
                         {6, 0, 2},
                         {3, numeric_limits<double>::max(), 0}};
    // numeric_limits<double>::max() represents infinity (or the maximum
    // value in this case, since the memory is limited)

    // Algorithm
    double A[n][n];
    // initializing matrix A[][]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = cost[i][j];
        }
    }

    // All pairs shortest path
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = min(A[i][j], (A[i][k] + A[k][j]));
            }
        }
    }

    // print result matrix
    cout << "All pairs shortest path costs: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}