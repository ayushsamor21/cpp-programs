#include <iostream>
#include <vector> 
using namespace std;

int main(){
    int sizeOfArray;
    cout << "Please enter the size of array: ";
    cin >> sizeOfArray;

    if (sizeOfArray <= 0){
        cout << "Invalid array size!!\n";
        return 1;
    }

    vector<int> array(sizeOfArray, 0);

    for(int i = 0; i < sizeOfArray; i++){
        cout << "The value at index["<< i <<"]: ";
        cin >> array[i];
    }
    
}