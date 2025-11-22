#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from, char to, char aux) {
    // Base case
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }

    // Step 1: Move top n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, from, aux, to);

    // Step 2: Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << from << " to " << to << endl;

    // Step 3: Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
