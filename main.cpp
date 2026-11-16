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
 
    cout << "Personalized cold-drink dataset" << endl;
    for (int i = 0; i < 20; i++) {
        int key = (S + 13 * i) % 100;
        cout << key << " - " << names[i] << endl;
    }
 
    return 0;
}
