// #include <iostream>
// #include <string>
// #include "hash.h"

// using namespace std;

// int hash_function(string text) {
//     // Implement your own hash function here
//     return 1;
// }

#include <string>
#include <iostream>
#include <cmath>
#include "hash.h"

/* == Stack Declarations == */
void Stack::push(std::string data) {
    // INSERT TO HEAD // LIFO
    // create newnode -> set newnode next to prev. head -> set head to newnode
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;

    // increment stack size by 1
    size++;
}

std::string Stack::pop() {
    if (head != NULL) {
        // obtain value
        std::string data = head->data;
        // create copy of node, delete the prev. head
        // free memory, prevent mem leak
        Node* temp = head->next;
        delete head;
        head = temp;

        // decrement stack size by 1
        size--;

        return data;
    }
    // case fails (head is NULL)
    return "";
}

void Stack::dispStack() {
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->getData() << " ";
        temp = temp->next;
    }
}

// HASH TABLE:
int HashTable::hash(std::string input) {
    // CONVERT TO ASCII - take string(int) MOD slots
    int total = 0;
    for (int i = 0; i < input.length(); i++) {
        char letter = input[i]; 
        total = total + letter;
    }

    // FOR DEBUGGING REMOVE LATER:
    // std::cout << "total : " << total << std::endl;

    return total % slots;
}

void HashTable::insertKey(std::string input) {
    // call hash on a given input & store its index
    int index = hash(input);

    // check if stack is declared at index
    if (stackArray[index] == NULL) {
        stackArray[index] = new Stack();
    }
    // push it onto the stack at given index.
    stackArray[index]->push(input);
}

void HashTable::formHashTable(std::string* text, int size) {
    for (int i = 0; i < size; i++)
    {
        std::string input = text[i];
        insertKey(input);
    }
    
    dispHashTable();
}

void HashTable::dispHashTable() {
    // 3a) display contents:
    std::cout << "==== Printing the contents of the first 5 slots ====" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Slot " << i << ": ";
        // IF NULL DO NOT PRINT CONTENTS:
        if (stackArray[i] != NULL) {
            stackArray[i]->dispStack();
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "==== Printing the slot lengths ====" << std::endl;

    // 3b) Print Lengths:
    int sum = 0;
    for (int i = 0; i < slots; i++) {
        std::cout << "Slot " << i << ": ";
        if (stackArray[i] == NULL) {
            std::cout << "0";
        }
        else
        {
            sum = sum + stackArray[i]->getSize();   
            std::cout << stackArray[i]->getSize();
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // 3c) standard deviation
    double sum2 = 0;
    double mean = (double) sum / slots; 
    for (int i = 0; i < slots; i++) {
        int xi;
        if (stackArray[i] == NULL) {
            xi = 0;
        }
        else {
            xi = stackArray[i]->getSize();
        }
        double diff = xi - mean;
        sum2 += pow(diff, 2); 
    }

    double std = sqrt((sum2/slots)); 
    
    std::cout << "==== Printing the standard deviation ====" << std::endl;
    std::cout << std << std::endl;
}