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
 
public:
    HashTable() {
        for (int i = 0; i < 23; i++) {
            bucket[i] = NULL;
        }
    }
};
 
int main() {
    HashTable ht;
    cout << "Hash table created with 23 empty buckets." << endl;
    return 0;
}
