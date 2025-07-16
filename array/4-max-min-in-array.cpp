#include <iostream>
#include <vector>
using namespace std;

int max(vector<int>& arr){
    int maxElement = arr[0];
    for(int i = 0; i < arr.size(); i++){
        if ( maxElement < arr[i]){
            maxElement = arr[i];
        }
    }
    return maxElement;
}

int min(vector<int> arr){
    int minElement = arr[0];
    for(int i = 0; i < arr.size(); i++){
        if (minElement > arr[i]){
            minElement = arr[i];
        }
    }
    return minElement;
}

int main(){
    int sizeOfArray;
    cout << "Please enter the size of array: ";
    cin >> sizeOfArray;

    if (sizeOfArray <= 0){
        cout << "Invalid array size!!\n";
        return 1;
    }

    vector<int> arr(sizeOfArray, 0);

    for(int i = 0; i < sizeOfArray; i++){
        cout << "Please enter the element at index["<< i <<"]: ";
        cin >> arr[i];
    }

    int maxElement = max(arr);
    cout << "The maximum element in array: " << maxElement << endl;

    int minElement = min(arr);
    cout << "The minimum element in array: " << minElement << endl;
    return 0;
}