#include <iostream>
#include <vector>
#include <queue>

// O(V + E) 

using namespace std;

void bfs(int start, vector<int> adj[], int V) {

    vector<bool> visited(V, false);

    queue<int> q;    
    visited[start] = true;
    q.push(start);

        while(!q.empty()) {
        int node = q.front();  // Front Node
        q.pop();

        cout << node << " ";

        // for(int neighbor : adj[node]) // range-based for loop
        // {

        for(int i = 0; i < adj[node].size(); i++){
            int neighbor = adj[node][i];

            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int V = 4; // Number of Vertices 

    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    bfs(0, adj, V);

    return 0;
}