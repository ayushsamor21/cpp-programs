#include <iostream>
#include <vector>
using namespace std;

// Time complexity:  O(n)

int main() {
    int sizeOfArray, largest = 0;
    cout << "Please enter the size of array: ";
    cin >> sizeOfArray;

    if (sizeOfArray <= 0){
        cout << "Invalid array size!!\n";
        return 1;
    }

    vector<int> array(sizeOfArray, 0);

    for(int i = 0; i < sizeOfArray; i++) {
        cout << "Element at index["<< i <<"]: ";
        cin >> array[i];
    }


    for(int i = 0; i < sizeOfArray; i++) {
        if (array[i] > largest) {
            largest = array[i];
        }
    }
    cout << "The largest element is : "<< largest << endl;
    return 0;
}