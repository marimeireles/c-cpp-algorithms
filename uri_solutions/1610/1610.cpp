#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int DFS(vector<vector<int>>& graph, int node, int *marked) {
    marked[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        if (marked[graph[node][i]] == 0) {
            if (DFS(graph, graph[node][i], marked)) return 1;
        }
        else if (marked[graph[node][i]] == 1) {
            marked[graph[node][i]] = 2;
            return 1;
        }
    }
    marked[node] = 2;
    return 0;
}

int main() {

    int T, numberVertices, numberEdges;
    scanf("%d\n", &T);

    for (int i = 0; i < T; ++i) {
        vector<vector<int>> graph;
        scanf("%d %d\n", &numberVertices, &numberEdges);
        graph.resize(numberVertices);
        for (int k = 0; k < numberEdges; ++k) {
            int a, b;
            scanf("%d %d\n", &a, &b);
            // printf("arestas a serem adds: %d %d\n", a, b);
            graph[a-1].push_back(b-1);
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

        //looking for cycles
        int answer = 0;
        for (int j = 0; j < numberVertices; ++j) {
            if (marked[j] != 2) {
                if (DFS(graph, j, marked) == 1) {
                    answer = 1;
                    break;
                }
            }
        }
        if (answer) printf("SIM\n");
        else printf("NAO\n");
    }

    return 0;
}
