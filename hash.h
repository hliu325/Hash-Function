// #include <iostream>
// #include <string>
// #include <cmath>
// // You are free to use additional libraries as long as it's not PROHIBITED per instruction.

// using namespace std;

// struct Node {
//     Node* next;
//     string key;
// }

#ifndef HASH_H
#define HASH_H

#include <string>

class Node {
    public:
        Node(std::string data) : data(data), next(NULL) {}
        std::string getData() {return data;}

        Node* next;
        std::string data;
};

class Stack {
    public:
        // constructors:
        Stack() : head(NULL), size(0) {}
        
        // stack operations
        void push(std::string data);
        std::string pop();

        // print operation + size
        void dispStack(); 
        int getSize() {return size;}

    private: 
        Node* head;
        int size;
};

class HashTable {
    public:
        // CONSTRUCTOR:
        HashTable(int slots) {
            this->slots = slots;
            stackArray = new Stack*[slots];
            // SET EACH SLOT TO NULL
            for (int i = 0; i < slots; i++) {
                stackArray[i] = NULL;
            }
        }

        // MAIN METHODS: 
        int hash(std::string input);
        void insertKey(std::string input);
        void formHashTable(std::string* text, int size);
        void dispHashTable();

    private: 
        Stack** stackArray;
        int slots; 
};

#endif