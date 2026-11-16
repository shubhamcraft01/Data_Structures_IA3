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
 
    cout << "Key and calculated bucket" << endl;
    for (int i = 0; i < 20; i++) {
        int key = (S + 13 * i) % 100;
        cout << key << " -> bucket " << ht.hashFunction(key) << endl;
    }
 
    return 0;
}
