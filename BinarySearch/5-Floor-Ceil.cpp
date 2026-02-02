#include <iostream>
using namespace std;

void findFloorCeil(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int floor = -1, ceil = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            floor = ceil = arr[mid];
            break;
        }
        else if (arr[mid] < key) {
            floor = arr[mid];   // possible floor
            low = mid + 1;
        }
        else {
            ceil = arr[mid];    // possible ceil
            high = mid - 1;
        }
    }

    cout << "Floor = " << floor << endl;
    cout << "Ceil = " << ceil << endl;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = 5;
    int key = 6;

    findFloorCeil(arr, n, key);
    return 0;
}
