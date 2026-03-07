#include <iostream>
using namespace std;

int main() {
    int vertex = 4;
    int matrix[4][4] = {0};

    // adding edges
    matrix[0][1] = 1;
    matrix[0][2] = 1;
    matrix[1][2] = 1;
    matrix[2][3] = 1;

    for (int i = 0; i < vertex; i++){
        for (int j = 0; j < vertex; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}