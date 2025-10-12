#include <iostream>
#include <vector>
using namespace std;

// Function to display (traverse) the array
void traverse(const vector<int>& arr) {
    cout << "Array elements: ";
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to insert an element at a given position
void insertElement(vector<int>& arr, int value, int position) {
    arr.insert(arr.begin() + position, value);
    cout << "Inserted " << value << " at position " << position << endl;
}

// Simple linear search function
int searchElement(const vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key)
            return i;  // return index if found
    }
    return -1;  // not found
}

// Function to delete an element at a given position
void deleteElement(vector<int>& arr, int position) {
    cout << "Deleted element: " << arr[position] << endl;
    arr.erase(arr.begin() + position);
}

// Main function
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nInitial Array:\n";
    traverse(arr);

    // Insertion
    int value, position;
    cout << "\nEnter value: ";
    cin >> value; 
    cout << "\nEnter position: ";
    cin >> position; 
    
    insertElement(arr, value, position);
    traverse(arr);

    // Search
    int key;
    cout << "\nEnter element to search: ";
    cin >> key;
    int index = searchElement(arr, key);
    if (index != -1)
        cout << key << " found at position " << index << endl;
    else
        cout << key << " not found in array.\n";

    // Deletion
    cout << "\nEnter position to delete: ";
    cin >> position;
    deleteElement(arr, position);
    traverse(arr);

    return 0;
}
