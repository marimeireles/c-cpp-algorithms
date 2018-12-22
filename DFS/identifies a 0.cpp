#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int DFS(vector<vector<int>>& graph, int node, int *marked) {
    marked[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        printf("%d\n", graph[node][i]);
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

int main(int argc, char const *argv[]) {

    FILE* inputFile = fopen(argv[1], "r");

    int numberVertices, numberEdges;
    fscanf(inputFile, "%d %d\n", &numberVertices, &numberEdges);

    //creates and fills a graph using the inputFile data
    vector<vector<int>> graph;
    graph.resize(numberVertices);
    for (int i = 0; i < numberEdges; ++i) {
        int verticeA, verticeB;
        fscanf(inputFile, "%d %d\n", &verticeA, &verticeB);
        graph[verticeA-1].push_back(verticeB-1);
    }
    fclose(inputFile);

    //marks vertices as unvisiteds
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
    if (answer) {
        printf("0 -1\n");
        return 0;
    }
    else {

    }

    return 0;
}
