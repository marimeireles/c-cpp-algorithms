#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int DFS(const vector<set<int>>& graph, int node, int *marked, int spaces) {
    marked[node] = 1;
    int aux = 0;
    for (int dest : graph[node]) {
        for (int j = 0; j < spaces; ++j)
            printf(" ");
        printf("%d-%d", node, dest);

        if (marked[dest] == 0) {
            printf(" pathR(G,%d)\n", dest);
            DFS(graph, dest, marked, spaces+2);
        } else {
            printf("\n");
        }
        aux++;
    }
    marked[node] = 2;
    return aux;
}

int main() {

    int N, numberVertices, numberEdges;
    scanf("%d\n", &N);

    for (int i = 0; i < N; ++i) {
        vector<set<int>> graph;
        scanf("%d %d\n", &numberVertices, &numberEdges);
        graph.resize(numberVertices);
        printf("Caso %d:\n", i+1);

        //builds graph
        for (int k = 0; k < numberEdges; ++k) {
            int a, b;
            scanf("%d %d\n", &a, &b);
            // printf("arestas a serem adds: %d %d\n", a, b);
            graph[a].insert(b);
        }

        //printing
        // for (int src = 0; src < numberVertices; ++src) {
        //     for (int dest : graph[src]) {
        //         printf("%d -> %d\n", src, dest);
        //     }
        // }

        int marked[numberVertices];
        for (int k = 0; k < numberVertices; ++k) {
            marked[k] = 0;
        }

        for (int j = 0; j < numberVertices; ++j) {
            if (!marked[j]) {
                if (DFS(graph, j, marked, 2) > 0)
                    printf("\n");
            }
        }
    }

    //     //looking for cycles
    //     int answer = 0;
    //     for (int j = 0; j < numberVertices; ++j) {
    //         if (marked[j] != 2) {
    //             if (DFS(graph, j, marked) == 1) {
    //                 answer = 1;
    //                 break;
    //             }
    //         }
    //     }
    //     if (answer) printf("SIM\n");
    //     else printf("NAO\n");
    // }

    return 0;
}
