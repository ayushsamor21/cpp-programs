#include <iostream>
using namespace std;

int countElements(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] <= key) {
            result = mid;        
            low = mid + 1;       
        } else {
            high = mid - 1;      
        }
    }

    return result + 1;
}


int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int key = 30;
    int n = sizeof(arr) / sizeof(arr[0]);

    
    int count = countElements(arr, n, key);
    printf("%d", count);
    return 0;
}
