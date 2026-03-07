#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertex = 4;
    vector<int> adj[vertex]; // adjacency list

    // adding edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(3);

    // print adjacency list
    for (int i = 0; i < vertex; i++) {
        cout << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}