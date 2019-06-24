#include <unordered_map>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <queue>

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

//vertex = conteúdo
//edge = arestas que ligam os conteúdos

void BFS(unordered_map<int, vector<int>> graph, map<int, int> color,
         map<int, int> predecessor, map<int, int> distance,
         int initial)
{
    //initialize graph and auxiliar variables
    for(auto vertex : graph)
    {
        cout << vertex.first << endl;
        color.insert(make_pair(vertex.first, WHITE));
        distance.insert(make_pair(vertex.first, 99999));
        predecessor.insert(make_pair(vertex.first, -1));
    }

    //marking the initial node
    color[initial] = GRAY;
    distance[initial] = 0;
    predecessor[initial] = -1;

    queue<int> q;
    q.push(initial);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto vertex : graph[u])
        {
            if(color[vertex] == WHITE)
            {
                color[vertex] = GRAY;
                distance[vertex] = distance[u] + 1;
                predecessor[vertex] = u;
                q.push(vertex);
            }
        }
        color[u] = BLACK;
    }

}

int main(int argc, char const *argv[])
{
    unordered_map<int, vector<int>> graph;
    map<int, int> color;
    map<int, int> predecessor;
    map<int, int> distance;
    int initial;

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

    initial = 1;

    BFS(graph, color, predecessor, distance, initial);

    return 0;
}