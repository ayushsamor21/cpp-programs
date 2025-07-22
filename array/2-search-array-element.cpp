#include <iostream>
#include <vector>
using namespace std;

int main(){
    int sizeOfArray, searchValue;
    cout << "Please enter the size of array: ";
    cin >> sizeOfArray;

    vector<int> array(sizeOfArray, 0);

    for(int i = 0; i < sizeOfArray; i++){
        cout <<"Please enter the element at index["<< i <<"]:";
        cin >> array[i];
    }

    cout << "Please enter the element to search: ";
    cin >> searchValue;

    for(int i = 0; i < sizeOfArray; i++){
        if (array[i] == searchValue){
            cout << "The element "<< searchValue <<" is present at index["<< i <<"]\n";
            break;
        }
    }
    return 0;
}