#include <iostream>
#include <vector>
using namespace std;

int main(){
    int sizeOfArray, sumOfElement = 0;
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
        sumOfElement += arr[i];
    }
    cout <<"The sum of array element: "<< sumOfElement << endl;
    return 0;
}