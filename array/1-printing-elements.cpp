#include <iostream>
#include <vector>
using namespace std;

void printArrayElements(const vector<int> &array){
    cout << "---The elements of the Array---\n";
    for(int i = 0; i < array.size(); i++){
        cout << "Index["<< i <<"]: " << array[i] << endl;
    }
}

int main(){
    int sizeOfArray;
    cout << "Please enter size of array: ";
    cin >> sizeOfArray;

    vector<int> array(sizeOfArray, 0);

    for(int i = 0; i < array.size(); i++){
        cout << "Please enter value at Index["<< i <<"]: ";
        cin >> array[i];
    }

    printArrayElements(array);
    return 0;
}