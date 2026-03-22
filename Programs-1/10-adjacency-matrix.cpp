#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertices = 5;

    vector<vector<int> > graph(vertices, vector<int>(vertices, 0));

    graph[0][1] = 1;
    graph[0][4] = 1;

    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;

    graph[2][1] = 1;
    graph[2][3] = 1;

    graph[3][1] = 1;
    graph[3][2] = 1;
    graph[3][4] = 1;

    graph[4][0] = 1;
    graph[4][1] = 1;
    graph[4][3] = 1;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}