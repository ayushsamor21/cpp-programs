#include <iostream>
#include <vector> 
using namespace std;

int main(){
    int sizeOfArray;
    cout << "Please enter the size of array: ";
    cin >> sizeOfArray;
    vector<int> array(sizeOfArray, 0);

    for(int i = 0; i < sizeOfArray; i++){
        cout << "The value at index["<< i <<"]: ";
        cin >> array[i];
    }

    cout << "The array elements :\n";
    for(int i = 0; i < sizeOfArray; i++){
        cout << "Index["<< i <<"]: "<< array[i] << endl;
    }
    return 0;
}
