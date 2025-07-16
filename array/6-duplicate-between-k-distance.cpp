#include <iostream>
#include <vector>
using namespace std;

int main(){
    int sizeOfArray, k_distance;
    cout << "Please enter the size of array: ";
    cin >> sizeOfArray;

    if (sizeOfArray <= 0){
        cout << "Invalid array size!!\n";
        return 1;
    }

    vector<int> arr(sizeOfArray, 0);

    for(int i = 0; i < arr.size(); i++){
        cout << "Please enter the element at index["<< i <<"]: ";
        cin >> arr[i];
    }

    cout << "The kth distance to search duplicate: ";
    cin >> k_distance;

    bool isDuplicate = false;
    for(int i = 0; i < arr.size(); i++){
        for(int j = i + 1; j <= i + k_distance; j++){
            if(arr[i] == arr[j]){
                isDuplicate = true;
                break;
            }
        }
        if(isDuplicate) break;
    }

    if (isDuplicate){
        cout << "Yes, the duplicate exist in range.\n";
    } else{
        cout << "No, the duplicate does not exist in range.\n";
    }
    return 0;
}