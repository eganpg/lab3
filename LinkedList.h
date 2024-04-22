#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <vector>

// Declare the LinkedList class
class LinkedList {
private:
    // Pointer to the first node in the linked list
    Node* headPtr;
    // Number of nodes/items in the linked list
    int numItems;

public:
    // Constructor: Initializes an empty linked list
    LinkedList();
    // Destructor: Cleans up all nodes in the linked list to prevent memory leaks
    ~LinkedList();
    // Copy constructor: Creates a deep copy of another linked list
    LinkedList(const LinkedList& other);

    // Member function to add a node with a category and line into the linked list in sorted order
    void add(const std::string& category, const std::string& line);
    // Converts the contents of the linked list into a vector of strings for easy display or processing
    std::vector<std::string> toVector() const;
    // Returns the number of items in the linked list
    int getNumItems() const;
};

// Include cpp file with implementation
#include "LinkedList.cpp"

#endif // LINKEDLIST_H
