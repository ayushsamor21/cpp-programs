#include <iostream>
using namespace std;

int firstOccur(int arr[], int n, int key) {
    int low = 0, high = n -1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if ( arr[mid] == key ) {
            first = mid;
            high = mid - 1;
        }else if(arr[mid] < key){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return first;
}

int lastOccur(int arr[], int n, int key) {
    int low = 0, high = n -1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if ( arr[mid] == key ) {
            last = mid;
            low = mid + 1;   
        }else if(arr[mid] < key){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return last;
}

int main () {
    int arr[] = {2, 4, 6, 8, 8, 8, 11, 15};
    int key = 8;
    int n = sizeof(arr) / sizeof(arr[0]);

    int first = firstOccur(arr, n, key);
    int last = lastOccur(arr, n, key);

    cout << "First Occurrence: " << first << endl;
    cout << "Last Occurrence: " << last << endl;

    return 0;
}
