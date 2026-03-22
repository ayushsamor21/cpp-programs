#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertices = 5;
    vector<vector<int> >  graph(vertices);

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

    for (int i = 0; i < vertices; i++) {
        cout << "Node " << i << ": ";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}