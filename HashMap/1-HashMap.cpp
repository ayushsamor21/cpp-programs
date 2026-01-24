//Example for understanding

#include <iostream>
using namespace std;

class HashMap {
private:
    int* keys;
    int* values;
    int capacity;

public:
    HashMap(int size) {
        capacity = size;
        keys = new int[capacity];
        values = new int[capacity];

        for (int i = 0; i < capacity; i++) {
            keys[i] = -1;   // -1 means empty
        }
    }

    ~HashMap() {
        delete[] keys;
        delete[] values;
    }

    int hashFunction(int key) {
        return key % capacity;
    }

    void insert(int key, int value) {
        int index = hashFunction(key);

        while (keys[index] != -1 && keys[index] != key) {
            index = (index + 1) % capacity;
        }

        keys[index] = key;
        values[index] = value;
    }

    int get(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (keys[index] != -1) {
            if (keys[index] == key) {
                return values[index];
            }
            index = (index + 1) % capacity;

            if (index == startIndex)
                break;
        }
        return -1;
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << i << " : ";
            if (keys[i] != -1)
                cout << "(" << keys[i] << "," << values[i] << ")";
            else
                cout << "EMPTY";
            cout << endl;
        }
    }
};

int main() {
    HashMap map(10);

    map.insert(1, 100);
    map.insert(11, 200);  // collision
    map.insert(21, 300);  // collision

    cout << "Hash Map:\n";
    map.display();

    cout << "\nValue for key 21: " << map.get(21);

    return 0;
}
