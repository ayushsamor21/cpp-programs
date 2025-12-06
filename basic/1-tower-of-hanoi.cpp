#include <iostream>
using namespace std;

void towerOfHanoi(int n, char start, char destination, char auxiliary) {
    // Base case
    if (n == 1) {
        cout << "Move disk 1 from " << start << " to " << destination << endl;
        return;
    }

    // Move n-1 disks from start → auxiliary
    towerOfHanoi(n - 1, start, auxiliary, destination);

    // Move nth disk from start → destination
    cout << "Move disk " << n << " from " << start << " to " << destination << endl;

    // Move n-1 disks from auxiliary → destination
    towerOfHanoi(n - 1, auxiliary, destination, start);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    // Fixed names as you wanted
    char start = 'A';
    char destination = 'C';
    char auxiliary = 'B';

    towerOfHanoi(n, start, destination, auxiliary);

    return 0;
}
