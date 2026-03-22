#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int> >& graph, int vertices) {
    vector<bool> visited(vertices, false);
    queue<int> q;
    
    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 0; i < graph[node].size(); i++) {
            int neighbor = graph[node][i];

            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

}

int main() {
    int vertices = 5;
    vector<vector<int> > graph(vertices);

    // Undirected graph
    graph[0].push_back(1);
    graph[0].push_back(4);

    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);

    graph[2].push_back(1);
    graph[2].push_back(3);

    graph[3].push_back(1);
    graph[3].push_back(2);
    graph[3].push_back(4);

    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[4].push_back(3);

    bfs(0, graph, vertices);

    return 0;
}