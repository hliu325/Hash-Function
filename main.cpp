#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int main() {
    // Stack test;
    // test.push("haha");
    // test.push("test");
    // test.push("baka");
    // cout << test.getSize() << endl;
    // test.dispStack();

    cout << "this is a change" << endl;
    
    string inputs[9] = {"apple", "amazon", "Amazon", "Applebee", "banana", "barbaric", "boring", "Boeing", "elephant"};
    HashTable test(5);
    test.formHashTable(inputs, 9);

    return 0;
}