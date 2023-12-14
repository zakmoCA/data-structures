#include <iostream>
#include <vector>

class HashTable {
private:
    std::vector<int> table; // Using a vector to represent the hash table

public:
    HashTable(int size) : table(size, -1) {} // Constructor initializes the table with a fixed size and default values (-1)

    // Simple hash function
    int hashFunction(int key) {
        return key % table.size(); // Using modulo for simplicity
    }

    // Insert key-value pair (assuming key and value are the same for simplicity)
    void insert(int key) {
        int index = hashFunction(key); // Get the index from the hash function
        table[index] = key; // Insert the key at the calculated index
    }

    // Retrieve a value by key
    bool get(int key, int& value) {
        int index = hashFunction(key); // Get the index from the hash function
        if (table[index] == key) { // Check if the key exists
            value = table[index];
            return true;
        }
        return false; // Return false if key not found
    }
};

int main() {
    HashTable hashTable(10);
    hashTable.insert(12);
    hashTable.insert(22);

    int value;
    if (hashTable.get(12, value)) {
        std::cout << "Value found: " << value << std::endl;
    } else {
        std::cout << "Value not found" << std::endl;
    }

    return 0;
}
