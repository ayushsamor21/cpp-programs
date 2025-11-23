#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr) {
    int n = arr.size();
    int num;
    for (int i = 1; i < n; i++) {
        num = arr[i];
        for(int j = i - 1; i >= 0; j--){
            if(arr[j] > num) {
                arr[j + 1] = num;
            }else{
                break;
            }
        arr[j + 1] = num;
        }
    }
}

int main() {
    int size;
    cout << "Please enter size of array: ";
    cin >> size;

    vector<int> arr(size);

    cout <<"--Please enter the array elements--\n";
    for (int i = 0; i < size; i++) {
        cout << "Enter element at index["<<i<<"]: ";
        cin >> arr[i];
    }

    insertionSort(arr);

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}