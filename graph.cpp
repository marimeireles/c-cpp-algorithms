#include <vector>
#include <queue>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

bool isReachable(unordered_map<int, vector<int>> graph, int search)
{
    //mark vertices as unvisiteds
    map<int, bool> marked;
    for (auto vertex : graph) {
        marked[vertex.first] = false;
    }

    // for(auto vertex : graph)
}

int main(int argc, char const *argv[])
{
    unordered_map<int, vector<int>> graph;

    graph[1].push_back(1);
    graph[1].push_back(2);
    graph[1].push_back(5);
    graph[2].push_back(1);
    graph[2].push_back(5);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[3].push_back(5);
    graph[4].push_back(5);
    graph[5].push_back(7);


    for(int i = 1; i < graph.size(); i++)
    {
        for(int j = 0; j < graph[i].size(); j++)
            cout << graph[i][j] << endl;
    }

    cout << graph[1].size();
    return 0;
}