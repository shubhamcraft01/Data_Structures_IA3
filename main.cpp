#include <iostream>
#include <string>
using namespace std;
 
// Node of the linked list
struct Node {
    int key;
    string name;
    Node* next;
 
    Node(int k, string n) {
        key = k;
        name = n;
        next = NULL;
    }
};
 
class HashTable {
    Node* bucket[23];
    int count;
 
public:
    HashTable() {
        count = 0;
        for (int i = 0; i < 23; i++) {
            bucket[i] = NULL;
        }
    }
 
    // Mid-square: square, pad to four digits, take middle two digits
    int hashFunction(int key) {
        int square = key * key;
        string s = to_string(square);
 
        while (s.length() < 4) {
            s = "0" + s;
        }
 
        int middle = (s[1] - '0') * 10 + (s[2] - '0');
        return middle % 23;
    }
 
    // Insert a new key, or update its name if the key already exists
    void insert(int key, string name) {
        int index = hashFunction(key);
        Node* temp = bucket[index];
        int position = 1;
 
        while (temp != NULL) {
            if (temp->key == key) {
                cout << "Duplicate key " << key
                     << " found in bucket " << index
                     << " (position " << position << ")"
                     << " -> name changed from "
                     << temp->name << " to " << name << endl;
                temp->name = name;
                return;
            }
 
            temp = temp->next;
            position++;
        }
 
        Node* newNode = new Node(key, name);
 
        if (bucket[index] == NULL) {
            bucket[index] = newNode;
        }
        else {
            temp = bucket[index];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
 
        count++;
        cout << "Inserted key " << key << " (" << name
             << ") -> bucket " << index << endl;
    }
 
    // Search for a key in its calculated bucket
    Node* search(int key) {
        int index = hashFunction(key);
        Node* temp = bucket[index];
 
        while (temp != NULL) {
            if (temp->key == key) {
                return temp;
            }
            temp = temp->next;
        }
 
        return NULL;
    }
 
    int size() {
        return count;
    }
};
 
int main() {
    const int S = 175;
    string names[20] = {
        "Cola", "Orange Fizz", "Lemon Lime", "Root Beer",
        "Ginger Ale", "Mango Cooler", "Cream Soda",
        "Grape Blast", "Cherry Pop", "Pineapple Punch",
        "Lime Mint", "Strawberry", "Blue Raspberry",
        "Peach Iced Tea", "Watermelon", "Apple Fizz",
        "Guava", "Litchi", "Tonic", "Jeera Masala"
    };
 
    HashTable ht;
 
    for (int i = 0; i < 20; i++) {
        int key = (S + 13 * i) % 100;
        ht.insert(key, names[i]);
    }
 
    cout << "\nSearch tests\n";
    int tests[3] = {53, 96, 42};
 
    for (int i = 0; i < 3; i++) {
        Node* result = ht.search(tests[i]);
 
        if (result != NULL) {
            cout << "key " << tests[i] << " found: "
                 << result->name << endl;
        }
        else {
            cout << "key " << tests[i] << " NOT found" << endl;
        }
    }
 
    cout << "\nDuplicate key test\n";
    ht.insert(53, "Cream Soda Zero");
 
    cout << "Entries after duplicate insert = " << ht.size()
         << " (still 20, no new node was created)" << endl;
 
    return 0;
}
